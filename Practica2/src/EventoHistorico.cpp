#include "../include/EventoHistorico.hpp"


/*
Constructores
 */
EventoHistorico::EventoHistorico(){
  f.anio = -1;
  f.dc = 1;
}

EventoHistorico::EventoHistorico(int f){
  setFecha(f);
}

EventoHistorico::EventoHistorico(Fecha f){
  setFecha(f);
}

EventoHistorico::EventoHistorico(int f, std::vector<Acontecimiento> v):evento(v){
  setFecha(f);
}

EventoHistorico::EventoHistorico(Fecha f, std::vector<Acontecimiento> v):evento(v){
  setFecha(f);
}

/*
Set y get
 */

void EventoHistorico::setFecha(int f){
  this->f.anio = f;
  this->f.dc = 1;
}

void EventoHistorico::setFecha(Fecha f) {
  this->f = f;
}

void EventoHistorico::setEvento(std::vector<Acontecimiento> v){
  this->evento = v;
}

void EventoHistorico::addEvento(Acontecimiento a){ // TODO Devolver un bool o no?
  if (busquedaAcontecimiento(a) == evento.end()) {
    evento.push_back(a);
  }
}

void EventoHistorico::addEvento(std::vector<Acontecimiento> evento){
  for (std::vector<Acontecimiento>::iterator p = evento.begin(); p != evento.end(); ++p){
    addEvento(*p);
  }
}

/*
Busqueda y borrado
 */

std::vector<Acontecimiento>::iterator EventoHistorico::busquedaAcontecimiento(Acontecimiento a){
  bool encontrado = false;
  std::vector<Acontecimiento>::iterator p = evento.begin();

  while (p != evento.end() && !encontrado) {
    if (*p == a)
      encontrado = true;
      ++p;
  }

  return p;
}

std::vector<Acontecimiento> EventoHistorico::buscarAcontecimientos(std::string key) const{
  std::vector<Acontecimiento> v;

  for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
    if (p->find(key) != std::string::npos) {
      v.push_back(*p);
    }
  }

  return v;
}

bool EventoHistorico::eliminarAcontecimiento(Acontecimiento a){
  if (busquedaAcontecimiento(a) != evento.end()) {
    evento.erase(busquedaAcontecimiento(a));

    return true;
  }
  else
    return false;
}

void EventoHistorico::eliminar(std::string key){
  std::vector<Acontecimiento>::iterator p = evento.begin();

  while (p != evento.end()) {
    if (p->find(key) != std::string::npos) {
      evento.erase(p);
    }
    else
      ++p;
  }
}

/*
E/S
 */

 std::ostream& EventoHistorico::mostrarEvento(std::ostream& os) const{
   os << f.anio << '#' << f.dc;
   for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
     os << '#' << *p;
   }

   return os;
 }

 std::istream& EventoHistorico::leerEvento(std::istream& is){
  std::string a;

  std::getline(is, a, '#');
  f.anio= std::stoi(a);

  std::getline(is, a, '#');
  f.dc= std::stoi(a);

  while (std::getline(is, a, '#')) {
    evento.push_back(a);
  }

  return is;
 }

 std::ostream& EventoHistorico::prettyPrint(std::ostream& os) const{
  os << "Año: " << f.anio;
  if (f.dc)
    os << "dc";
  else
    os << "ac";

  os << '\n';

  for (std::vector<Acontecimiento>::const_iterator p = evento.begin(); p != evento.end(); ++p){
    os << "  -"<< *p << std::endl;
  }

   return os;
 }
