#ifndef CRONOLOGIA_
#define CRONOLOGIA_

#include <iostream>
#include <vector>
#include "EventoHistorico.hpp"

class Cronologia{
  private:
    std::vector<EventoHistorico> eventos;

    void insertaEvento(EventoHistorico v);
    std::vector<EventoHistorico>::iterator getPos(Fecha f);
    std::vector<EventoHistorico>::const_iterator getPos(Fecha f)const;
  public:
    //Constructores
    Cronologia(){}
    Cronologia(EventoHistorico evento);
    Cronologia(std::vector<EventoHistorico> v);

    //Set&Get
    std::vector<EventoHistorico> getEventos()const {return eventos;}
    void setEventoHistorico(std::vector<EventoHistorico> v);
    void addEventoHistorico(EventoHistorico a);                               // Añade el evento historico(Realiza la union)
    void addEventoHistorico(std::vector<EventoHistorico> v);                  // Añade el vector v a la cronologia(Realiza la union)
    Fecha getPrimerAnio()const;                                                // Devuelve el primer año de la cronologia
    Fecha getUltimoAnio()const;                                                // Devuelve el ultimo año de la cronologia
    EventoHistorico getEventoAnio(Fecha f)const;                              // Devuelve el evento sucedido en la fecha f

    //Eliminar y busqueda
    bool eliminarEventoAnio(Fecha f);                                         // Elimina el evento historico del año
    std::vector<EventoHistorico> restringir(Fecha f, Fecha l)const;                                        // Restringe la cronologia a los eventos contenidos entre las fechas f y l
    // int eliminar(std::string key);
    std::vector<EventoHistorico> buscar(std::string key)const;                     // Busca todos aquellos eventos que contengan al menos un acontecimiento con la clave key.

    //E&S
    std::istream& leerCronologia(std::istream& is);                           // Carga la cronologia del flujo de entrada is
    std::ostream& mostrarCronologia(std::ostream& os) const;                  // Imprime la cronologia en el flujo de salid os
    std::ostream& prettyPrintCronologia(std::ostream& os) const;                        // Muestra la cronologia en una interfaz intuitiva y agradable


};

#endif
