DW: Position.o Pieza.o main.o
		g++ -o Position.cpp Pieza.cpp main.cpp

main.o: Position.o Pieza.o
		g++ -o Position.cpp Pieza.cpp main.cpp

Pieza.o: Position.o
		g++ -o Position.cpp Pieza.cpp

Position.o:
		g++ -o Position.cpp
