/*
 * Jugador.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Jugador.h"

#include <string>

Jugador::Jugador(std::string name, unsigned int fichasIniciales, char fficha) {

	this->nombre = name;

	this->fichasRestantes = fichasIniciales;

	this->ficha = fficha;

	this->juegosGanados = 0;

	for (int i = 0; i < 3; i++) {

		this->cartas[i] = 0;
	}
};

