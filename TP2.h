/*
 * TP2.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_TP2_H_
#define SRC_TP2_H_

#include <string>

class TP2 {

	private:

		int largo;

		int ancho;

		int profundidad;

		int cantidadDeFichas;

		int cantidadFichasEnLinea;

		int cantidadDeJugadores;

		std::string jugadores [5];

	public:

		/*
		 * pre:
		 * pos: Genera un objeto TP
		 */
		TP2();

		/*
		 * pre:
		 * pos: Carga el largo del tablero entre 5 y 10 lugares
		 */
		void setLargo ();

		/*
		 * pre:
		 * pos: Carga el ancho del tablero entre 5 y 10 lugares
		 */
		void setAncho ();

		/*
		 * pre:
		 * pos: Carga la profundidad del tablero entre 5 y 10 lugares
		 */
		void setProfundidad ();

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
		 * pre:
		 * pos: Carga los nombres de los jugadores
		 */
		void setJugadores ();

		/*
		 * pre:
		 * pos: Devuelve el largo del tablero
		 */
		int getLargo ();

		/*
		 * pre:
		 * pos: Devuelve el ancho del tablero
		 */
		int getAncho ();

		/*
		 * pre:
		 * pos: Devuelve la profundidad del tablero
		 */
		int getProfundidad ();

		/*
		 * pre:
		 * pos: Devuelve la cantidad de fichas que hay que alinear para ganar
		 */
		int getCantidadFichasEnLinea ();

		/*
		 * pre:
		 * pos: Devuelve la cantidad de jugadores
		 */
		int getCantidadDeJugadores ();


};




#endif /* SRC_TP2_H_ */
