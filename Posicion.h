/*
 * Posicion.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_POSICION_H_
#define SRC_POSICION_H_

class Posicion {

	private:

		bool ocupado;

		char ficha;

	public:

	/*
	 * Contructor
	 * Precondicion: No tiene.
	 * Postcondicion: Crea una posicion del tablero y la inicializa.
	 */
		Posicion();

	/*
	 * Precondicion: No tiene.
	 * Postcondicion: Devuelve un bool indicando si esta o no ocupado.
	 */
		bool estaOcupado ();

	/*
	 * Precondicion: No tiene.
	 * Postcondicion: Devuelve la ficha que contiene.
	 */
		char queFicha();

	/*
	 * Precondicion: El lugar debe estar libre.
	 * Postcondicion: Coloca una ficha en la posicion.
	 */
		void ocupar (char tipoFicha);

	/*
	 * Destructor
	 * Libera recursos asociados

	~Posicion;*/
};





#endif /* SRC_POSICION_H_ */
