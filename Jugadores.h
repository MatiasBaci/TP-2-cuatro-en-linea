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
		 * pre : Existe la lista (puntero).
		 * pos: Da de alta un jugador al final de la lista.
		 */
		void alta ();

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
