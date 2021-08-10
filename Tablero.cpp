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

	this->ancho = 0;

	this->largo = 0;

	this->profundidad = 0;

	this->slice.SetSize(10, 10);

	this->slice.SetBitDepth(8);
}

void Tablero::inicializaTablero(int x, int y, int z) {

	this->largo = y;

	this->ancho = x;

	this->profundidad = z;

	this->slice.SetSize(x*30, z*30);

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

		this->tablero->agregar(nivel2);

	}
	this->inicializarVecinos();
}

void Tablero::inicializarVecinos(){

	this->tablero->iniciarCursor();
	int tableroActual = 0, filaActual = 0, columnaActual = 0;
	while(this->tablero->avanzarCursor()) {
		tableroActual++;
		Lista<Lista<Posicion*>*>* fila = this->tablero->obtenerCursor();

		fila->iniciarCursor();

		while(fila->avanzarCursor()){
			filaActual++;
			Lista<Posicion*>* columna = fila->obtenerCursor();

			columna->iniciarCursor();

			while(columna->avanzarCursor()) {
				columnaActual++;
				Posicion* posicion = columna->obtenerCursor();

				for(int i = -1; i <= 1; i++){

					for(int j = -1; j <= 1; j++){

						for(int k = -1; k <= 1; k++){
							
							Posicion* posicionVecina = this->buscarPosicion(posicion->getX() + i, posicion->getY() + j, posicion->getZ() + k, this->tablero);
							posicion->setVecino(posicionVecina, i, j, k);

							tablero->setCursor(tableroActual);
							fila->setCursor(filaActual);
							columna->setCursor(columnaActual);
						}
					}
				}
			}
			columnaActual = 0;
		}
		filaActual = 0;
	}
	tableroActual = 0;
}

Posicion* Tablero::buscarPosicion (int x, int y, int z, Lista<Lista<Lista<Posicion*>*>*>* tableroAux) {

	Posicion* posicionBuscada = NULL;

	if ((x >= 0) && ( y >= 0 ) && (z >= 0)){

		tableroAux->iniciarCursor();

		while((tableroAux->avanzarCursor()) && posicionBuscada == NULL) {
		
			Lista<Lista<Posicion*>*>* fila = tableroAux->obtenerCursor();

			fila->iniciarCursor();

			while((fila->avanzarCursor()) && posicionBuscada == NULL) {

				Lista<Posicion*>* columna = fila->obtenerCursor();
				columna->iniciarCursor();

				while((columna->avanzarCursor()) && posicionBuscada == NULL) {

					Posicion* posicion = columna->obtenerCursor();

					if((x == posicion->getX()) && (y == posicion->getY()) && (z == posicion->getZ())) {

						posicionBuscada = posicion;
					}
				}
			}
		}
	}
 	return posicionBuscada;
}

bool Tablero::posicionDisponible (int xSeleccionada, int zSeleccionada){

	if (!(this->buscarPosicion(xSeleccionada, 0, zSeleccionada, this->tablero)->estaOcupado())){

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
				while(vecino != NULL && vecino->tieneLaMismaFicha(ultimaJugada)){

					cantidadEnLinea[i + 1][j + 1][k + 1]++;

					vecino = vecino->getVecino(i, j, k);
				}
			}
		}
	}

	for(int i = 0; i < 3; i++){

		for(int j = 0; j < 3; j++){

			for(int k = 0; k < 3; k++){

				if(((cantidadEnLinea[i][j][k] + cantidadEnLinea[k][j][i]) - 1) >= cantidadDeFichasParaGanar){

					gano = true;
				}
			}
		}
	}

	return gano;
}

void Tablero::reiniciarTablero(){

	tablero->iniciarCursor();

	while(tablero->avanzarCursor()) {

		Lista < Lista < Posicion * > * > * fila = tablero->obtenerCursor();

		fila->iniciarCursor();

		while(fila->avanzarCursor()){

			Lista < Posicion * > * columna = fila->obtenerCursor();

			columna->iniciarCursor();

			while(columna->avanzarCursor()){

				Posicion * posicion = columna->obtenerCursor();

				posicion->reiniciarPosicion();
				
			}
		}
	}
}

Tablero::~Tablero() {

	if (this->tablero != NULL){

		tablero->iniciarCursor();

		while(tablero->avanzarCursor()) {

			Lista<Lista<Posicion*>*>* fila = tablero->obtenerCursor();

			fila->iniciarCursor();

			while(fila->avanzarCursor()) {

				Lista<Posicion*>* columna = fila->obtenerCursor();

				columna->iniciarCursor();

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

int Tablero::getAncho(){

	return this->ancho;
}

int Tablero::getLargo(){

	return this->largo;
}

int Tablero::getProfundidad(){

	return this->profundidad;
}

void Tablero::generarBMP() {

    this->slice.WriteToFile("Tablero_visto_desde_arriba.bmp");
}

void Tablero::colorearPixel(Posicion* posicion, int x_bmp, int y_bmp, char letra) {

	RGBApixel pixel;
	pixel.Alpha = 0;
	pixel.Red = 0;
	pixel.Green = 0;
	pixel.Blue = 0;

	if (letra == 'R' || letra == 'r') {
		pixel.Red = 255;
	}
	else if (letra == 'G' || letra == 'g') {
		pixel.Green = 255;
	}
	else if (letra == 'B' || letra == 'b') {
		pixel.Blue = 255;
	}
	else if (letra == 'P' || letra == 'p') {
		pixel.Blue = 255;
		pixel.Red = 255;
	}
	else if (letra == 'O' || letra == 'o') {
		pixel.Green = 128;
		pixel.Red = 255;
	}
	else if (letra == 'V' || letra == 'v') {
		pixel.Blue = 153;
		pixel.Red = 76;
	}

	for (int i = x_bmp*30; i < x_bmp*30+30; i++) {
		for (int j = y_bmp*30; j < y_bmp*30+30; j++) {
		
			this->slice.SetPixel(i, j, pixel);
		}
	}
}