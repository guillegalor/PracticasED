#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.h"
#include <cassert>


class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;

		void rellenarNodo(ArbolGeneral<Tablero>::Nodo n);

	public:
		/*
		Constructores
		 */
  	JugadorAuto(){}
  	JugadorAuto(const Tablero &t);

		/* TODO Pendientes de revision
		void CalcularPrimeraFila(const Tablero t);
		ArbolGeneral<Tablero>  Calcular(const Tablero t);
		bool InsertarTablero(const Tablero t,int pos, ArbolGeneral<Tablero> arbol);
		*/


		ArbolGeneral<Tablero> GetArbol();
		void rellenarArbol(int max_profundidad);
};

#endif
