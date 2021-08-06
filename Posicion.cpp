/*
 * Posicion.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Posicion.h"
#include <iostream>

	Posicion::Posicion() {

		this->ocupado = false;

		this->ficha = ' ';

		this->x = 0;

		this->y = 0;

		this->z = 0;
	}


	bool Posicion::estaOcupado () {

		return (this->ocupado);

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

		return this->vecinos[x + 1][y + 1][z + 1];

	}

	void Posicion::setVecino(Posicion* posicion, int x, int y, int z){

		if (x == 0 && y == 0 && z == 0){

			return;

		}

		this->vecinos[x + 1][y+ 1][z + 1] = posicion;

	}

	bool Posicion::tieneLaMismaFicha (Posicion* posicionAComparar){

		return (this->queFicha() == posicionAComparar->queFicha());

	}

	char Posicion::queFicha() {

		return (this->ficha);
	}


	void Posicion::ocupar (char tipoFicha) {

		if (!this->ocupado) {

			this->ficha = tipoFicha;

			this->ocupado = true;

		}
	}

	void Posicion::reiniciarPosicion(){

		this->ocupado = false;
		
		this->ficha = ' ';

		for(int i = -1; i <= 1; i++){

			for(int j = -1; j <= 1; j++){

				for(int k = -1; k <= 1; k++){

					Posicion * vecino = this->getVecino(i, j, k);

					if(vecino != NULL){

						vecino->ocupado = false;
						vecino->ficha = ' ';
					}
				}
			}
		}
	}

	Posicion::~Posicion(){

	}