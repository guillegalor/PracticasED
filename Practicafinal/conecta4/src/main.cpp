#include "../include/jugadorauto.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  JugadorAuto nuevo;
  Tablero mitab;
  nuevo.CalcularPrimeraFila(mitab);

  ArbolGeneral<Tablero> arbol;
  arbol = nuevo.GetArbol();

  arbol.recorrer_preorden();


  return 0;
}
