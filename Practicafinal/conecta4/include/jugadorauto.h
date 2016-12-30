#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.h"
#include "tablero.h"
#include <cassert>


class JugadorAuto{

private:
  ArbolGeneral<Tablero> arbol;

public:

  JugadorAuto();

  JugadorAuto(const Tablero &t);

  ArbolGeneral<Tablero>  Calcular(const Tablero t);

  bool InsertarTablero(const Tablero t,int pos, ArbolGeneral<Tablero> arbol);

  ArbolGeneral<Tablero> GetArbol();

  void CalcularPrimeraFila(const Tablero t);

}
#endif
