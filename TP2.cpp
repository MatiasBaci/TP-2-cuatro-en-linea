
#include "TP2.h"

#include "Jugadores.h"

#include "Posicion.h"

#include <iostream>

#include <string>

using namespace std;

TP2::TP2() {

	this->largo_Y = 10;

	this->ancho_X = 10;

	this->profundidad_Z = 10;

	this->cantidadDeFichas = 50;

	this->cantidadFichasEnLinea = 4;

    this->cantidadDeJugadores = 2;

    this->players = NULL;

    this->tablero =NULL;
}



void TP2::setLargo () {

	int l;

	do {

		std::cout << "Ingrese el largo del tablero (entre 5 y 10): ";

		std::cin >> l;

		std::cout << std::endl;

	} while ((l < 5) || (l > 10));

	this->largo_Y = l;
}

void TP2::setAncho () {

	int a;

	do {

		std::cout << "Ingrese el ancho del tablero (entre 5 y 10): ";

		std::cin >> a;

		std::cout << std::endl;

	} while (a < 5 || a > 10);

	this->ancho_X = a;
}

void TP2::setProfundidad () {

	int p;

	do {

		std::cout << "Ingrese la profundidad del tablero (entre 5 y 10): ";

		std::cin >> p;

		std::cout << std::endl;

	} while (p < 5 || p > 10);

	this->profundidad_Z = p;

}

void TP2::setCantidadDeFichas () {

int cantFichas;

do {

	std::cout << "Ingrese la cantidad de fichas iniciales (entre 10 y 100): ";

	std::cin >> cantFichas;

	std::cout << std::endl;

} while (cantFichas < 10 || cantFichas > 100);

this->cantidadDeFichas = cantFichas;

}

void TP2::setCantidadFichasEnLinea() {

	int cantFichas;

	do {

		std::cout << "Ingrese la cantidad de fichas en linea necesarias para ganar (entre 3 y 8) : ";

		std::cin >> cantFichas;

		std::cout << std::endl;

	} while (cantFichas < 3 || cantFichas > 8);

	this->cantidadFichasEnLinea = cantFichas;

}


void TP2::setCantidadDeJugadores () {

int cantJugadores;

do {

	std::cout << "Ingrese la cantidad de jugadores (entre 2 y 5): ";

	std::cin >> cantJugadores;

	std::cout << std::endl;

} while (cantJugadores < 2 || cantJugadores > 5);

this->cantidadDeJugadores = cantJugadores;

}


/*void TP2::inicializarMatriz() {

	this->tablero = new Posicion **[largo_Y];

	for (int i = 0; i < largo_Y; i++) {

		this->tablero [i] = new Posicion *[ancho_X];

		for (int j = 0; j < ancho_X; j++) {

			this->tablero [i][j] = new Posicion [profundidad_Z];

		}
	}

	char r = tablero [1][1][3].queFicha();

	cout << r << endl;


}*/

Tablero* TP2::getTablero() {

	return (this->tablero);

}

int TP2::getLargo () {

	return (this->largo_Y);

}

int TP2::getAncho () {

	return (this->ancho_X);

}

int TP2::getProfundidad () {

	return (this->profundidad_Z);

}

int TP2::getCantidadFichasEnLinea () {

	return (this->cantidadFichasEnLinea);

}

int TP2::getCantidadDeJugadores () {

	return (this->cantidadDeJugadores);

}

Jugadores* TP2::getJugadores() {

	return (this->players);

}

void TP2::setJugadores(Jugadores *play) {

	this->players = play;

}






