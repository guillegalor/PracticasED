#ifndef CRONOLOGIA_
#define CRONOLOGIA_

#include <iostream>
#include <vector>
#include "EventoHistorico.hpp"

class Cronologia{
  private:
    std::vector<EventoHistorico> eventos;

    void insertaEvento(EventoHistorico v);
  public:
    //Constructores
    Cronologia(){}
    Cronologia(EventoHistorico evento);
    Cronologia(std::vector<EventoHistorico> v):eventos(v){}         // TODO Pensar si hace falta algun constructor mas constructores

    //Set&Get                                                       // TODO Comprobar cuales son o no constantes
    std::vector<EventoHistorico> getEventos(){return eventos;}
    void setEventos(std::vector<EventoHistorico> v){eventos = v;}
    void addEvento(EventoHistorico a);                              // Añade el evento historico(Realiza la union)
    void addEvento(std::vector<EventoHistorico> v);                 // Añade el vector v a la cronologia(Realiza la union)
    Fecha getPrimerAño();                                           // Devuelve el primer año de la cronologia
    Fecha getUltimoAño();                                           // Devuelve el ultimo año de la cronologia
    EventoHistorico getEventoAnio(Fecha f);                         // Devuelve el evento sucedido en la fecha f
                                                                    // TODO Pensar acerca de si merece la pena definir el struct fecha

    //Eliminar y busqueda
    bool eliminarEventoAnio(Fecha f);                               // Elimina el evento historico del año
    void restringir(Fecha f, Fecha l);                              // Restringe la cronologia a los eventos contenidos entre las fechas f y l
    // int eliminar(std::string key);
    std::vector<EventoHistorico> buscar(std::string key);           // Busca todos aquellos eventos que contengan al menos un acontecimiento con la clave key.

    //E&S
    std::istream& leerCronologia(std::istream& is);                 // Carga la cronologia del flujo de entrada is
    std::ostream& mostrarCronologia(std::ostream& os) const;        // Imprime la cronologia en el flujo de salid os
    std::ostream& prettyPrint(std::ostream& os) const;              // Muestra la cronologia en una interfaz intuitiva y agradable


};

#endif
