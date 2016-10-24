#ifndef EVENTO_HISTORICO
#define EVENTO_HISTORICO

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

enum campo {algoritmos, peliculas, ciencias, historia};

class EventoHistorico{
private:
  int fecha;
  std::vector<std::string> acontecimientos;

public:
  EventoHistorico():fecha(-1){}
  EventoHistorico(int f);
  EventoHistorico(int f, std::vector<std::string> v);
  EventoHistorico(int f, std::string keyword);
  //EventoHistorico(int f, std::vector<std::string> keywords);
  EventoHistorico(int f, campo tipo);

  int getFecha();
  std::vector<std::string> getAcontecimientos();

  std::ostream mostrarEvento(std::ostream os);
  std::istream leerEvento(std::istream is); //Haria falta añadir algun parametro para saber como leer?



};

#endif
