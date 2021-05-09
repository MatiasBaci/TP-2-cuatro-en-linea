/*
 * Posicion.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Posicion.h"


	Posicion::Posicion() {

		ocupado = false;

		ficha = 'X';
	}


	bool Posicion::estaOcupado () {

		return (ocupado);

	}

	char Posicion::queFicha() {

		return (ficha);
	}


	void Posicion::ocupar (char tipoFicha) {

		if (!ocupado) {

			ficha = tipoFicha;

			ocupado = true;

		}
	}


//	Posicion::~Posicion;




