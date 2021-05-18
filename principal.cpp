/*
 * principal.cpp

 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "TP2.h"

#include "Interacciones.h"

#include "Posicion.h"

#include "Jugadores.h"

#include "Tablero.h"

#include "Cartas del Jugador.h"

#include "Jugador.h"

#include <string>

#include <iostream>

using namespace std;

int main () {

	presentacion ();

	TP2 codeando21;

	opcionesDeJuego (&codeando21);


//	codeando21.setLargo();

/*	codeando21.setAncho();

	codeando21.setProfundidad();

	codeando21.setCantidadDeJugadores();

	codeando21.setCantidadFichasEnLinea();

	codeando21.setJugadores();*/

	Tablero tablero;

	tablero.inicilizaTablero(codeando21.getLargo(), codeando21.getAncho(), codeando21.getProfundidad());

/*	cartasDelJugador msCartas;

	msCartas.alta();

	msCartas.alta();

	msCartas.alta();

	msCartas.emite();

	msCartas.baja(4);

	msCartas.baja(3);

	msCartas.alta();

	msCartas.emite();

	msCartas.baja(1);

	msCartas.baja(3);

	msCartas.baja(2);

	msCartas.alta();

	msCartas.alta();

	msCartas.alta();

	msCartas.emite();*/;

/*Jugador Alex ("Jose", 3, 'A');

std::cout << Alex.getNombre() << " tiene "
		  << Alex.getFichasRestantes() << " fichas " << " y juega con la " << Alex.getFicha();*/

Jugadores SanLorenzo;

for (int i = 0; i < codeando21.getCantidadDeJugadores(); i++) {

	SanLorenzo.alta();

}

/*SanLorenzo.alta();

SanLorenzo.alta();

SanLorenzo.alta();*/

SanLorenzo.emitePU();

SanLorenzo.emiteUP();


	return 0;
}


