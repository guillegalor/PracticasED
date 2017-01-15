#include "../include/JugadorAuto.hpp"

JugadorAuto::JugadorAuto(const Tablero &t): arbol(t){}

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

void JugadorAuto::rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, int max_profundidad){
	// Si la profundidad es 0 o negativa salimos del programa
	if (max_profundidad < 1) {
		printf("Profundidad no valida(<1)\n");
		exit(-1);
	}

	// Rellenamos el nodo pasado como argumento(rellenamos unicamente el nivel justo mas bajo)
	rellenarNodo(n);

	ArbolGeneral<Tablero>::Nodo aux;

	/*
	Si la profundidad hasta la que hay que rellenar es mayor que 1, llamamos de nuevo a esta funcion
	pasandole como argumento cada nodo hijo de este, y una produndidad una unidad mejor 
	 */
	if (max_profundidad > 1) {
		for(aux = arbol.hijomasizquierda(n); aux != 0; aux = arbol.hermanoderecha(aux)){
			rellenarNodoProfundidad(aux, max_profundidad-1);
		}
	}
}

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
