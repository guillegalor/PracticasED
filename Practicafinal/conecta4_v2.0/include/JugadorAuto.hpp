#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.hpp"
#include <cassert>


class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;

		void rellenarNodo(ArbolGeneral<Tablero>::Nodo n);
		void rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, int max_profundidad);

	public:
		/*
		Constructores
		 */
  	JugadorAuto(){}
  	JugadorAuto(const Tablero &t);

		ArbolGeneral<Tablero> GetArbol();

		/* TODO Pendientes de revision
		void CalcularPrimeraFila(const Tablero t);
		ArbolGeneral<Tablero>  Calcular(const Tablero t);
		bool InsertarTablero(const Tablero t,int pos, ArbolGeneral<Tablero> arbol);
		*/
};

#endif
