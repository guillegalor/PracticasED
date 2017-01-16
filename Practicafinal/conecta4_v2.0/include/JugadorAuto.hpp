#ifndef __CONECTA4_H__
#define __CONECTA4_H__


#include "ArbolGeneral.hpp"
#include "tablero.hpp"
#include <cassert>


class JugadorAuto{
	private:
  	ArbolGeneral<Tablero> arbol;
		unsigned max_profundidad;

		void rellenarNodo(ArbolGeneral<Tablero>::Nodo n);
		void rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, int profundidad);
		void rellenarTablero(int profundidad);
		void actualizar(Tablero tab);

		const ArbolGeneral<Tablero>::Nodo buscarNodo(ArbolGeneral<Tablero>::Nodo n, Tablero tab ) const;
		const ArbolGeneral<Tablero>::Nodo buscarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, Tablero tab, int profundidad) const;

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
