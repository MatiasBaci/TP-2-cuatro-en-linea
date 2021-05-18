/*
 * Carta.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */
#include "Carta.h"

#include <cstdlib>

carta::carta () {

	this->info = rand() % 5 + 1;

	this->sig = NULL;

}

int  carta::getInfo() {

	return info;

}

carta* carta::getSig() {

	return sig;

}

void carta::setSig(carta* n) {

	this->sig = n;

}
