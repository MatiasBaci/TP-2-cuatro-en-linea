/*
 * Jugador.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Jugador.h"

#include "Cartas del Jugador.h"

#include <string>

Jugador::Jugador() {

	this->fichasRestantes = 0;

	this->ficha = (char) 0;

	this->juegosGanados = 0;

	this->sig = NULL;

	this->ant = NULL;

	misCartas = NULL;
}

Jugador::Jugador(std::string name, unsigned int fichasIniciales, char fficha) {

	this->nombre = name;

	this->fichasRestantes = fichasIniciales;

	this->ficha = fficha;

	this->juegosGanados = 0;

	misCartas = NULL;

	this->sig = NULL;

	this->ant = NULL;
}

std::string Jugador::getNombre() {

	return this->nombre;

}

char Jugador::getFicha() {

	return this->ficha;

}

unsigned int Jugador::getFichasRestantes() {

	return this->fichasRestantes;

}

unsigned int Jugador::getJuegosGanados () {

	return this->juegosGanados;

}

void Jugador::setFichasRestantes (int variacion) {

	this->fichasRestantes += variacion;

}

Jugador* Jugador::getSig() {

	return sig;
}

Jugador* Jugador::getAnt() {

	return ant;

}

void Jugador::setSig(Jugador* n) {

	this->sig = n;

}

void Jugador::setAnt(Jugador* n) {

	this->ant = n;

}

void Jugador::setJuegosGanados () {

	this->juegosGanados++;

}
