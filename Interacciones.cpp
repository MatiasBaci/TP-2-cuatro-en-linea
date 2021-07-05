/*
 * Interacciones.cpp
 *
 *  Created on: May 1, 2021
 *      Author: algo2
 */

#include <iostream>

#include "Interacciones.h"

#include "Tablero.h"

#include "TP2.h"

void presentacion () {

	std::cout << std::endl << std::endl << std::endl;

	std::cout << "                               ***************************** " << std::endl;

	std::cout << "                               JUEGO CUATRO EN LINEA V 1.0 " << std::endl;

	std::cout << "                              ***************************** " << std::endl << std::endl;

	std::cout << "Bienvenido al juego cuatro en linea version mejorada. " << std::endl << std::endl;

	std::cout << "El juego consiste en alinear un conjunto de fichas ( vertical, horizontal o diagonal ) " << std::endl
			  << "en un tablero 3D. " << std::endl << std::endl;

	std::cout << "Se puede jugar con ciertos parametros predeterminados a saber : " << std::endl << std::endl

			  << "Cantidad de Jugadores : 2" << std::endl << std::endl

			  << "Dimensiones del tablero : 10 x 10 x 10 posiciones" << std::endl << std::endl

			  << "Cantidad de fichas iniciales : 50" << std::endl << std::endl

			  << "Cantidad de fichas alineadas para ganar : 4" << std::endl << std::endl

			  << "O bien definirlos al inicio del juego" << std::endl << std::endl

			  << "Que se diviertan!!" << std::endl << std::endl;
}

void opcionesDeJuego (TP2* n) {

	char opcion;

	std::cout << "Desea cambiar los parametros predeterminados s/n : ";

	std::cin >> opcion;

	std::cout << std::endl;

	if ((opcion == 's') || (opcion == 'S')) {

		n->setLargo();

		n->setAncho();

		n->setProfundidad();

		n->setCantidadDeJugadores();

		n->setCantidadFichasEnLinea();
	}
}

int queCartaVaAJugar (Jugador* jugadorDeTurno){

	int cartaSeleccionada;

	jugadorDeTurno->emite();

	std::cout << "Ingrese el numero de carta que desea jugar, si no desea jugar ninguna ingrese 7 : " << std::endl;

	std::cin >> cartaSeleccionada;

	return cartaSeleccionada;

}
