#include "../include/JugadorAuto.hpp"

/*
Constructores
 */

JugadorAuto::JugadorAuto(const Tablero &t): arbol(t){}

/*
Metodos privados
*/

/*
Precondicion: El nodo n tiene que ser una hoja
 */
void JugadorAuto::rellenarNodo(ArbolGeneral<Tablero>::Nodo n){
	ArbolGeneral<Tablero>::Nodo hermano_mas_der;

	for (int i = 0; i < n->etiqueta.GetColumnas(); i++) {
		ArbolGeneral<Tablero> hijo;
		Tablero tablero(n->etiqueta);

		if (tablero.colocarFicha(i)) {

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

/*
Metodos públicos
*/

ArbolGeneral<Tablero> JugadorAuto::GetArbol(){
  return arbol;
}

void JugadorAuto::rellenarArbol(int max_profundidad){
	ArbolGeneral<Tablero>::Nodo altura_a_rellenar = arbol.raiz();
	ArbolGeneral<Tablero>::Nodo aux = arbol.raiz();

	for (int i = 0; i < max_profundidad; i++) {
		do {
			rellenarNodo(aux);
			aux = aux->drcha;
			if(aux)
				aux -> etiqueta.cambiarTurno();
		} while(aux);

		altura_a_rellenar = arbol.hijomasizquierda(altura_a_rellenar);
		aux = altura_a_rellenar;
	}
}

void JugadorAuto::recorrerarbolpreorden(){
	arbol.recorrer_preorden();
}
