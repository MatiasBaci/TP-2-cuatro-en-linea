
#include "TP2.h"

#include "Jugadores.h"

#include "Posicion.h"

#include "MazoDeCartas.h"

#include <iostream>

#include <string>

using namespace std;

TP2::TP2() {

	this->largo_Y = 10;

	this->ancho_X = 10;

	this->profundidad_Z = 10;

	this->cantidadDeFichasIniciales = 50;

	this->cantidadFichasEnLinea = 4;

    this->cantidadDeJugadores = 2;

    this->jugarOrdenInverso = false;

    this->players = NULL;

    this->tableroDeJuego = new Tablero();
}

void TP2::cambiarOrdenDeJuego (){

	if(!this->jugarOrdenInverso){

		this->jugarOrdenInverso = true;

	} else {

		this->jugarOrdenInverso = false;
	}
}

bool TP2::getOrdenDeJuego (){

	return this->jugarOrdenInverso;
}

void TP2::setLargo () {

	int l;

	do {

		std::cout << "Ingrese el largo del tableroDeJuego (entre 5 y 10): ";

		std::cin >> l;

		std::cout << std::endl;

	} while ((l < 5) || (l > 10));

	this->largo_Y = l;
}

void TP2::setAncho () {

	int a;

	do {

		std::cout << "Ingrese el ancho del tableroDeJuego (entre 5 y 10): ";

		std::cin >> a;

		std::cout << std::endl;

	} while (a < 5 || a > 10);

	this->ancho_X = a;
}

void TP2::setProfundidad () {

	int p;

	do {

		std::cout << "Ingrese la profundidad del tableroDeJuego (entre 5 y 10): ";

		std::cin >> p;

		std::cout << std::endl;

	} while (p < 5 || p > 10);

	this->profundidad_Z = p;

}

void TP2::setCantidadDeFichasIniciales() {

int cantFichas;

do {

	std::cout << "Ingrese la cantidad de fichas iniciales (entre 10 y 100): ";

	std::cin >> cantFichas;

	std::cout << std::endl;

} while (cantFichas < 10 || cantFichas > 100);

this->cantidadDeFichasIniciales = cantFichas;

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


Tablero* TP2::getTablero() {

	return (this->tableroDeJuego);

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

void TP2::setJugadores() {

	Jugadores* jugadores = new Jugadores();

	for (int i = 0; i < this->getCantidadDeJugadores(); i++) {

		jugadores->altaDeUnJugador(this->getCantidadDeFichasIniciales());
	}

	this->players = jugadores;
}

int TP2::getCantidadDeFichasIniciales (){

	return this->cantidadDeFichasIniciales;
}

Posicion* TP2::jugar(){

	return (this->ubicarFicha(this->getTablero(), this->players->getListaDeJugadores(), this->solicitarJugada(this->players->getListaDeJugadores(), this->tableroDeJuego)));
}

Posicion* TP2::ubicarFicha (Tablero* tablero, Jugador* jugadorDeTurno, Posicion* posicionSeleccionada){

	int y = this->getLargo() - 1;
	bool encontrado = false;
	while(y > 0 && !encontrado) {

		if(tablero->buscarPosicion(posicionSeleccionada->getX(), y, posicionSeleccionada->getZ(), tablero->getTablero())->estaOcupado()){
			y--;
		}
		else{
			encontrado = true;
		}

	}
	tablero->buscarPosicion(posicionSeleccionada->getX(), y, posicionSeleccionada->getZ(), tablero->getTablero())->ocupar(jugadorDeTurno->getFicha());

	jugadorDeTurno->setFichasRestantes(-1);

	return tablero->buscarPosicion(posicionSeleccionada->getX(), y, posicionSeleccionada->getZ(), tablero->getTablero());

}

Posicion* TP2::solicitarJugada (Jugador* jugadorDeTurno, Tablero* tablero) {

	int xSeleccionada, zSeleccionada;

	bool hayLugar;

	std::cout << std::endl << "Jugador " << jugadorDeTurno->getNombre() << endl << "Cantidad de fichas: " << jugadorDeTurno->getFichasRestantes() << endl << "Coordenada X : " << std::endl;

	std::cin >> xSeleccionada;

	while(xSeleccionada > getTablero()->getAncho() || xSeleccionada < 0){
		
		cout << "Posicion fuera de limites. Vuelva a seleccionar su coordenada X (0 a " << ancho_X  - 1 << ")" << endl;
		cin >> xSeleccionada;
	}

	std::cout << std::endl << "Coordenada Z : " << std::endl;

	std::cin >> zSeleccionada;

	while(zSeleccionada > getTablero()->getProfundidad() || zSeleccionada < 0){
		
		cout << "Posicion fuera de limites. Vuelva a seleccionar su coordenada Z (0 a" << profundidad_Z - 1 << ")" << endl;
		cin >> zSeleccionada;
	}

	hayLugar = tablero->posicionDisponible (xSeleccionada, zSeleccionada);

	while ( !hayLugar ) {

		std::cout << "Fila llena. Seleccione otra! ";

		std::cin >> xSeleccionada;

		std::cout << std::endl << " Coordenada Z : " << std::endl;

		std::cin >> zSeleccionada;

		hayLugar = tablero->posicionDisponible (xSeleccionada, zSeleccionada);

	}

	return (tablero->buscarPosicion(xSeleccionada, 0, zSeleccionada, tablero->getTablero()));
}

MazoDeCartas* TP2::crearMazoDeCartas(){

	MazoDeCartas* mazo = new MazoDeCartas();

	for (int i = 0; i < 100; i++) {

		mazo->agregarUnaCarta();
	}

	return mazo;
}

void TP2::efectuarCarta(int carta){

	this->getJugadores()->getListaDeJugadores()->bajaDeUnaCarta(carta);

	switch (carta){

		case 1: this->getJugadores()->avanzaUnJugador(this->getOrdenDeJuego());

			this->getJugadores()->avanzaUnJugador(this->getOrdenDeJuego());

			break;

		case 2:

			break;

		case 3: this->getJugadores()->sacar5Fichas(this->getJugadores()->getListaDeJugadores());

			this->getJugadores()->avanzaUnJugador(this->getOrdenDeJuego());

			break;

		case 4: this->cambiarOrdenDeJuego();

			this->getJugadores()->avanzaUnJugador(this->getOrdenDeJuego());
			    	        
            break;

		case 7: this->getJugadores()->avanzaUnJugador(this->getOrdenDeJuego());

			break;

	}
}

void TP2::reiniciarJuego(){

	this->getJugadores()->reiniciarJugadores(this->cantidadDeFichasIniciales);
	this->getTablero()->reiniciarTablero();
}