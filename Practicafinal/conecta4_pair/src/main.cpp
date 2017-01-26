#include "JugadorAuto.hpp"
#include "ArbolGeneral.hpp"
#include "../include/tablero.hpp"
#include "mando.hpp"

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <termio.h>

void imprimeTablero(Tablero &t, Mando &m){
    cout << m.GetJugador() << endl;
    cout << t ;
    cout << m.GetBase() << endl;
    cout << m.GetMando() << endl;
}

int main(int argc, char const *argv[]) {
	Tablero tablero(5,7);
	Mando mando(tablero);

	tablero.colocarFicha(3);
	tablero.colocarFicha(3);

	tablero.cambiarTurno();
	tablero.colocarFicha(0);

	imprimeTablero(tablero, mando);

	JugadorAuto j1(tablero);
	tablero.colocarFicha(j1.metrica_defensiva());
	imprimeTablero(tablero, mando);


	tablero.cambiarTurno();
	j1.actualizar(tablero);
	tablero.colocarFicha(j1.metrica_ofensiva());

	imprimeTablero(tablero, mando);
}
