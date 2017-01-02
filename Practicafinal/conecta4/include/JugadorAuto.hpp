#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.h"
#include <cassert>

/**
 * @brief T.D.A. JugadorAuto
 *
 */
class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;   //< Arbol de tableros que representa todos movimientos

		/**
		 * @brief Crea todos los posibles tableros que surgen de la etiqueta
		 * del nodo que se le pasa, y los engancha como hijos del nodo que se le pasa.
		 * PRECONDICION: El nodo n tiene que ser una hoja.
		 * @param n Nodo al que se le calculan sus hijos.
		 */
		void rellenarNodo(ArbolGeneral<Tablero>::Nodo n);

	public:

		/**
		 * @brief Constructor vacio. Crea un arbol vacio de tableros.
		 */
  	JugadorAuto(){}

		/**
		 * @brief Constructor. Crea un arbol de tableros, cuya raiz
		 * es el tablero que se le pasa.
		 * @param t: tablero que será la raiz de arbol de tableros.
		 */
  	JugadorAuto(const Tablero &t);

		/**
		 * @brief Devuelve el arbol de tableros.
		 * IMPORTANTE: Esta función esta pendiente de revisión, la estamos usando
		 * para probar si funcionan los metodos de la clase, extrayendo
		 * el arbol y mostrandolo por pantalla.
		 * @return Devuelve el arbol de la clase.
		 */
		ArbolGeneral<Tablero> GetArbol();

		/**
		 * @brief Rellena el arbol de tableros, con todos los tableros
		 * posibles hasta una profundidad.
		 * @param max_profundidad Indica la profundidad con la que se va
		 * a calcular las posibles jugadas.
		 */
		void rellenarArbol(int max_profundidad);

		void recorrerarbolpreorden();

};

#endif
