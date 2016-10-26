
#ifndef EVENTO_HISTORICO
#define EVENTO_HISTORICO

#include <iostream>
#include <vector>

//Definimos el struct fecha que incluye el año que siempre es positivo y un booleano para saber si es ac/dc
struct Fecha{
  int anio;
  bool dc;
};

typedef std::string Acontecimiento; //Llamamos acontecimiento a un string que va a contener su nombre

class EventoHistorico{

private:
  Fecha f;
  std::vector<Acontecimiento> evento;

  std::vector<Acontecimiento>::iterator busquedaAcontecimiento(Acontecimiento a);

public:
  //Constructores
  EventoHistorico();
  EventoHistorico(int f);
  EventoHistorico(Fecha f);
  EventoHistorico(int f, std::vector<Acontecimiento> v);
  EventoHistorico(Fecha f, std::vector<Acontecimiento> v);

  //Set Get
  Fecha getFecha() const{return f;}
  std::vector<Acontecimiento> getEvento() const{return evento;};
  void setFecha(int f);
  void setFecha(Fecha f);
  void setEvento(std::vector<Acontecimiento> v);
  void addEvento(Acontecimiento a);
  void addEvento(std::vector<Acontecimiento> evento);

  //Eliminar
  bool eliminarAcontecimiento(Acontecimiento a);
  bool eliminar(std::string key);

  //Busqueda
  std::vector<Acontecimiento> buscarAcontecimientos(std::string key) const; //Busca acontecimientos que contienen la palabra clave "key"

  //Entrada Salida
  std::ostream& mostrarEvento(std::ostream& os) const;
  std::istream& leerEvento(std::istream& is);
  std::ostream& prettyPrint(std::ostream& os) const;

};

#endif
