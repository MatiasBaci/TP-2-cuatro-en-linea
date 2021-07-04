/*
 * Cartas del Jugador.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_CARTAS_DEL_JUGADOR_H_
#define SRC_CARTAS_DEL_JUGADOR_H_

#include "Carta.h"

class cartasDelJugador {

	private:

		int cantidadDeCartas;

		Carta* cartaDelJugador;

	public:

		/*
		 * pre:
		 * pos: Constructor de la lista que contiene las cartas de un determinado jugador.
		 */
		cartasDelJugador();

		/*
		 * pre : Existe la lista (puntero).
		 * pos: Da de alta una carta al final de la lista.
		 */
		void alta ();

		/*
		 * pre: Existe la carta.
		 * pos: Da de baja la carta del jugador.
		 */
		void baja (int);

		/*
		 * pre: Recibe un numero de carta
		 * pos: Indica con un bool si una carta esta entre las que tiene el jugador
		 */
		bool busca (int);

		/*
		 * pre: Existe la lista
		 * pos: Muestra por consola las cartas del jugador
		 */
		void emite () const;

		/*
		 * pre: Existe la lista
		 * pos: Destruye la lista
		 */
		~cartasDelJugador();

};





#endif /* SRC_CARTAS_DEL_JUGADOR_H_ */
