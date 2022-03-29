#ifndef _CIRCUITO_HH_
#define _CIRCUITO_HH_

#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

#include "Jugador.hh"
#include "Torneo.hh"

class Circuito
{
public:





private:
  map<int, Jugador> ranking;
  list<Torneo> lista_torneos;
};

#endif
