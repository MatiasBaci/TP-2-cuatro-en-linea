/*
 * principal.cpp

 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#include "TP2.h"

#include "Interacciones.h"

#include "Posicion.h"

#include "Jugadores.h"

#include "Tablero.h"

#include "Cartas del Jugador.h"

#include "MazoDeCartas.h"

#include "Jugador.h"

#include <string>

#include <iostream>

using namespace std;

int main () {

	presentacion ();

	TP2* codeando21 = new TP2();

	opcionesDeJuego(codeando21);

	MazoDeCartas* mazo = codeando21->crearMazoDeCartas();

	char deseaSeguirJugando = 's';

    bool ganado = false;

	codeando21->getTablero()->inicializaTablero(codeando21->getLargo(), codeando21->getAncho(), codeando21->getProfundidad());

	codeando21->setJugadores();

	Posicion* posicionJugada;

	int cantidadDeJugadoresSalteados = 0;

	while (deseaSeguirJugando == 's'){

		while(cantidadDeJugadoresSalteados < codeando21->getJugadores()->getCantidadDeJugadores() && !ganado) {

			posicionJugada = codeando21->jugar();

            codeando21->getJugadores()->getListaDeJugadores()->agregarPosicionOcupada(posicionJugada);

            if(codeando21->getTablero()->hayGanador(posicionJugada, codeando21->getCantidadFichasEnLinea())){

                cout << "Gano " << codeando21->getJugadores()->getListaDeJugadores()->getNombre() << endl;
				codeando21->getJugadores()->getListaDeJugadores()->setJuegosGanados();
                ganado = true;
            
            }
            else {

                codeando21->getJugadores()->getListaDeJugadores()->altaDeUnaCarta(mazo);

                opcionesDeJugador(codeando21);   

			    if (codeando21->getJugadores()->getListaDeJugadores()->getFichasRestantes() == 0){

				    codeando21->getJugadores()->avanzaUnJugador(codeando21->getOrdenDeJuego());

				    cantidadDeJugadoresSalteados++;
		        }   
            }
	    }
        cout << "Desea seguir jugando s/n : " << endl;

		cin >> deseaSeguirJugando;
	}
	return 0;
}