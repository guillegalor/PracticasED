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

void EventoHistorico::addEvento(Acontecimiento a){
  
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
