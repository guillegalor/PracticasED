

/*
Busqueda y borrado
 */

std::vector<Acontecimiento>::iterator EventoHistorico::busquedaAcontecimiento(Acontecimiento a){
  bool encontrado = false;
  std::vector<Acontecimiento>::iterator p = evento.second.begin();

  while (p != evento.second.end() && !encontrado) {
    if (*p == a)
      encontrado = true;
    else
      ++p;
  }

  return p;
}

std::set<Acontecimiento> EventoHistorico::buscar(std::string key) const{
  std::set<Acontecimiento> v;

  for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
    if (p->find(key) != std::string::npos) {
      v.second.insert(*p);
    }
  }

  return v;
}

bool EventoHistorico::eliminarAcontecimiento(Acontecimiento a){
  if (busquedaAcontecimiento(a) != evento.second.end()) {
    evento.second.erase(busquedaAcontecimiento(a));

    return true;
  }
  else
    return false;
}

int EventoHistorico::eliminar(std::string key){
  std::set<Acontecimiento>::iterator p = evento.second.begin();
  int acontecimientos_eliminados = 0;

  while (p != evento.second.end()) {
    if (p->find(key) != std::string::npos) {
      evento.second.erase(p);
      ++acontecimientos_eliminados;
    }
    else
      ++p;
  }

  return acontecimientos_eliminados;
}

/*
E/S
 */

std::ostream& EventoHistorico::mostrarEvento(std::ostream& os) const{
   os << evento.first.anio << '#' << evento.first.dc;
   for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
     os << '#' << *p;
   }

   return os;
 }

std::istream& EventoHistorico::leerEvento(std::istream& is){
  std::string a;

  std::getline(is, a, '#');
  evento.first.anio= std::stoi(a);

  std::getline(is, a, '#');
  evento.first.dc= std::stoi(a);

  std::getline(is, a);

  std::stringstream ss(a);

  while (std::getline(ss, a, '#')) {
    evento.second.insert(a);
  }

  return is;
}

std::ostream& EventoHistorico::prettyPrint(std::ostream& os) const{
  os << "Año: " << evento.first.anio;
  if (evento.first.dc)
    os << "dc";
  else
    os << "ac";

  os << '\n';

  for (std::set<Acontecimiento>::const_iterator p = evento.second.cbegin(); p != evento.second.end(); ++p){
    os << "  -"<< *p << std::endl;
  }

   return os;
}

std::ostream& operator<<(std::ostream& os, EventoHistorico a){
   return a.mostrarEvento(os);
}


std::istream& operator>>(std::istream& is, EventoHistorico a){
  return a.leerEvento(is);
}
