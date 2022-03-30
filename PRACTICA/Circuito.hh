/** @file Circuito.hh
    @brief Especificación de la clase Circuito
*/


#ifndef _CIRCUITO_HH_
#define _CIRCUITO_HH_

#include "Jugador.hh"
#include "Torneo.hh"
#include "Categoria.hh"
#ifndef NO_DIAGRAM
#include <map>
#include <list>
#endif

/** @class Circuito
    @brief Representa el Circuito de los torneos

Contiene el ranking y la lista de los torneos...
*/

class Circuito
{
public:


private:
  map<int, Jugador> ranking;
  map<string, Torneo> lista_torneos;
};

#endif
