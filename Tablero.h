/*
 * Tablero.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

#include "Posicion.h"

class Tablero {

	private:

		int largo;

		int ancho;

		int profundidad;

		Posicion ***tablero;

	public:

		/*
		 * pre: No tiene.
		 * pos: Devuelve un puntero a un tablero, sin dimensiones
		 */
		Tablero ();

		/*
		 * pre: Existe el puntero al tablero
		 * pos: Genera un tablero con las dimensiones dadas y lo iniciliza.
		 */
		void inicilizaTablero (int l, int a, int p);

};




#endif /* SRC_TABLERO_H_ */
