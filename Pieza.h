#ifndef PIEZA_H
#define PIEZA_H

#include "Position.h"
#include "Enumeracion.h"
#include "string.h"
#include <sstream>
#include <vector>
using namespace std;

class Pieza{
	private:
		ENUM_COLOR color;
		bool dentro;
		int valorArray;
		vector<Position*> posiciones;
	public:
		Pieza( ENUM_COLOR );
		string toString();
		ENUM_COLOR getColor(){ return this->color; }
		bool estaEnCasa(){ return this->dentro; }
		Position* getSiguientePosicion( int );
		~Pieza();
};

#endif
