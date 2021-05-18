
#include "TP2.h"

#include "Jugadores.h"

#include <iostream>

#include <string>

TP2::TP2() {

	this->largo = 0;

	this->ancho = 0;

	this->profundidad = 0;

	this->cantidadDeFichas = 0;

	this->cantidadFichasEnLinea = 0;

	this->cantidadDeJugadores = 0;

}



void TP2::setLargo () {

	int l;

	do {

		std::cout << "Ingrese el largo del tablero (entre 5 y 10): ";

		std::cin >> l;

		std::cout << std::endl;

	} while ((l < 5) || (l > 10));

	this->largo = l;
}

void TP2::setAncho () {

	int a;

	do {

		std::cout << "Ingrese el ancho del tablero (entre 5 y 10): ";

		std::cin >> a;

		std::cout << std::endl;

	} while (a < 5 || a > 10);

	this->ancho = a;
}

void TP2::setProfundidad () {

	int p;

	do {

		std::cout << "Ingrese la profundidad del tablero (entre 5 y 10): ";

		std::cin >> p;

		std::cout << std::endl;

	} while (p < 5 || p > 10);

	this->profundidad = p;

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

int TP2::getLargo () {

	return (this->largo);

}

int TP2::getAncho () {

	return (this->ancho);

}

int TP2::getProfundidad () {

	return (this->profundidad);

}

int TP2::getCantidadFichasEnLinea () {

	return (this->cantidadFichasEnLinea);

}

int TP2::getCantidadDeJugadores () {

	return (this->cantidadDeJugadores);

}






