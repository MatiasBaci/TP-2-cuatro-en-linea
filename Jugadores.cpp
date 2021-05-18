/*
 * Jugadores.cpp
 *
 *  Created on: May 1, 2021
 *      Author: algo2
 */

#include "Jugadores.h"

#include "Jugador.h"

#include <iostream>

#include <string>

using namespace std;

Jugadores::Jugadores() {

	cantidadDeJugadores = 0;

	listaDeJugadores = NULL;

	primero = NULL;

	ultimo = NULL;

}

void Jugadores::alta() {

	string nombre;

	unsigned int cantFichas = 20;

	char ficha = 'A';

	if (this->cantidadDeJugadores < 6) {

		cout << "Ingrese el nombre del jugador :";

		cin >> nombre;

		Jugador *nuevo = new Jugador(nombre, cantFichas, ficha);

		if (primero == NULL) {

			primero = nuevo;

			ultimo = nuevo;

			primero->setSig(primero);

			primero->setAnt(ultimo);

		} else {

			ultimo->setSig(nuevo);

			nuevo->setAnt(ultimo);

			nuevo->setSig(primero);

			ultimo = nuevo;

			primero->setAnt(ultimo);

		}

		this->cantidadDeJugadores++;

	}

}

void Jugadores::emitePU () const {

	Jugador *actual = new Jugador();

	actual = primero;

	if (primero != NULL) {

		do {

			cout << actual->getNombre() << endl;

			actual = actual->getSig();

		} while (actual != primero);

	} else {

		cout << "La lista de jugadores esta vacia" << endl;

	}

}

void Jugadores::emiteUP () const {

	Jugador *actual = new Jugador();

	actual = ultimo;

	if (primero != NULL) {

		do {

			cout << actual->getNombre() << endl;

			actual = actual->getAnt();

		} while (actual != ultimo);

	} else {

		cout << "La lista de jugadores esta vacia" << endl;

	}

}

/*
* pre: Existe la lista
* pos: Destruye la lista
*/
Jugadores::~Jugadores() {

	if (listaDeJugadores) {

		Jugador *aux = listaDeJugadores;

		while (aux) {

			listaDeJugadores = listaDeJugadores->getSig();

			delete aux;

			aux = listaDeJugadores;

		}
	}
}








