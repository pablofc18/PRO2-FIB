/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH
#define _JUGADOR_HH

/** @class Jugador
    @brief Representa un Jugador

Dispone de blablabla...
*/

class Jugador
{
public:
  //Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Jugador.
      \pre <em>cierto</em>
      \post El resultado es un Jugador sin inicializar
  */
  Jugador();



private:
  string nombre;
  int puntos;
  int torneos_disputados;
  pair<int, int> partidos; // first = ganados, second = perdidos
  pair<int, int> sets;  // first = ganados, second = perdidos
  pair<int, int> juegos;  // first = ganados, second = perdidos

};

#endif
