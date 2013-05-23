#include "Ludo.h"

Ludo::Ludo(){
	this->inicializarTablero();
}

void Ludo::inicializarTablero(){
	for( int i = 0; i < 11; i++ ){
		for( int j = 0; j < 11; j++ )
			this->tablero[i][j] = 0;
	}

	//PEIZAS ROJAS
	tablero[1][1] = new Pieza( ROJO );
	tablero[1][2] = new Pieza( ROJO );
	tablero[2][1] = new Pieza( ROJO );
	tablero[2][2] = new Pieza( ROJO );

	piezasRoja.insert( pair<int, Position*>( 1, new Position(1,1) ) );
	piezasRoja.insert( pair<int, Position*>( 2, new Position(1,2) ) );
	piezasRoja.insert( pair<int, Position*>( 3, new Position(2,1) ) );
	piezasRoja.insert( pair<int, Position*>( 4, new Position(2,2) ) );

	//PIEZAS rojos
	tablero[1][8] = new Pieza( VERDE );
	tablero[1][9] = new Pieza( VERDE );
	tablero[2][8] = new Pieza( VERDE );
	tablero[2][9] = new Pieza( VERDE );

	piezasVerde.insert( pair<int, Position*>( 1, new Position(1,8) ) );
	piezasVerde.insert( pair<int, Position*>( 2, new Position(1,9) ) );
	piezasVerde.insert( pair<int, Position*>( 3, new Position(2,8) ) );
	piezasVerde.insert( pair<int, Position*>( 4, new Position(2,9) ) );

	//PIEZAS AMARILLAS
	tablero[8][1] = new Pieza( AMARILLO );
	tablero[9][1] = new Pieza( AMARILLO );
	tablero[8][2] = new Pieza( AMARILLO );
	tablero[9][2] = new Pieza( AMARILLO );

	piezasAmarilla.insert( pair<int, Position*>( 1, new Position(8,1) ) );
	piezasAmarilla.insert( pair<int, Position*>( 3, new Position(9,1) ) );
	piezasAmarilla.insert( pair<int, Position*>( 2, new Position(8,2) ) );
	piezasAmarilla.insert( pair<int, Position*>( 4, new Position(9,2) ) );

	//PIEZAS AZULES
	tablero[8][8] = new Pieza( AZUL );
	tablero[8][9] = new Pieza( AZUL );
	tablero[9][8] = new Pieza( AZUL );
	tablero[9][9] = new Pieza( AZUL );

	piezasAzul.insert( pair<int, Position*>( 1, new Position(8,8) ) );
	piezasAzul.insert( pair<int, Position*>( 2, new Position(8,9) ) );
	piezasAzul.insert( pair<int, Position*>( 3, new Position(9,8) ) );
	piezasAzul.insert( pair<int, Position*>( 4, new Position(9,9) ) );

	//TABLERO DE JUEGO
	for( int i = 4; i < 7; i++ ){
		for( int j = 0; j < 11; j++ )
			tablero[i][j] = new Pieza( CASA );
	}
	for( int i = 4; i < 7; i++ ){
		for( int j = 0; j < 11; j++ )
			tablero[j][i] = new Pieza( CASA );
	}
}

bool Ludo::estaVacia( int x, int y ){
	if( this->tablero[x][y] == 0 )
		return true;
	return false;
}

void Ludo::imprimirTablero(){
	int contRojo = 1, contAma = 1, contVerde = 1, contAzul = 1;
	Position* tmp;
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE );
	init_pair(2, COLOR_RED, COLOR_RED );
	init_pair(3, COLOR_GREEN, COLOR_GREEN );
	init_pair(4, COLOR_YELLOW, COLOR_YELLOW );
	init_pair(5, COLOR_WHITE, COLOR_BLACK );
	init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA );
	init_pair(7, COLOR_BLACK, COLOR_WHITE );
	init_pair(9, COLOR_BLUE, COLOR_BLUE );
	attron( COLOR_PAIR(5) | A_BOLD  );
	printw("\t  T A B L E R O\n\n");
	for( int i = 0; i < 11; i++ ){
		for( int j = 0; j < 11; j++ ){
			if( !estaVacia( i, j ) ){
				switch( tablero[i][j]->getColor() ){
					case ROJO:
						attron( COLOR_PAIR(2) | A_BOLD  );
						printw(" %d ",contRojo);
						contRojo++;
					break;
					case VERDE:
						attron( COLOR_PAIR(3) | A_BOLD  );
						printw(" %d ",contVerde);
						contVerde++;
					break;
					case AMARILLO:
						attron( COLOR_PAIR(4) | A_BOLD  );
						printw(" %d ",contAma);
						contAma++;
					break;
					case AZUL:
						attron( COLOR_PAIR(9) | A_BOLD  );
						printw(" %d ",contAzul);
						contAzul++;
					break;
					case CASA:
						attron( COLOR_PAIR(7) | A_BOLD  );
						printw(" | ");
					break;
				}//FIN SWITCH
			}//FIN IF
			else{
				attron( COLOR_PAIR(5) | A_BOLD  );
				printw("   ");
			}
		}//FIN FOR INTERNO
		printw("\n");
	}//FIN FOR EXTERNO
}

