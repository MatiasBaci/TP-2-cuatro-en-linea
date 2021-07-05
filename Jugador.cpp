/*
 * Jugador.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Jugador.h"

#include "Cartas del Jugador.h"

#include "MazoDeCartas.h"

#include <iostream>

#include <string>

using namespace std;

Jugador::Jugador() {

	this->fichasRestantes = 0;

	this->ficha = (char) 0;

	this->juegosGanados = 0;

	this->cantidadDeCartas = 0;

	this->sig = NULL;

	this->ant = NULL;

	misCartas = NULL;
}

Jugador::Jugador(std::string name, unsigned int fichasIniciales, char fficha) {

	this->nombre = name;

	this->fichasRestantes = fichasIniciales;

	this->ficha = fficha;

	this->cantidadDeCartas = 0;

	this->juegosGanados = 0;

	misCartas = NULL;

	this->sig = NULL;

	this->ant = NULL;
}

Jugador::~Jugador() {

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

void Jugador::altaDeUnaCarta (MazoDeCartas* mazo) {

	if (this->cantidadDeCartas < 3) {

		Carta *aux = misCartas;

		while ((aux) && (aux->getSig())) {

			aux = aux->getSig();
		}


		if (aux) {

			aux->setSig(new Carta (mazo->sacarUnaCarta()));


		} else {

			misCartas = new Carta (mazo->sacarUnaCarta());

		}

		this->cantidadDeCartas++;

	}

}

void Jugador::bajaDeUnaCarta(int numeroCarta){
	Carta * aux = misCartas;
	Carta * aux2 = misCartas->getSig();
	int iterador = 1;

	while(aux && aux2 && iterador < numeroCarta - 1){
		aux = aux2;
		aux2 = aux2->getSig();
		iterador++;
	}

	if(aux2->getSig()){
		aux->setSig(aux2->getSig());
		delete aux2;
	}

	else{

		delete aux2;
	}
	
	this->cantidadDeCartas--;
}


void Jugador::emite() const {

	Carta *aux = misCartas;

	while (aux) {


		switch(aux->getInfo()) {

			case 1 : std::cout << "- (1) Saltear un jugador" << std::endl;

			break;

			case 2 : std::cout << "- (2) Juego de nuevo" << std::endl;

			break;

			case 3 : std::cout << "- (3) Saco 5 fichas a los demas jugadores" << std::endl;

			break;

			case 4 : std::cout << "- (4) Invierto el orden de juego" << std::endl;

			break;

		}

		aux = aux->getSig();

	}

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
