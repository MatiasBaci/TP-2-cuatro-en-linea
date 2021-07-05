/*
 * Interacciones.h
 *
 *  Created on: May 1, 2021
 *      Author: algo2
 */

#ifndef SRC_INTERACCIONES_H_
#define SRC_INTERACCIONES_H_

#include "TP2.h"

#include "Jugador.h"

/*
 * pre: No tiene
 * post: Presenta el juego
 */
void presentacion ();

/*
 * pre: No tiene
 * post: Permite seleccionar los parametros iniciales del juego
 */
void opcionesDeJuego (TP2*);

/*
 * pre: Existe el jugador
 * post: Devuelve la carta jugada por el jugador de turno
 */
int queCartaVaAJugar (Jugador*);


#endif /* SRC_INTERACCIONES_H_ */
