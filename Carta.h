/*
 * Carta.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */
// Clase Carta

#ifndef SRC_CARTA_H_

#define SRC_CARTA_H_

#ifndef NULL

#define NULL 0

#endif

class Carta {

	private:

		int info;

		Carta* sig;

	public:

		/*
		 * pre: Constructor sin argumentos nodo carta
		 * pos: Genera una carta,que es un numero aleatorio del 1 al 4.
		 */
		Carta ();

		/*
		 * pre: Constructor sin argumentos nodo carta
		 * pos: Genera una carta,que es un numero aleatorio del 1 al 4.
		 */
		Carta (int valor);

		/*
		 * pre: Existe la carta.
		 * pos: Nos da el valor de la carta.
		 */
		int getInfo ();

		/*
		 * pre:
		 * pos: Avanza una carta.
		 */
		Carta* getSig();

		/*
		 * pre:
		 * pos: Hace que la carta apunte a otra determinada.
		 */
		void setSig (Carta*);

};





#endif /* SRC_CARTA_H_ */
