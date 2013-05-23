#include "Pieza.h"
#include "Enumeracion.h"

Pieza::Pieza( ENUM_COLOR color ){
	this->color = color;
	this->valorArray = 0;
	this->dentro = false;
	if( this->color == AMARILLO ){
		posiciones.push_back( new Position(10,4) );posiciones.push_back( new Position(10,5) );
		posiciones.push_back( new Position(10,6) );posiciones.push_back( new Position(9,6) );
		posiciones.push_back( new Position(8,6) );posiciones.push_back( new Position(7,6) );
		posiciones.push_back( new Position(6,6) );posiciones.push_back( new Position(6,7) );
		posiciones.push_back( new Position(6,8) );posiciones.push_back( new Position(6,9) );
		posiciones.push_back( new Position(6,10) );posiciones.push_back( new Position(5,10) );
		posiciones.push_back( new Position(4,10) );posiciones.push_back( new Position(4,9) );
		posiciones.push_back( new Position(4,8) );posiciones.push_back( new Position(4,7) );
		posiciones.push_back( new Position(4,6) );posiciones.push_back( new Position(3,6) );
		posiciones.push_back( new Position(2,6) );posiciones.push_back( new Position(1,6) );
		posiciones.push_back( new Position(0,6) );posiciones.push_back( new Position(0,5) );
		posiciones.push_back( new Position(0,4) );posiciones.push_back( new Position(1,4) );
		posiciones.push_back( new Position(2,4) );posiciones.push_back( new Position(3,4) );
		posiciones.push_back( new Position(4,4) );posiciones.push_back( new Position(4,3) );
		posiciones.push_back( new Position(4,2) );posiciones.push_back( new Position(4,1) );
		posiciones.push_back( new Position(4,0) );posiciones.push_back( new Position(5,0) );
		posiciones.push_back( new Position(6,0) );posiciones.push_back( new Position(6,1) );
		posiciones.push_back( new Position(6,2) );posiciones.push_back( new Position(6,3) );
		posiciones.push_back( new Position(6,4) );posiciones.push_back( new Position(7,4) );
		posiciones.push_back( new Position(8,4) );posiciones.push_back( new Position(9,4) );
	}
	else if( this->color == ROJO ){
		posiciones.push_back( new Position(4,0) );posiciones.push_back( new Position(5,0) );
		posiciones.push_back( new Position(6,0) );posiciones.push_back( new Position(6,1) );
		posiciones.push_back( new Position(6,2) );posiciones.push_back( new Position(6,3) );
		posiciones.push_back( new Position(6,4) );posiciones.push_back( new Position(7,4) );
		posiciones.push_back( new Position(8,4) );posiciones.push_back( new Position(9,4) );
		posiciones.push_back( new Position(10,4) );posiciones.push_back( new Position(10,5) );
		posiciones.push_back( new Position(10,6) );posiciones.push_back( new Position(9,6) );
		posiciones.push_back( new Position(8,6) );posiciones.push_back( new Position(7,6) );
		posiciones.push_back( new Position(6,6) );posiciones.push_back( new Position(6,7) );
		posiciones.push_back( new Position(6,8) );posiciones.push_back( new Position(6,9) );
		posiciones.push_back( new Position(6,10) );posiciones.push_back( new Position(5,10) );
		posiciones.push_back( new Position(4,10) );posiciones.push_back( new Position(4,9) );
		posiciones.push_back( new Position(4,8) );posiciones.push_back( new Position(4,7) );
		posiciones.push_back( new Position(4,6) );posiciones.push_back( new Position(3,6) );
		posiciones.push_back( new Position(2,6) );posiciones.push_back( new Position(1,6) );
		posiciones.push_back( new Position(0,6) );posiciones.push_back( new Position(0,5) );
		posiciones.push_back( new Position(0,4) );posiciones.push_back( new Position(1,4) );
		posiciones.push_back( new Position(2,4) );posiciones.push_back( new Position(3,4) );
		posiciones.push_back( new Position(4,4) );posiciones.push_back( new Position(4,3) );
		posiciones.push_back( new Position(4,2) );posiciones.push_back( new Position(4,1) );
	}
	else if( this->color == AZUL ){
		posiciones.push_back( new Position(6,10) );posiciones.push_back( new Position(5,10) );
		posiciones.push_back( new Position(4,10) );posiciones.push_back( new Position(4,9) );
		posiciones.push_back( new Position(4,8) );posiciones.push_back( new Position(4,7) );
		posiciones.push_back( new Position(4,6) );posiciones.push_back( new Position(3,6) );
		posiciones.push_back( new Position(2,6) );posiciones.push_back( new Position(1,6) );
		posiciones.push_back( new Position(0,6) );posiciones.push_back( new Position(0,5) );
		posiciones.push_back( new Position(0,4) );posiciones.push_back( new Position(1,4) );
		posiciones.push_back( new Position(2,4) );posiciones.push_back( new Position(3,4) );
		posiciones.push_back( new Position(4,4) );posiciones.push_back( new Position(4,3) );
		posiciones.push_back( new Position(4,2) );posiciones.push_back( new Position(4,1) );
		posiciones.push_back( new Position(4,0) );posiciones.push_back( new Position(5,0) );
		posiciones.push_back( new Position(6,0) );posiciones.push_back( new Position(6,1) );
		posiciones.push_back( new Position(6,2) );posiciones.push_back( new Position(6,3) );
		posiciones.push_back( new Position(6,4) );posiciones.push_back( new Position(7,4) );
		posiciones.push_back( new Position(8,4) );posiciones.push_back( new Position(9,4) );
		posiciones.push_back( new Position(10,4) );posiciones.push_back( new Position(10,5) );
		posiciones.push_back( new Position(10,6) );posiciones.push_back( new Position(9,6) );
		posiciones.push_back( new Position(8,6) );posiciones.push_back( new Position(7,6) );
		posiciones.push_back( new Position(6,6) );posiciones.push_back( new Position(6,7) );
		posiciones.push_back( new Position(6,8) );posiciones.push_back( new Position(6,9) );
	}
	else if( this->color == VERDE ){
		posiciones.push_back( new Position(0,6) );posiciones.push_back( new Position(0,5) );
		posiciones.push_back( new Position(0,4) );posiciones.push_back( new Position(1,4) );
		posiciones.push_back( new Position(2,4) );posiciones.push_back( new Position(3,4) );
		posiciones.push_back( new Position(4,4) );posiciones.push_back( new Position(4,3) );
		posiciones.push_back( new Position(4,2) );posiciones.push_back( new Position(4,1) );
		posiciones.push_back( new Position(4,0) );posiciones.push_back( new Position(5,0) );
		posiciones.push_back( new Position(6,0) );posiciones.push_back( new Position(6,1) );
		posiciones.push_back( new Position(6,2) );posiciones.push_back( new Position(6,3) );
		posiciones.push_back( new Position(6,4) );posiciones.push_back( new Position(7,4) );
		posiciones.push_back( new Position(8,4) );posiciones.push_back( new Position(9,4) );
		posiciones.push_back( new Position(10,4) );posiciones.push_back( new Position(10,5) );
		posiciones.push_back( new Position(10,6) );posiciones.push_back( new Position(9,6) );
		posiciones.push_back( new Position(8,6) );posiciones.push_back( new Position(7,6) );
		posiciones.push_back( new Position(6,6) );posiciones.push_back( new Position(6,7) );
		posiciones.push_back( new Position(6,8) );posiciones.push_back( new Position(6,9) );
		posiciones.push_back( new Position(6,10) );posiciones.push_back( new Position(5,10) );
		posiciones.push_back( new Position(4,10) );posiciones.push_back( new Position(4,9) );
		posiciones.push_back( new Position(4,8) );posiciones.push_back( new Position(4,7) );
		posiciones.push_back( new Position(4,6) );posiciones.push_back( new Position(3,6) );
		posiciones.push_back( new Position(2,6) );posiciones.push_back( new Position(1,6) );
	}
}

string Pieza::toString(){
	stringstream ret;
	ret << "Pieza  ";
	if( this->color == AMARILLO )
		ret << " Color: Amarillo";
	else if( this->color == ROJO )
		ret << " Color: Rojo";
	else if( this->color == AZUL )
		ret << " Color: Azul";
	else if( this->color == VERDE )
		ret << " Color: Verde";
	return ret.str();
}

Position* Pieza::getSiguientePosicion( int v ){
	if( this->valorArray+(v-1) < this->posiciones.size() )
		this->valorArray += v-1;
	else if ( this->valorArray+(v-1) == this->posiciones.size() ){
		this->valorArray += v-1;
		this->dentro = true;
	}
	else
		return 0;
	return this->posiciones.at( this->valorArray );
}

Pieza::~Pieza(){
	this->posiciones.clear();
}
