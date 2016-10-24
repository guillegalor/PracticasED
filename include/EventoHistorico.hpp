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
  EventoHistorico(int fecha);
  EventoHistorico(int fecha, std::string keyword);
  //EventoHistorico(int fecha, std::vector<std::string> keywords);
  EventoHistorico(int fecha, campo tipo);

  int getFecha();
  std::vector<std::string> getAcontecimientos();

  void add(EventoHistorico evento);
  


};

#endif
