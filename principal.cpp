/*
 * principal.cpp

 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "TP2.h"

#include "Posicion.h"

#include "Tablero.h"

#include <iostream>

using namespace std;

int main () {

	TP2 codeando21;

	codeando21.setLargo();

	codeando21.setAncho();

	codeando21.setProfundidad();

	codeando21.setCantidadDeJugadores();

	codeando21.setCantidadFichasEnLinea();

	codeando21.setJugadores();

	Tablero tablero;

	tablero.inicilizaTablero(codeando21.getLargo(), codeando21.getAncho(), codeando21.getProfundidad());

	return 0;
}