void Ludo::mover( int turno ){
	srand( time(NULL) );
	int valorDado = rand()%6+1;
	int valorPieza;
	Position* valorPiezaArray = 0;
	Position* tmp = 0;

	attron( COLOR_PAIR(5) | A_BOLD );
	switch( turno ){
		case 1:{
			printw("Turno de color: ROJO\n");
			printw("Ingrese numero de pieza: \n");
			valorPieza = getch();
			printw("\nIngrese cualquier tecla para mover!\nValor del dado: %d",valorDado);
			getch();
			valorPieza -= 48;
			valorPiezaArray = piezasRoja[valorPieza];
			if( !tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->estaEnCasa() ){
				tmp = tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->getSiguientePosicion( valorDado );
				if( tmp != 0 ){
					swap( valorPiezaArray, tmp );
					piezasRoja[valorPieza] = tmp;
				}
			}
		}break;
		case 2:{
			printw("Turno de color: VERDE\n");
			printw("Ingrese numero de pieza: \n");
			valorPieza = getch();
			printw("\nIngrese cualquier tecla para mover!\nValor del dado: %d",valorDado);
			getch();
			valorPieza -= 48;
			valorPiezaArray = piezasVerde[valorPieza];
			if( !tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->estaEnCasa() ){
				tmp = tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->getSiguientePosicion( valorDado );
				if( tmp != 0 ){
					swap( valorPiezaArray, tmp );
					piezasVerde[valorPieza] = tmp;
				}
			}
		}break;
		case 3:{
			printw("Turno de color: AMARILLO\n");
			printw("Ingrese numero de pieza: \n");
			valorPieza = getch();
			printw("\nIngrese cualquier tecla para mover!\nValor del dado: %d",valorDado);
			getch();
			valorPieza -= 48;
			valorPiezaArray = piezasAmarilla[valorPieza];
			if( !tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->estaEnCasa() ){
				tmp = tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->getSiguientePosicion( valorDado );
				if( tmp != 0 ){
					swap( valorPiezaArray, tmp );
					piezasAmarilla[valorPieza] = tmp;
				}
			}
		}break;
		case 4:{
			printw("Turno de color: AZUL\n");
			printw("Ingrese numero de pieza: \n");
			valorPieza = getch();
			printw("\nIngrese cualquier tecla para mover!\nValor del dado: %d",valorDado);
			getch();
			valorPieza -= 48;
			valorPiezaArray = piezasAzul[valorPieza];
			if( !tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->estaEnCasa() ){
				tmp = tablero[valorPiezaArray->getX()][valorPiezaArray->getY()]->getSiguientePosicion( valorDado );
				if( tmp != 0 ){
					swap( valorPiezaArray, tmp );
					piezasAzul[valorPieza] = tmp;
				}
			}
		}break;
	}
}

void Ludo::swap( Position* origen, Position* destino ){
	Pieza* tmp = tablero[destino->getX()][destino->getY()];
	tablero[destino->getX()][destino->getY()] = tablero[origen->getX()][origen->getY()];
	tablero[origen->getX()][origen->getY()] = tmp;
}

bool Ludo::finJuego(){
	for( int i = 0; i < 10; i++){
		for( int j = 0; j < 10; j++ ){
			if( !estaVacia( i , j) ){
				switch( tablero[i][j]->getColor() ){
					case ROJO:
					case VERDE:
					case AMARILLO:
					case AZUL:
						if( !tablero[i][j]->estaEnCasa() )
							return false;
					break;
				}//FIN SWITCH
			}
		}
	}
	return true;
}

Ludo::~Ludo(){
	for( int i = 0; i < 10; i++){
		for( int j = 0; j < 10; j++ )
			delete tablero[i][j];
	}
}
