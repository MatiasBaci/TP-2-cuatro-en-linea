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

#include "MazoDeCartas.h"

#include "Jugador.h"

#include <string>

#include <iostream>

using namespace std;

int main () {

	presentacion ();

	TP2* codeando21 = new TP2();

	opcionesDeJuego(codeando21);

	MazoDeCartas* mazo = codeando21->crearMazoDeCartas();

	cout << "LLega hasta aca 1" << endl;

	codeando21->getTablero()->inicializaTablero(codeando21->getLargo(), codeando21->getAncho(), codeando21->getProfundidad());

	cout << "LLega hasta aca 2" << endl;

	codeando21->setJugadores();

	cout << "El cursor esta en " << codeando21->getJugadores()->getListaDeJugadores()->getNombre() << endl;

	Posicion* posicionJugada;

	posicionJugada = codeando21->jugar();

	while(!codeando21->getTablero()->hayGanador(posicionJugada, codeando21->getCantidadFichasEnLinea()))

		codeando21->getJugadores()->getListaDeJugadores()->altaDeUnaCarta(mazo);

		codeando21->getJugadores()->avanzaUnJugador();

		posicionJugada = codeando21->jugar();

	};


/*	for (int i = 0; i < codeando21.getCantidadDeJugadores(); i++) {

		cout << "LLega hasta aca" << endl;

		codeando21.getJugadores()->altaDeUnJugador();

		codeando21.getJugadores()->altaDeUnJugador();

		cout << "LLega hasta aca tambien" << endl; }*/

	/*	codeando21.getJugadores().getJugadorN(i)->altaDeUnaCarta();

		codeando21.getJugadores().getJugadorN(i)->altaDeUnaCarta();

		codeando21.getJugadores().getJugadorN(i)->altaDeUnaCarta();

		codeando21.getJugadores().getJugadorN(i)->emite();*/

//	}






//	codeando21.setLargo();

/*	codeando21.setAncho();

	codeando21.setProfundidad();

	codeando21.setCantidadDeJugadores();

	codeando21.setCantidadFichasEnLinea();

	codeando21.setJugadores();*/

//	Tablero tablero;

//	tablero.inicilizaTablero(codeando21.getLargo(), codeando21.getAncho(), codeando21.getProfundidad());

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

	msCartas.emite();*/

/*Jugador Alex ("Jose", 3, 'A');

std::cout << Alex.getNombre() << " tiene "
		  << Alex.getFichasRestantes() << " fichas " << " y juega con la " << Alex.getFicha();*/

/*MazoDeCartas* mazo = new MazoDeCartas();

for (int i = 0; i < 50; i++) {

	mazo->agregarUnaCarta();

}*/

/*for (int i = 0; i < 40; i++){

	cout << mazo.sacarUnaCarta() << endl;

}*/

/*
Jugadores* SanLorenzo = new Jugadores();

cout << "Hay " << codeando21->getCantidadDeJugadores() << " jugadores" << endl;

for (int i = 0; i < codeando21->getCantidadDeJugadores(); i++) {

	SanLorenzo->altaDeUnJugador(codeando21->getCantidadDeFichasIniciales());

	SanLorenzo->getJugadorN(i)->altaDeUnaCarta(mazo);

	SanLorenzo->getJugadorN(i)->altaDeUnaCarta(mazo);

	SanLorenzo->getJugadorN(i)->altaDeUnaCarta(mazo);

	SanLorenzo->getJugadorN(i)->emite();

}*/






/*SanLorenzo.alta();

SanLorenzo.alta();

SanLorenzo.alta();*/

/*SanLorenzo.emitePU();

SanLorenzo.emiteUP();*/


	return 0;
}


