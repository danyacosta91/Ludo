#include "Position.h"

Position::Position( int x, int y ){
	this->posX = x;
	this->posY = y;
}

string Position::toString(){
	stringstream ret;

	ret << "(" << this->posX << "," << this->posY << ")";
	return ret.str();
}
