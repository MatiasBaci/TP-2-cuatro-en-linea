/*
 * Tablero2.h
 *
 *  Created on: Jun 20, 2021
 *      Author: algo2
 */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

#include "Posicion.h"

#include "Lista.h"

#include "Nodo.h"

class Tablero {

	private:

		Lista<Lista<Lista<Posicion*>*>*>* tablero;

	public:

		/*
		 * pre: No tiene.
		 * post: Devuelve un puntero a un tablero, sin dimensiones
		 */
		Tablero ();

		/*
		 * pre: Existe el puntero al tablero
		 * post: Genera un tablero con las dimensiones dadas y lo iniciliza.
		 */
		void inicializaTablero (int x, int y, int z);

		/*
		 * pre: Recibe una posicion valida en el tablero
		 * post: Devuelve un puntero a esa posicion
		 */
		Posicion* buscarPosicion (int x, int y, int z,Lista<Lista<Lista<Posicion*>*>*>* );

		/*
		 * pre: Recibe la ultima jugada, la cantidad necesaria de fichas en linea para ganar
		 * post: Indica si hay un ganador
		 */
		bool hayGanador (Posicion* ultimaJugada, int cantidadDeFichasParaGanar);

		/*
		 * pre: Recibe dos coordenadas (X y Z) validas.
		 * post: Devuleve un bool que indica si hay lugar en esa columna
		 */
		bool posicionDisponible (int, int);

		/*
		 * pre: Existe el tablero
		 * post: Devuelve un puntero al tablero
		 */
		Lista<Lista<Lista<Posicion*>*>*>* getTablero();

		void inicializarVecinos();
		/*
		 * pre : Existe el tablero
		 * pos: Destruye el tablero
		 */
		~Tablero ();

};




#endif /* SRC_TABLERO_H_ */
