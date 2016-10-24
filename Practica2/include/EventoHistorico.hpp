/**
  * @file EventoHistorico.hpp
  * @brief Fichero cabecera del TDA EventoHistorico
  *
  */


#ifndef EVENTO_HISTORICO
#define EVENTO_HISTORICO

#include <iostream>
#include <vector>

struct Fecha{
  int anio;
  bool dc;
};

typedef std::string Acontecimiento;

class EventoHistorico{
private:
  Fecha f;
  std::vector<Acontecimiento> evento;

public:
  //Constructores
  EventoHistorico();
  EventoHistorico(int f);
  EventoHistorico(int f, std::vector<Acontecimiento> v);

  //Set Get
  int getFecha();
  std::vector<Acontecimiento> getEvento();
  void setFecha(int f);
  void setEvento(std::vector<Acontecimiento> v);
  void addEvento(Acontecimiento a);
  void addEvento(std::vector<Acontecimiento> evento);

  //Eliminar
  bool eliminarAcontecimiento(Acontecimiento a);
  bool eliminar(std::string key);

  //Busqueda
  std::vector<Acontecimiento> buscarAcontecimientos(std::string key); //Busca acontecimientos que contienen

  //Entrada Salida
  std::ostream& mostrarEvento(std::ostream& os) const;
  std::istream& leerEvento(std::istream& is); //Haria falta añadir algun parametro para saber como leer?

};

#endif
