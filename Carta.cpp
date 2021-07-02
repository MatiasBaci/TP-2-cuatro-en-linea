/*
 * Carta.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */
#include "Carta.h"

#include <cstdlib>

Carta::Carta () {

	this->info = rand() % 5 + 1;

	this->sig = NULL;

}

int  Carta::getInfo() {

	return info;

}

Carta* Carta::getSig() {

	return sig;

}

void Carta::setSig(Carta* n) {

	this->sig = n;

}
