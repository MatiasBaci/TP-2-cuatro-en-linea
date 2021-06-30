/*
 * MazoDeCartas.cpp
 *
 *  Created on: May 22, 2021
 *      Author: algo2
 */


#include "MazoDeCartas.h"

#include <iostream>

using namespace std;

#define ELEMENTO_NULO 0



MazoDeCartas::MazoDeCartas() {

	this->tope = NULL;

}


bool MazoDeCartas::noTieneCartas() {

	return (this->tope == NULL);

}


void MazoDeCartas::agregarUnaCarta() {

		Carta* nuevoTope = new Carta();

		nuevoTope->setSig(this->tope);

		this->tope = nuevoTope;

}

int MazoDeCartas::sacarUnaCarta() {

	int elemento = ELEMENTO_NULO;

	if (!this->noTieneCartas()) {

		Carta* topeAnterior = this->tope;

		this->tope = topeAnterior->getSig();

		elemento = topeAnterior->getInfo();

		delete topeAnterior;
	}

	return elemento;

}

MazoDeCartas::~MazoDeCartas() {

	while (! this->noTieneCartas()) {

		this->sacarUnaCarta();

	}

}

