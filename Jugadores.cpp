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

void Jugadores::altaDeUnJugador(int cantFichas) {

	string nombre;

	char ficha = (char)(this->cantidadDeJugadores + 64);

	if (this->cantidadDeJugadores < 6) {

		cout << "Ingrese el nombre del jugador :";

		cin >> nombre;

		Jugador *nuevo = new Jugador(nombre, cantFichas, ficha);

		if (primero == NULL) {

			primero = nuevo;

			ultimo = nuevo;

			primero->setSig(primero);

			primero->setAnt(ultimo);

			this->listaDeJugadores = this->primero;

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

Jugador* Jugadores::avanzaUnJugador() {

	this->listaDeJugadores = listaDeJugadores->getSig();

	return (this->listaDeJugadores);

}

Jugador* Jugadores::getListaDeJugadores () {

	return (this->listaDeJugadores);

}

Jugador* Jugadores::getJugadorN(int n) {

	Jugador *jugadorN = new Jugador ();

	jugadorN = primero;

	for (int j = 0; j < n; j++) {

		jugadorN = jugadorN->getSig();
	}

	return (jugadorN);

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

void Jugadores::eliminarFichaJugadores(Jugador * jugadorActual){
	Jugador * aux = primero;
	while(aux->getNombre() != ultimo->getNombre()){
		if(aux->getNombre() != jugadorActual->getNombre()){
			aux->setFichasRestantes(-5);
			aux = aux->getSig();
		}
	}
}

/*
* pre: Existe la lista
* pos: Destruye la lista
*/
Jugadores::~Jugadores() {

	if (listaDeJugadores) {

		Jugador *aux = listaDeJugadores;

		for (int i = 0; i < this->cantidadDeJugadores; i++) {

			listaDeJugadores = listaDeJugadores->getSig();

			delete aux;

			aux = listaDeJugadores;

		}
	}
}








