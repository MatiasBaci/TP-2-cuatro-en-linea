/*
 * Carta.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */
// Clase Carta

#ifndef SRC_Carta_H_

#define SRC_Carta_H_

#ifndef NULL

#define NULL 0

#endif

class Carta {

	private:

		int info;

		Carta* sig;

	public:

		/*
		 * pre:
		 * pos: Genera una Carta,que es un numero aleatorio del 1 al 4.
		 */
		Carta ();

		/*
		 * pre: Existe la Carta.
		 * pos: Nos da el valor de la Carta.
		 */
		int getInfo ();

		/*
		 * pre:
		 * pos: Avanza una Carta.
		 */
		Carta* getSig();

		/*
		 * pre:
		 * pos: Hace que la Carta apunte a otra determinada.
		 */
		void setSig (Carta*);

};





#endif /* SRC_Carta_H_ */
