/*
 * Jugador.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include <string>

class Jugador {

	private:

		std::string nombre;

		char ficha;

		unsigned int fichasRestantes;

		unsigned int juegosGanados;

		int cartas [3];

	public:

		/*
		* pre: No tiene
		* pos: Crea un jugador.
		*/
		Jugador (std::string name, unsigned int fichasIniciales, char fficha);



		/*
		 * pre:
		 * pos: Devuelve el nombre del jugador.
		 */
		std::string getNombre ();

		/*
		 * pre:
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
		 * pre:
		 * pos: Actualiza las fichas que le quedan al jugador.
		 */
		void setFichasRestantes ();

		/*
		 * pre:
		 * pos: Actualiza juegos ganados por el jugador.
		 */
		void setJuegosGanados ();


};






#endif /* SRC_JUGADOR_H_ */
