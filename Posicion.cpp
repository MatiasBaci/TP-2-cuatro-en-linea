/*
 * Posicion.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Posicion.h"


	Posicion::Posicion() {

		ocupado = false;

		ficha = ' ';

		x = 0;

		y = 0;

		z = 0;
	}


	bool Posicion::estaOcupado () {

		return (ocupado);

	}

	void Posicion::setX(int ancho) {

		this->x = ancho;
	}

	void Posicion::setY(int alto) {

		this->y = alto;
	}

	void Posicion::setZ(int profundidad) {

		this->z = profundidad;
	}

	int Posicion::getX(){

		return this->x;
	}

	int Posicion::getY(){

		return this->y;
	}

	int Posicion::getZ(){

		return this->z;
	}

	Posicion* Posicion::getVecino(int x, int y, int z) {

		// validar

		return vecinos[x + 1][y + 1][z + 1];

	}

	void Posicion::setVecino(Posicion* posicion, int x, int y, int z){

		if (x == 0 && y == 0 && z == 0){

			return;

		}

		this->vecinos[x + 1][y+ 1][z + 1] = posicion;

	}

	bool Posicion::tieneLaMismaFicha (Posicion* posicionAComparar){

		return (this->getFicha() == posicionAComparar->getFicha());

	}

	char Posicion::getFicha() {

		return (ficha);
	}


	void Posicion::ocupar (char tipoFicha) {

		if (!ocupado) {

			ficha = tipoFicha;

			ocupado = true;

		}
	}

	Posicion::~Posicion(){

	}




