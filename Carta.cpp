/*
 * Carta.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */
#include "Carta.h"

#include <cstdlib>

Carta::Carta () {

	this->info = rand() % 4 + 1;

	this->sig = NULL;

}

Carta::Carta(int valor) {

	this->info = valor;

	this->sig = NULL;

}

int  Carta::getInfo() {

	return this->info;

}

Carta* Carta::getSig() {

	return this->sig;

}

void Carta::setSig (Carta* n) {

	this->sig = n;

}
