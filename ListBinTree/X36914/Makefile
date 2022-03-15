OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Estudiant.o LlistaIOEstudiant.o
	g++ -o program.exe program.o Estudiant.o LlistaIOEstudiant.o
	rm *.o

LlistaIOEstudiant.o: LlistaIOEstudiant.cc LlistaIOEstudiant.hh Estudiant.hh
	g++ -c LlistaIOEstudiant.cc $(OPCIONS)

Estudiant.o: Estudiant.cc Estudiant.hh
	g++ -c Estudiant.cc $(OPCIONS)

program.o: program.cc LlistaIOEstudiant.hh Estudiant.hh
	g++ -c program.cc $(OPCIONS)

tar: program.cc LlistaIOEstudiant.hh LlistaIOEstudiant.cc
	tar cvf sol.tar program.cc LlistaIOEstudiant.hh LlistaIOEstudiant.cc

clean:
	rm *.o
	rm *.exe
