/*
 * Jugador.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include <string>

#include "MazoDeCartas.h"

#include "Cartas del Jugador.h"

class Jugador {

	private:

		std::string nombre;

		char ficha;

		unsigned int fichasRestantes;

		unsigned int juegosGanados;

		int cantidadDeCartas;

		Carta* misCartas;

		Jugador *sig;

		Jugador *ant;

	public:

		/*
		 * pre: No tiene
		 * pos: Crea un jugador sin argumentos
		 */
		Jugador ();

		/*
		* pre: No tiene
		* pos: Crea un jugador.
		*/
		Jugador (std::string, unsigned int, char);

		/*
		 * post: Destructor
		 */
		~Jugador ();

		/*
		 * pre:
		 * pos: Avanza un jugador.
		 */
		Jugador* getSig();

		/*
		 * pre: Existe un jugador
		 * pos: Devuelve un puntero al jugador anterior
		 */
		Jugador* getAnt();

		/*
		 * pre:
		 * pos: Hace que un jugador apunte al siguiente jugador.
		 */
		void setSig (Jugador*);

		/*
		 * pre: Existe un jugador
		 * pos: Agrega una carta al jugador
		 */
		void altaDeUnaCarta (MazoDeCartas*);

		/*
		 * pre: Existe el jugador
		 * pos: Emite todas las cartas del jugador
		 */
		void emite () const;

		/*
		 * pre:
		 * pos: Hace que un jugador apunte al jugador anterior.
		 */
		void setAnt (Jugador*);

		/*
		 * pre: Existe el jugador
		 * pos: Devuelve el nombre del jugador.
		 */
		std::string getNombre ();

		/*
		 * pre: Existe jugador
		 * pos: Devuelve la ficha del jugador
		 */
		char getFicha ();

		/*
		 * pre:
		 * pos: Devuelve las fichas que le quedan al jugador
		 */
		unsigned int getFichasRestantes ();

		/*'
		 * pre:
		 * pos: Devuelve los juegos ganados por el jugador.
		 */
		unsigned int getJuegosGanados ();

		/*
		 * pre: Recibe la variacion en la cantidad de fichas.
		 * pos: Actualiza las fichas que le quedan al jugador.
		 */
		void setFichasRestantes (int);

		/*
		 * pre: Suma un juego ganado al jugador
		 * pos: Actualiza juegos ganados por el jugador.
		 */
		void setJuegosGanados ();


};






#endif /* SRC_JUGADOR_H_ */
