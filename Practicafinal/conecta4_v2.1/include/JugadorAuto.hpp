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
		void rellenarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, unsigned profundidad);

		const ArbolGeneral<Tablero>::Nodo buscarNodo(ArbolGeneral<Tablero>::Nodo n, Tablero tab ) const;
		const ArbolGeneral<Tablero>::Nodo buscarNodoProfundidad(ArbolGeneral<Tablero>::Nodo n, Tablero tab, int profundidad) const;
		int gana(ArbolGeneral<Tablero>:: Nodo n);
		int contarNumVictorias(ArbolGeneral<Tablero>::Nodo n);
		int contarNumDerrotas(ArbolGeneral<Tablero>::Nodo n);

	public:
		/*
		Constructores
		 */
  	JugadorAuto():max_profundidad(0){}
  	JugadorAuto(const Tablero &t);

		ArbolGeneral<Tablero> GetArbol();	// TODO Esta funcion no deberia de existir. Solo pruebas

		void rellenarTablero(unsigned profundidad); // TODO Esta funcion es privada. Esta aquí para pruebas
		void actualizar(Tablero tab);
		unsigned metrica_defensiva_simple();
		unsigned metrica_defensiva();
		unsigned metrica_ofensiva();

};

#endif
