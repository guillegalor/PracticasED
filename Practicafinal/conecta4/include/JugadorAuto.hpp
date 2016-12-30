#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.h"
#include "tablero.h"
#include <cassert>


class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;
		const int max_profundidad = 5;

		void rellenarArbol();
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

};

#endif
