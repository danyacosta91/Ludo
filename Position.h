#ifndef POSITION_H
#define POSITION_H

#include "string.h"
#include <sstream>
using namespace std;

class Position{
	private:
		int posX;
		int posY;
	public:
		Position( int, int );
		void setX( int x ){ posX = x; }
		void setY( int y ){ posY = y; }
		int getX(){ return posX;  }
		int getY(){ return posY;  }
		string toString();
};

#endif
