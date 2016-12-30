#include "../include/JugadorAuto.hpp"

JugadorAuto::JugadorAuto(const Tablero &t): arbol(t){}

/* TODO Pendiente de revision
void JugadorAuto::CalcularPrimeraFila(const Tablero t){

  for(int i=0; i < t.GetColumnas(); i++)
    InsertarTablero(t,i,arbol);
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
  }
	else
    return false;
}
*/

ArbolGeneral<Tablero> JugadorAuto::GetArbol(){
  return arbol;
}

/*
Precondicion: El nodo n tiene que ser una hoja
 */
void JugadorAuto::rellenarNodo(ArbolGeneral<Tablero>::Nodo n){
	ArbolGeneral<Tablero>::Nodo hermano_mas_der;

	for (int i = 0; i < n->etiqueta.GetColumnas(); i++) {
		ArbolGeneral<Tablero> hijo;
		Tablero tablero(n->etiqueta);

		if (tablero.colocarFicha(i)) {
			tablero.cambiarTurno();
			hijo.AsignaRaiz(tablero);

			if (!arbol.hijomasizquierda(n)){
				arbol.insertar_hijomasizquierda(n, hijo);
				hermano_mas_der = arbol.hijomasizquierda(n);
			}
			else{
				arbol.insertar_hermanoderecha(hermano_mas_der, hijo);
				hermano_mas_der = hermano_mas_der->drcha;
			}
		}
	}

}

void JugadorAuto::rellenarArbol(int max_profundidad){
	ArbolGeneral<Tablero>::Nodo altura_a_rellenar = arbol.raiz();
	ArbolGeneral<Tablero>::Nodo aux = arbol.raiz();

	for (int i = 0; i < max_profundidad; i++) {
		do {
			rellenarNodo(aux);
			aux = aux->drcha;
		} while(aux);

		altura_a_rellenar = arbol.hijomasizquierda(altura_a_rellenar);
		aux = altura_a_rellenar;
	}
}
