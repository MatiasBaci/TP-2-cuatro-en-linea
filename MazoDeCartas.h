/*
 * MazoDeCartas.h
 *
 *  Created on: May 22, 2021
 *      Author: algo2
 */

#ifndef SRC_MAZODECARTAS_H_
#define SRC_MAZODECARTAS_H_

#include "Carta.h"

class MazoDeCartas {

	private:

		Carta* tope;

	public:

		/*
		 * pre: No tiene
		 * post: Instancia de mazo vacia y lista para ser usada
		 */
		MazoDeCartas();

		/*
		 * pre: No tiene
		 * post: Devuelve si el mazo no cartas
		 */
		bool noTieneCartas();

		/*
		 * pre: No tiene
		 * post: Agrega una carta en el tope del mazo
		 */
		void agregarUnaCarta();


		/*
		 * pre: La pila no esta vacia
		 * post: Remueve una carta del tope del mazo y la devuelve
		 */
		int sacarUnaCarta();

		/*
		 * pre: No tiene
		 * post: Remueve todos los elementos y libera los recursos
		 * 		tomados por la estructura de datos
		 */
		~MazoDeCartas();
};




#endif /* SRC_MAZODECARTAS_H_ */
