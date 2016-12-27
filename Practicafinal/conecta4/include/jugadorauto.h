#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.h"
#include "tablero.h"

class JugadorAuto{

private:
  ArbolGeneral <Tablero> arbol;

public:

  JugadorAuto();

  JugadorAuto(const Tablero &t);

  void Calcular(const Tablero t);

  void Actualizar(const Tablero);
}
#endif
