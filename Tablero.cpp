/*
 * Tablero2.cpp
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

	Lista<Lista<Lista<Posicion*>*>*>* tableroAux = NULL;

	tableroAux = new Lista<Lista<Lista<Posicion*>*>*>();

	for (int i = 0; i < x; i++) {

		Lista<Lista<Posicion*>*>* nivel2 = new Lista<Lista<Posicion*>*>();

		for (int j = 0; j < y; j++) {

			Lista<Posicion*>* nivel3 = new Lista<Posicion*>();

			for (int k = 0; k < z; k++){

				Posicion* posicion = new Posicion();

				posicion->setX(i);

				posicion->setY(j);

				posicion->setZ(k);

				nivel3->agregar(posicion);
			}

			nivel2->agregar(nivel3);
		}

		tableroAux->agregar(nivel2);

	}

	this->tablero = tableroAux;

	this->tablero->iniciarCursor();

	while(this->tablero->avanzarCursor()) {

		Lista<Lista<Posicion*>*>* fila = this->tablero->obtenerCursor();

		fila->iniciarCursor();

		while(fila->avanzarCursor()){

			Lista<Posicion*>* columna = fila->obtenerCursor();

			columna->iniciarCursor();

			while(columna->avanzarCursor()) {

				//Lista<Posicion*>* columnaAux = columna;

				do{

				Posicion* posicion = columna->obtenerCursor();

				cout << " Voy a buscar " << posicion->getX() << posicion->getY() << posicion->getZ() << endl;

				int parar;

				cin >> parar;

				for(int i = -1; i <= 1; i++){

					for(int j = -1; j <= 1; j++){

						for(int k = -1; k <= 1; k++){

							cout << "Antes de Avanzar cursor 1 "<< columna->obtenerCursor()->getZ() << endl;

							Posicion* posicionVecina = this->buscarPosicion(posicion->getX() + i,

							posicion->getY() + j, posicion->getZ() + k, this->tablero);

							posicion->setVecino(posicionVecina, i, j, k);

							cout << "Antes de Avanzar cursor 2 "<< columna->obtenerCursor()->getZ() << endl;

						}
					}
				}



				//cout << "Antes de Avanzar cursor "<< columna->obtenerCursor()->getX() << posicion->getY() << posicion->getZ() << endl;

				//columna = columnaAux;

				} while (columna->avanzarCursor() && columna->avanzarCursor() && columna->avanzarCursor());

			}

		}
	}
}

Posicion* Tablero::buscarPosicion (int x, int y, int z, Lista<Lista<Lista<Posicion*>*>*>* tableroAux){


	int contadorDeCasilleros = 0;

	cout << " Esta buscando " << x << y << z << endl;

	Posicion* posicionBuscada = NULL;

	if ((0 <= x) && ( 0 <= y ) && (0 <= z)){

		tableroAux->iniciarCursor();

		while((tableroAux->avanzarCursor()) &&

				posicionBuscada == NULL) {

			cout << "LLega a 61 " << endl;

			Lista<Lista<Posicion*>*>* fila = tableroAux->obtenerCursor();

			fila->iniciarCursor();

			while((fila->avanzarCursor()) &&

					posicionBuscada == NULL) {

				Lista<Posicion*>* columna = fila->obtenerCursor();

				columna->iniciarCursor();

				while((columna->avanzarCursor()) &&

						posicionBuscada == NULL) {

					cout << "LLega a 62 " << endl;

					Posicion* posicion = columna->obtenerCursor();

					cout << "LLega a 67 " << posicion->getX() << endl;

					cout << "LLega a 67 " << posicion->getY() << endl;

					cout << "LLega a 67 " << posicion->getZ() << endl;

					cout << " Esta buscando x =  " << x << " y = "<< y << " z = " << z << endl;

					if((x == posicion->getX()) &&

							(y == posicion->getY()) &&

							(z == posicion->getZ())) {

						cout << "LLega a 63 " << endl;

						posicionBuscada = posicion;
					}
				}
			}
		}

		cout << "LLega a 69 " << endl;

		cout << posicionBuscada->getX() << "esaa" << endl;

		contadorDeCasilleros++;

		cout << contadorDeCasilleros << endl;

	}

	return posicionBuscada;
}

bool Tablero::posicionDisponible (int xSeleccionada, int zSeleccionada){

	cout << xSeleccionada << zSeleccionada << endl;

	cout << this->buscarPosicion(xSeleccionada, 0, zSeleccionada, this->tablero)->getX() << endl;

	if (!(this->buscarPosicion(xSeleccionada, 0, zSeleccionada, this->tablero)->estaOcupado())){

		cout << "999" << endl;

		return true;
	}

	return false;
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

Lista<Lista<Lista<Posicion*>*>*>* Tablero::getTablero(){

	return this->tablero;

}
