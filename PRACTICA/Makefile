OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Categoria.o Cjt_Categorias.o Cjt_Jugadores.o Jugador.o Circuito.o Torneo.o
	g++ -o program.exe program.o Categoria.o Cjt_Categorias.o Cjt_Jugadores.o Jugador.o Circuito.o Torneo.o

Categoria.o:  Categoria.cc Categoria.hh
	g++ -c Categoria.cc $(OPCIONS)

Torneo.o:  Torneo.cc Torneo.hh Categoria.hh Jugador.hh Cjt_Jugadores.hh Cjt_Categorias.hh BinTree.hh
	g++ -c Torneo.cc $(OPCIONS)

Jugador.o:	Jugador.cc Jugador.hh
	g++ -c Jugador.cc $(OPCIONS)

Cjt_Categorias.o: Cjt_Categorias.cc Cjt_Categorias.hh Categoria.hh
	g++ -c Cjt_Categorias.cc $(OPCIONS)

Circuito.o: Circuito.cc Circuito.hh Torneo.hh
	g++ -c Circuito.cc $(OPCIONS)

Cjt_Jugadores.o: Cjt_Jugadores.cc Cjt_Jugadores.hh Jugador.hh
	g++ -c Cjt_Jugadores.cc $(OPCIONS)

program.o: program.cc Categoria.hh Cjt_Categorias.hh Cjt_Jugadores.hh Jugador.hh Circuito.hh Torneo.hh BinTree.hh
	g++ -c program.cc $(OPCIONS)

tar: program.cc Categoria.hh Cjt_Categorias.hh Cjt_Jugadores.hh Jugador.hh Circuito.hh Torneo.hh Categoria.cc Cjt_Categorias.cc Cjt_Jugadores.cc Jugador.cc Circuito.cc Torneo.cc
		tar -cvf practica.tar Makefile program.cc Categoria.hh Cjt_Categorias.hh Cjt_Jugadores.hh Jugador.hh Circuito.hh Torneo.hh Categoria.cc Cjt_Categorias.cc Cjt_Jugadores.cc Jugador.cc Circuito.cc Torneo.cc

clean:
	rm *.o
	rm *.exe
