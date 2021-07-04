/*
 * Cartas del Jugador.cpp

 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Cartas del Jugador.h"

#include "Carta.h"

#include <iostream>

cartasDelJugador::cartasDelJugador() {

	this->cantidadDeCartas = 0;

	this->cartaDelJugador = NULL;
}

void cartasDelJugador::alta() {

	if (this->cantidadDeCartas < 3) {

	Carta *aux = cartaDelJugador;

		while ((aux) && (aux->getSig())) {

			aux = aux->getSig();

		}
		if (aux) {

			aux->setSig(new Carta());

		} else {

			cartaDelJugador = new Carta ();

		}

		this->cantidadDeCartas++;

	}

}

void cartasDelJugador::baja(int cartaSeleccionada) {

	if (cartaDelJugador) {

		if((cartaDelJugador->getInfo() != cartaSeleccionada) && (cartaDelJugador->getSig())) {

			Carta *aux1 = cartaDelJugador, *aux2 = cartaDelJugador->getSig();

			while ((aux2->getInfo() != cartaSeleccionada) && (aux2->getSig() != NULL)) {

				aux1 = aux2;

				aux2 = aux2->getSig();

			}

			if (aux2->getInfo() == cartaSeleccionada) {

				aux1->setSig(aux2->getSig());

				delete aux2;

			}

		}	else {

			if (cartaDelJugador->getInfo() == cartaSeleccionada) {

				Carta *aux = cartaDelJugador;

				cartaDelJugador = cartaDelJugador->getSig();

				delete aux;

			}

		}

	}

	cantidadDeCartas--;

}

bool cartasDelJugador::busca(int cartaSeleccionada) {

	Carta *aux = cartaDelJugador;

	while ((aux) && (aux->getInfo() != cartaSeleccionada)){

		aux = aux->getSig();

	}

	if (aux) {

		return true;

	} else {

		return false;

	}

}

void cartasDelJugador::emite() const {

	Carta *aux = cartaDelJugador;

	while (aux) {

		switch(aux->getInfo()) {

			case 1 : std::cout << "- (1) Saltear un jugador" << std::endl;

			break;

			case 2 : std::cout << "- (2) Juego de nuevo" << std::endl;

			break;

			case 3 : std::cout << "- (3) Saco fichas 5 fichas a los demas jugadores" << std::endl;

			break;

			case 4 : std::cout << "- (4) Invierto el orden de juego" << std::endl;

			break;

		}

		aux = aux->getSig();

	}

}

cartasDelJugador::~cartasDelJugador() {

	if (cartaDelJugador) {

		Carta *aux = cartaDelJugador;

		while (aux) {

			cartaDelJugador = cartaDelJugador->getSig();

			delete aux;

			aux = cartaDelJugador;

		}
	}
}
