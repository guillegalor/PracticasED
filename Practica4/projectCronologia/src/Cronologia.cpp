#include "../include/Cronologia.hpp"
#include <sstream>

/*
Private
 */

// TODO Pensar para el resto del programa si acceder a una fecha como p->first o como p->second.getFecha()

void Cronologia::insertaEvento(EventoHistorico v){

  if (eventos.empty())
    eventos.insert(std::pair<Fecha,EventoHistorico>(v.getFecha(), v));
  else{
    bool insertado = false;

    for (iterator p = begin(); p != end() && !insertado; ++p){	//TODO Modificar despues de definir los iteradores de la clase
			if (p->first == v.getFecha()) {
        (p->second).addEvento(v);
        insertado = true;
      }
      else if (p->first > v.getFecha()) {
        eventos.insert(std::pair<Fecha,EventoHistorico>(v.getFecha(), v));	// TODO Realizar comparador para insertar
        insertado = true;
      }
    }
    if (!insertado)
      eventos.insert(std::pair<Fecha,EventoHistorico>(v.getFecha(), v));
  }
}

void Cronologia::insertaEvento(std::pair<Fecha, EventoHistorico> par){

  if (eventos.empty())
    eventos.insert(par);
  else{
    bool insertado = false;

    for (iterator p = begin(); p != end() && !insertado; ++p){	//TODO Modificar despues de definir los iteradores de la clase
			if (p->first == par.first) {
        (p->second).addEvento(par.second);
        insertado = true;
      }
      else if (p->first > par.first) {
        eventos.insert(par);	// TODO Realizar comparador para insertar
        insertado = true;
      }
    }
    if (!insertado)
      eventos.insert(par);
  }
}

Cronologia::iterator Cronologia::getPos(Fecha f){
  iterator p = begin();
  bool encontrado = false;

  while (p != end() && !encontrado) {
    if (p->first == f) {
      encontrado = true;
    }
    else
      ++p;
  }

  return p;
}

Cronologia::const_iterator Cronologia::getPos(Fecha f)const {
	const_iterator p = eventos.begin();
  bool encontrado = false;

  while (p != eventos.end() && !encontrado) {
    if (p->first == f) {
      encontrado = true;
    }
    else
      ++p;
  }

  return p;
}

/*
Iterators & related
 */

 Cronologia::iterator Cronologia::begin(){
 	return eventos.begin();
 }

 Cronologia::iterator Cronologia::end(){
 	return eventos.end();
 }

 Cronologia::const_iterator Cronologia::cbegin() const{
 	return eventos.cbegin();
 }

 Cronologia::const_iterator Cronologia::cend()const{
 	return eventos.cend();
 }



/*
Constructores
 */

Cronologia::Cronologia(EventoHistorico evento){
  insertaEvento(evento);
}

Cronologia::Cronologia(std::map<Fecha, EventoHistorico> m){
  setEventoHistorico(m);
}

/*
Set&Get
 */

void Cronologia::setEventoHistorico(std::map<Fecha, EventoHistorico> m){
  eventos.clear();

  for (std::map<Fecha, EventoHistorico>::iterator p = m.begin(); p != m.end() ; ++p)
    insertaEvento(*p);
}

void Cronologia::addEventoHistorico(EventoHistorico a){
  insertaEvento(a);
}

void Cronologia::addEventoHistorico(std::pair<Fecha, EventoHistorico> a){
  insertaEvento(a);
}

void Cronologia::addEventoHistorico(std::map<Fecha, EventoHistorico> m){
  for (std::map<Fecha, EventoHistorico>::iterator p = m.begin(); p != m.end() ; ++p)
    addEventoHistorico(*p);
}

Fecha Cronologia::getPrimerAnio()const{
  return cbegin()->first;
}

Fecha Cronologia::getUltimoAnio()const{
  return std::prev(cend())->first;
}

EventoHistorico Cronologia::getEventoAnio(Fecha f)const{
  if (getPos(f) != eventos.end())
    return getPos(f)->second;
  else{
    EventoHistorico no_valido;
    return no_valido;
  }
}

/*
Eliminar y busqueda
 */

bool Cronologia::eliminarEventoAnio(Fecha f){
  bool eliminado = false;

  if (getPos(f) != eventos.end()){
    eventos.erase(getPos(f));
    eliminado = true;
  }

  return eliminado;
}

std::map<Fecha, EventoHistorico> Cronologia::restringir(Fecha f, Fecha l)const{

	std::map<Fecha, EventoHistorico> copia(eventos);

	const_iterator inicio = copia.begin();
  const_iterator final = std::prev(copia.end());

  while ((inicio != copia.end()) && inicio->first < f) {
    ++inicio;
  }
  while (final != eventos.begin() && final->first > l) {
    --final;
  }

	copia.erase(copia.begin(), inicio);
	copia.erase(final, copia.end());

	return copia;

	/*
  std::vector<EventoHistorico> v;

  for (std::vector<EventoHistorico>::const_iterator p = inicio; p != final; ++p)
    v.push_back(*p);

  v.push_back(*final);

  return v;
	*/
}

Cronologia Cronologia::buscar(std::string key)const{
  Cronologia m;

  for (const_iterator p = cbegin(); p != cend(); ++p){
    if (!(p->second.buscar(key).empty())) {
			EventoHistorico evento(p->first,p->second.buscar(key));
      m.insertaEvento(evento);
    }
  }
  return m;
}


/*
E/S
 */

std::ostream& Cronologia::mostrarCronologia(std::ostream& os) const{
  for (const_iterator p = cbegin(); p != cend() ; ++p){
    os << p->second;
  }

  return os;
}

std::istream& Cronologia::leerCronologia(std::istream& is){
  eventos.clear();
  std::string str;
  EventoHistorico a;

  while (std::getline(is,str)) {
    std::stringstream ss(str);
    a.leerEvento(ss);
    insertaEvento(a);

  }

  return is;
}

std::ostream& Cronologia::prettyPrint(std::ostream& os) const{
  for (const_iterator p = cbegin(); p != cend() ; ++p){
    p->second.prettyPrint(os);
  }

  return os;
}
