/*
 * principal.cpp

 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Posicion.h"

#include "Tablero.h"

#include <iostream>

using namespace std;

int main () {

	int largo = 5;
	int ancho =5;
	int profundidad =5;

	Tablero tablero;

	tablero.inicilizaTablero(largo, ancho, profundidad);

	return 0;
}


