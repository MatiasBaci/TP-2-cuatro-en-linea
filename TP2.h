/*
 * TP2.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_TP2_H_
#define SRC_TP2_H_

#include <string>

#include "Jugadores.h"

#include "Lista.h"

#include "Jugador.h"

#include "Tablero.h"

class TP2 {

	private:

		int largo_Y;

		int ancho_X;

		int profundidad_Z;

		int cantidadDeFichasIniciales;

		int cantidadFichasEnLinea;

		int cantidadDeJugadores;

		bool jugarOrdenInverso;

		Tablero* tableroDeJuego;

		Jugadores* players;

	public:

		/*
		 * pre:
		 * pos: Genera un objeto TP
		 */
		TP2();

		/*
		 * pre:
		 * pos: Carga el largo del tableroDeJuego entre 5 y 10 lugares
		 */
		void setLargo ();

		/*
		 * pre:
		 * pos: Carga el ancho del tableroDeJuego entre 5 y 10 lugares
		 */
		void setAncho ();



		/*
		 * pre:
		 * pos: Carga la profundidad del tableroDeJuego entre 5 y 10 lugares
		 */
		void setProfundidad ();

		/*
		 * pre:
		 * pos: Carga cantidad de fichas iniciales de cada jugador entre 20 y 100.
		 */
		void setCantidadDeFichasIniciales ();


		/*
		 * pre:
		 * pos: Carga la cantidad de fichas que hay que alinear para ganar (minimo 3 y maximo dos menos que la menor dimension)
		 */
		void setCantidadFichasEnLinea ();

		/*
		 * pre:
		 * pos: Carga la cantidad de jugadores, minimo 2 y maximo 5
		 */
		void setCantidadDeJugadores ();

		/*
		 * pre: No tiene
		 * pos: Da de alta a los jugadores
		 */
		void setJugadores ();

		/*
		 * pre: No tiene
		 * post: Cambia el orden de juego
		 */
		void cambiarOrdenDeJuego ();

		/*
		 * pre: No tiene
		 * post: Devuelve el orden de juego, directo o inverso
		 */
		bool getOrdenDeJuego ();

		/*
		 * pre:
		 * pos: Devuelve el largo del tableroDeJuego
		 */
		int getLargo ();

		/*
		 * pre:
		 * pos: Devuelve el ancho del tableroDeJuego
		 */
		int getAncho ();

		/*
		 * pre:
		 * pos: Devuelve la profundidad del tableroDeJuego
		 */
		int getProfundidad ();

		/*
		 * pre:
		 * pos: Devuelve la cantidad de fichas que hay que alinear para ganar
		 */
		int getCantidadFichasEnLinea ();

		/*
		 * pre:
		 * pos: Carga cantidad de fichas iniciales de cada jugador entre 20 y 100.
		 */
		int getCantidadDeFichasIniciales ();


		/*
		 * pre:
		 * pos: Devuelve la cantidad de jugadores
		 */
		int getCantidadDeJugadores ();

		/*
		 * pre:
		 * pos: Devuelve un puntero al tableroDeJuego
		 */
		Tablero* getTablero ();

		/*
		 * pre:
		 * pos: Devuelve un puntero a la lista de jugadores
		 */
		Jugadores* getJugadores ();

		/*
		 * pre:
		 * post:
		 */
		Posicion* jugar ();

		/*
		 * pre: Existe tablero y jugadores
		 * post: Solicita una jugada y la valida
		 */
		Posicion* solicitarJugada (Jugador*, Tablero*);

		/*
		 * pre: La jugada es valida
		 * post: Ubica la ficha en la posicion
		 */
		Posicion* ubicarFicha (Tablero*, Jugador*, Posicion*);

		/*
		 * pre: No tiene
		 * post: Crea el mazo de cartas
		 */
		MazoDeCartas* crearMazoDeCartas();
		
		/*
		 * pre: El numero de carta debe ser valido.
		 * post: Efectua la carta que se jugo ese turno.
		 */

		void efectuarCarta(int);
};




#endif /* SRC_TP2_H_ */
