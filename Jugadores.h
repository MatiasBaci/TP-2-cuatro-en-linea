/*
 * Jugadores.h
 *
 *  Created on: May 1, 2021
 *      Author: algo2
 */

#ifndef SRC_JUGADORES_H_
#define SRC_JUGADORES_H_

#include "Jugador.h"

class Jugadores {

	private:

		int cantidadDeJugadores;

		Jugador *listaDeJugadores;

		Jugador *primero, *ultimo;

	public:

		/*
		 * pre: No tiene
		 * pos: Constructor de la lista doblemente enlazada que contiene los jugadores.
		 */
		Jugadores();

		/*
		 * pre :Existe por lo menos un jugador
		 * pos : Devuelve un puntero al jugador
		 */
		Jugador* getListaDeJugadores ();

		/*
		* pre :Existe por lo menos un jugador
		* pos : Devuelve un puntero al primer jugador
		*/
		Jugador* getJugadorN (int n);

		/*
		 * pre: Existe por lo menos un jugador
		 * post: Devuelve la cantidad de jugadores
		 */
		int getCantidadDeJugadores();

		/*
		 * pre : Existe la lista (puntero).
		 * pos: Da de alta un jugador al final de la lista.
		 */
		void altaDeUnJugador (int);

		/*
		 * pre : Existe la lista (puntero).
		 * pos: Avanza un jugador en la lista..
		 */
		Jugador* avanzaUnJugador (bool);

		/*
		 * pre: Existe la lista de jugadores
		 * post: Le saca cinco fichas a todos los jugadores, menos al que se da como parametro
		 */
		void sacar5Fichas(Jugador*);

		bool fichaRepetida(char ficha);
		/*
		 * pre: Existe la lista
		 * pos: Muestra por consola los nombres de los jugadores del primero al ultimo
		 */
		void emitePU () const;

		/*
		 * pre: Existe la lista
		 * pos: Muestra por consola los nombres de los jugadores del ultimo al primero
		 */

		void emiteUP () const;

		/*
		 * pre: Existe la lista
		 * pos: Destruye la lista
		 */
		~Jugadores();

};






#endif /* SRC_JUGADORES_H_ */
