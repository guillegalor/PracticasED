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

void JugadorAuto::rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, int profundidad){
	// Si la profundidad es 0 o negativa salimos del programa
	if (profundidad < 1) {
		printf("Profundidad no valida(<1)\n");
		exit(-1);
	}

	// Rellenamos el nodo pasado como argumento(rellenamos unicamente el nivel justo mas bajo)
  // TODO Comprobar si nodo n relleno;
  rellenarNodo(n);

	ArbolGeneral<Tablero>::Nodo aux;

	/*
	Si la profundidad hasta la que hay que rellenar es mayor que 1, llamamos de nuevo a esta funcion
	pasandole como argumento cada nodo hijo de este, y una produndidad una unidad mejor
	 */
	if (profundidad > 1) {
		for(aux = arbol.hijomasizquierda(n); aux != 0; aux = arbol.hermanoderecha(aux)){
			rellenarNodoProfundidad(aux, profundidad-1);
		}
	}
}

void JugadorAuto::rellenarTablero(int profundidad) {
  if (profundidad > max_profundidad) {
    rellenarNodoProfundidad(arbol.raiz(), profundidad);
    max_profundidad = profundidad;
  }
}

//Precondicion: Nodo n esta relleno. Nodo que devuelve cte?
const ArbolGeneral<Tablero>::Nodo JugadorAuto::buscarNodo(ArbolGeneral<Tablero>::Nodo n, Tablero tab ) const{
  ArbolGeneral<Tablero>::Nodo aux;
  for(aux = arbol.hijomasizquierda(n); aux != 0; aux = arbol.hermanoderecha(aux) )
    if(aux->etiqueta == tab)
      return aux;

  return aux;
}

//Precondicion: la profundidad no puede ser negativa. TODO Nodo que devuelve cte?
const ArbolGeneral<Tablero>::Nodo JugadorAuto::buscarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, Tablero tab, int profundidad) const{
  ArbolGeneral<Tablero>::Nodo aux, resultado;

  resultado = buscarNodo(n, tab);

  if(profundidad > 1){
    for(aux = arbol.hijomasizquierda(n); (aux != 0) && !resultado; aux = arbol.hermanoderecha(aux) ){
      resultado = buscarNodoProfundidad(aux,tab, profundidad-1);
    }
  }

  return resultado;
}

void JugadorAuto::actualizar(Tablero tab){
  ArbolGeneral<Tablero>::Nodo n;
  unsigned profundidad;

  n = buscarNodoProfundidad(arbol.raiz(), tab, max_profundidad);

  if (n) {
    profundidad = max_profundidad;

    arbol.AsignaRaiz(n);
    max_profundidad = arbol.altura(n);

    rellenarTablero(profundidad);
  }

}
