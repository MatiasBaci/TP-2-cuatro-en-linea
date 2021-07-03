/*
 * Tablero.cpp
 *
 *  Created on: Jun 20, 2021
 *      Author: algo2
 */


//#include "Nodo.h"

#include "Posicion.h"

#include <iostream>

#include "Tablero.h"

using namespace std;

Tablero::Tablero() {

	this->tablero = NULL;

	this->tablero = new Lista<Lista<Lista<Posicion*>*>*>();

}

void Tablero::inicializaTablero(int x, int y, int z) {

	Lista<Lista<Lista<Posicion * > * > * > * tableroAux = NULL;
	tableroAux = new Lista<Lista<Lista<Posicion * > * > * > ();
	for (int i = 0; i < x; i++) {

		Lista<Lista<Posicion*>*>* nivel2 = new Lista<Lista<Posicion*>*>();

		for (int j = 0; j < y; j++) {

			Lista<Posicion*>* nivel3 = new Lista<Posicion*>();

			for (int k = 0; k < z; k++){

				Posicion* posicion = new Posicion();

				posicion->setX(x);

				posicion->setY(y);

				posicion->setZ(z);

				nivel3->agregar(posicion);
			}

			nivel2->agregar(nivel3);
		}

		tableroAux->agregar(nivel2);

	}

	tableroAux->iniciarCursor();

	while(tableroAux->avanzarCursor()) {

		Lista<Lista<Posicion*>*>* fila = tableroAux->obtenerCursor();

		fila->iniciarCursor();

		while(fila->avanzarCursor()) {

			Lista<Posicion*>* columna = fila->obtenerCursor();

			columna->iniciarCursor();
			while(columna->avanzarCursor()) {

				Posicion* posicion = columna->obtenerCursor();

				for(int i = -1; i <= 1; i++){

					for(int j = -1; j <= 1; j++){

						for(int k = -1; k <= 1; k++){

							Posicion* posicionVecina = this->buscarPosicion(posicion->getX() + i, posicion->getY() + j, posicion->getZ() + k);
							posicion->setVecino(posicionVecina, i, j, k);

						}
					}
				}
			}
		}
	}
	this->tablero = tableroAux;
}

Posicion* Tablero::buscarPosicion (int x, int y, int z){

	Posicion* posicionBuscada = NULL;

	tablero->iniciarCursor();

	while((tablero->avanzarCursor()) && posicionBuscada != NULL) {

		Lista<Lista<Posicion*>*>* fila = tablero->obtenerCursor();

		fila->iniciarCursor();

		while((fila->avanzarCursor()) && posicionBuscada != NULL) {

			Lista<Posicion*>* columna = fila->obtenerCursor();

			columna->iniciarCursor();

			while((columna->avanzarCursor()) && posicionBuscada != NULL) {

				Posicion* posicion = columna->obtenerCursor();

				if((posicion->getX() == x) &&
				   (posicion->getY() == y) &&
				   (posicion->getZ() == z)) {

					posicionBuscada = posicion;
				}
			}
		}
	}

	return posicionBuscada;
}

bool Tablero::hayGanador (Posicion* ultimaJugada, int cantidadDeFichasParaGanar) {

	bool gano = false;

	int cantidadEnLinea[3][3][3];

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			for(int k = 0; k < 3; k++){

				cantidadEnLinea[i][j][k] = 0;
			}
		}
	}

	for(int i = -1; i <= 1; i++){

		for(int j = -1; j <= 1; j++){

			for(int k = -1; k <= 1; k++){

				Posicion* vecino = ultimaJugada->getVecino(i, j, k);

				while(vecino->tieneLaMismaFicha(ultimaJugada)){

					cantidadEnLinea[i + 1][j + 1][k + 1]++;

					vecino = vecino->getVecino(i, j, k);
				}
			}
		}
	}

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			for(int k = 0; k < 3; k++){

				if(((cantidadEnLinea[i][j][k] + cantidadEnLinea[k][j][i]) + 1) >= cantidadDeFichasParaGanar){

					gano = true;
				}
			}
		}
	}

	return gano;
}


bool colocarFicha(char ficha, int x, int y, int z) {

	
}


Tablero::~Tablero() {

	if (this->tablero != NULL){

		tablero->iniciarCursor();

		while(tablero->avanzarCursor()) {

			Lista<Lista<Posicion*>*>* fila = tablero->obtenerCursor();

			fila->iniciarCursor();

			while(fila->avanzarCursor()) {

				Lista<Posicion*>* columna = fila->obtenerCursor();

				columna->obtenerCursor();

				while(columna->avanzarCursor()) {

					Posicion* posicion = columna->obtenerCursor();

					delete posicion;
				}

				delete columna;
			}

			delete fila;
		}

		delete tablero;
	}
}

