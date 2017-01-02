#include "JugadorAuto.hpp"
#include "ArbolGeneral.hpp"
#include "tablero.h"
#include "mando.h"

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
	JugadorAuto j1(tablero);
	Mando mando(tablero);

	j1.rellenarArbol(3);

	j1.recorrerarbolpreorden();

}
