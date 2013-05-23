#ifndef LUDO_H
#define LUDO_H

#include "Pieza.h"
#include "Position.h"
#include "Enumeracion.h"
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sstream>
#include <map>
using namespace std;

class Ludo{
	private:
		Pieza* tablero[11][11];
		void inicializarTablero();
		bool estaVacia( int, int );
		map<int, Position*> piezasVerde;
		map<int, Position*> piezasRoja;
		map<int, Position*> piezasAmarilla;
		map<int, Position*> piezasAzul;
		void swap( Position*, Position* );
	public:
		Ludo();
		void imprimirTablero();
		void mover( int  );
		bool finJuego();
		~Ludo();
};

#endif
