/*
 * Jugador.h
 *
 *  Created on: Apr 30, 2021
 *      Author: algo2
 */

#ifndef SRC_JUGADOR_H_
#define SRC_JUGADOR_H_

#include <string>

#include "MazoDeCartas.h"

#include "Cartas del Jugador.h"

#include "Lista.h"

#include "Nodo.h"

#include "Posicion.h"

class Jugador {

	private:

		std::string nombre;

		char ficha;

		unsigned int fichasRestantes;

		unsigned int juegosGanados;

		int cantidadDeCartas;

		Carta* misCartas;

		Jugador *sig;

		Jugador *ant;

		Lista <Posicion *> * posicionesOcupadas;

	public:

		/*
		 * pre: No tiene
		 * pos: Crea un jugador sin argumentos
		 */
		Jugador ();

		/*
		* pre: No tiene
		* pos: Crea un jugador.
		*/
		Jugador (std::string, unsigned int);

		/*
		 * post: Destructor
		 */
		~Jugador ();

		/*
		 * pre:
		 * pos: Avanza un jugador.
		 */
		Jugador* getSig();

		/*
		 * pre: Existe un jugador
		 * pos: Devuelve un puntero al jugador anterior
		 */
		Jugador* getAnt();

		/*
		 * pre:
		 * pos: Hace que un jugador apunte al siguiente jugador.
		 */
		void setSig (Jugador*);

		/*
		 * pre: Existe un jugador
		 * pos: Agrega una carta al jugador
		 */
		void altaDeUnaCarta (MazoDeCartas*);

		/*
		 * pre: Existe el jugador
		 * pos: Emite todas las cartas del jugador
		 */
		void emite () const;

		/*
		 * pre:
		 * pos: Hace que un jugador apunte al jugador anterior.
		 */
		void setAnt (Jugador*);

		/*
		 * pre: Existe el jugador y tiene como minimo una carta
		 * post: Da de baja una carta de las que tiene el jugador
		 */
		void bajaDeUnaCarta(int);

		/*
		 * pre: Existe el jugador
		 * pos: Devuelve el nombre del jugador.
		 */
		std::string getNombre ();

		/*
		 * pre: Existe jugador
		 * pos: Devuelve la ficha del jugador
		 */
		char getFicha ();

		/*
		 *	pre: Existe jugador
		 *	post: Crea la ficha del jugador segun caracter dado por parametro
		 */
		void setFicha (char);
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
		 * pre: Recibe la variacion en la cantidad de fichas.
		 * pos: Actualiza las fichas que le quedan al jugador.
		 */
		void setFichasRestantes (int);

		/*
		 * pre: Suma un juego ganado al jugador
		 * pos: Actualiza juegos ganados por el jugador.
		 */
		void setJuegosGanados ();

		/*
		 * pre:
		 * post: Devuelve la cantidad de cartas que tiene el jugador.
		 */
		int getCantidadCartas();

		/*
		 *	pre: Posicion debe estar inicializada previamente con datos validos.
		 *  post: Agrega a la lista de posicionesOcupadas la posicion dada por argumento.
		 */
		void agregarPosicionOcupada(Posicion*);

		/*
		 * pre: -
 		 * post: Emite por consola las posiciones ocupadas por este jugador.
		 */
		void emitirPosicionesOcupadas();

		/*
		 * pre: Existe el jugador.
		 * post: Reinicia a caso base al jugador.
		 */
		void reiniciarJugador(int);
};






#endif /* SRC_JUGADOR_H_ */
