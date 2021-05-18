/*
 * Tablero.cpp
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "Tablero.h"

#include <iostream>

using namespace std;

Tablero::Tablero() {

	this->largo = 0;

	this->ancho = 0;

	this->profundidad = 0;

	this->tablero = NULL;

}

void Tablero::inicilizaTablero(int l, int a, int p) {

		this->largo = l;

		this->ancho = a;

		this->profundidad = p;

		this->tablero = new Posicion **[largo];

		for (int i = 0; i < largo; i++) {

			this->tablero [i] = new Posicion *[ancho];

			for (int j = 0; j < ancho; j++) {

				this->tablero [i][j] = new Posicion [profundidad];

			}
		}

		char r = tablero [1][1][3].queFicha();

		cout << r << endl;

}

Tablero::~Tablero() {

	for (int i = 0; i < largo; i++) {

		for (int j = 0; j < ancho; j++) {

			delete[] tablero[i][j];
		}

	delete[] tablero [i];

	}

	delete[] tablero;

}


