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

		Posicion* vecinos [3][3][3];

		int x;

		int y;

		int z;


	public:

	/*
	 * Contructor
	 * Precondicion: No tiene.
	 * Postcondicion: Crea una posicion del tablero y la inicializa.
	 */
		Posicion();

	/*
	 * pre: Existe la posicion y recibe una coordenada valida
	 * post: Setea la coordenada X.
	 */
	   void setX(int ancho);

	/*
	 * pre: Existe la posicion y recibe una coordenada valida
	 * post: Setea la coordenada Y.
	 *
	 */
	   void setY(int alto);

	/*
	 * pre: Existe la posicion y recibe una coordenada valida
	 * post: Setea la coordenada Z.
	 */
	   void setZ(int profundidad);

	/*
	 * pre: Existe la posicion
	 * post: Devuelve la coordenada X.
	 */
	   int getX();

	/*
	 * pre: Existe la posicion
	 * post: Devuelve la coordenada Y.
	 */
	   int getY();

	/*
	 * pre: Existe la posicion
	 * post: Devuelve la coordenada Z.
	 */
		int getZ();

	/*
	 * pre: x, y, z deben estar en un rango de -1 a +1
	 * post: Devuelve un puntero a la posicion vecina
	 */
		Posicion* getVecino(int x, int y, int z);

	/*
	 * pre:
	 * post:
	 */
		void setVecino(Posicion* posicion, int x, int y, int z);

	/*
	 * pre: Recibe una posicion
	 * post: Indica si esa posicion tiene la misma ficha que la de la posicion this
	 */
		bool tieneLaMismaFicha (Posicion* posicionAComparar);



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
	 */
	    ~Posicion();
};





#endif /* SRC_POSICION_H_ */
