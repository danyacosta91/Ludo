#include "Position.h"
#include "Pieza.h"
#include "Enumeracion.h"
#include <ncurses.h>
#include <string.h>
#include "Ludo.h"
using namespace std;

int main(){
	Ludo* juego = new Ludo();
	int turno = 1;
	initscr();
	start_color();
	init_pair(10, COLOR_WHITE, COLOR_BLACK );
	do{
		juego->imprimirTablero();
		attron( COLOR_PAIR(10) | A_BOLD );

		juego->mover( turno );
		if( turno < 5 )
			turno++;
		else
			turno = 1;
		clear();
	}while( !juego->finJuego() );
	endwin();
	delete juego;
	return 9;
}
