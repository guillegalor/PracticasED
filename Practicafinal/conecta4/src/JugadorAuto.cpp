#include "../include/jugadorauto.h"


  JugadorAuto::JugadorAuto(){}

  JugadorAuto::JugadorAuto(const Tablero &t){

  }

    ArbolGeneral<Tablero> JugadorAuto::Calcular(const Tablero t){
    Tablero copia = t;
    ArbolGeneral<Tablero> aux, rama;
    aux.AsignaRaiz(t);

    for(int i=0; i<t.GetColumnas(); i++){
      if(InsertarTablero(t,i,aux)){
        copia.colocarFicha(i);
        rama = Calcular(copia);
        aux.insertar_hijomasizquierda(aux.hijomasizquierda(aux.raiz()), rama);
      }

    }

    return aux;

  }

  bool JugadorAuto::InsertarTablero(const Tablero t,int pos, ArbolGeneral<Tablero> arbol){
    Tablero aux = t;
    ArbolGeneral<Tablero> copia;
    if((aux.colocarFicha(pos)) != 0){
      copia.AsignaRaiz(aux);
      arbol.insertar_hijomasizquierda(arbol.hijomasizquierda(arbol.raiz()),copia );
      return true;
    }else
      return false;

  }

  ArbolGeneral<Tablero> JugadorAuto::GetArbol(){
    return arbol;
  }


  void JugadorAuto::CalcularPrimeraFila(const Tablero t){
    arbol.AsignaRaiz(t);

    for(int i=0; i < t.GetColumnas(); i++){
      InsertarTablero(t,i,arbol);
    }

  }
