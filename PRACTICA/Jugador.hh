/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH
#define _JUGADOR_HH

#ifndef NO_DIAGRAM
#include <utility>
#include <string>
#include <iostream>
using namespace std;
#endif

/** @class Jugador
    @brief Representa un Jugador

Dispone de blablabla...
*/

class Jugador
{
public:
  // Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Jugador
      \pre <em>Cierto</em>
      \post El resultado es un Jugador sin inicializar
  */
  Jugador();

  /** @brief Creadora con valores correctos.

      \pre Nombre no repetido
      \post El resultado es un jugador con su nombre y todo inicializado a 0
  */
  Jugador(string nombre_jug);

  // Modificadoras

  /** @brief Modificador de los puntos

      \pre <em>Cierto</em>
      \post Los puntos del Jugador pasan a ser puntos_jug
  */
  void modificar_puntos(int puntos_jug);

  /** @brief Modificador de los partidos jugados

  \pre El pair consta de first = ganados, second = perdidos
  \post Los partidos disputados del Jugador pasan a ser partidos_jug
  */
  void modificar_partidos_jugados(pair<int, int> partidos_jug);

  /** @brief Modificador de los sets jugados

      \pre El pair consta de first = ganados, second = perdidos
      \post Los sets disputados del Jugador pasan a ser sets_jug
  */
  void modificar_sets_jugados(pair<int, int> sets_jug);

  /** @brief Modificador de los juegos jugados

      \pre El pair consta de first = ganados, second = perdidos
      \post Los juegos disputados del Jugador pasan a ser juegos_jug
  */
  void modificar_juegos_jugados(pair<int, int> juegos_jug);

  /** @brief Modificador de los torneos disputados

      \pre torneo_disp = 1 o torneo_disp = -1
      \post Los torneos disputados del Jugador se les suma torneo_disp
  */
  void modificar_torneo_disputados(int torneo_disp);

  // Consultoras

  // /** @brief Consultora si existe Jugador con ese nombre
  //
  //     \pre <em>Cierto</em>
  //     \post El resultado es si existe o no el Jugador
  // */
  // bool existe_jugador(string nombre_jug) const;

  /** @brief Consultora del nombre del Jugador

      \pre <em>Cierto</em>
      \post El resultado es el nombre del Jugador
  */
  string consultar_nombre() const;

  /** @brief Consultora de los puntos del Jugador

      \pre <em>Cierto</em>
      \post El resultado son los puntos del Jugador
  */
  int consultar_puntos() const;

  /** @brief Consultora de los torneos disputados del Jugador

      \pre <em>Cierto</em>
      \post El resultado es el numero de torneos disputados del Jugador
  */
  int consultar_torneos_disputados() const;

  /** @brief Consultora de los partidos ganados y perdidos del Jugador

      \pre <em>Cierto</em>
      \post El resultado es un pair de los partidos ganados (first) y perdidos (second) del Jugador
  */
  pair<int, int> consultar_partidos() const;

  /** @brief Consultora de los sets ganados y perdidos del Jugador

      \pre <em>Cierto</em>
      \post El resultado es un pair de los sets ganados (first) y perdidos (second) del Jugador
  */
  pair<int, int> consultar_sets() const;

  /** @brief Consultora de los juegos ganados y perdidos del Jugador

      \pre <em>Cierto</em>
      \post El resultado es un pair de los juegos ganados (first) y perdidos (second) del Jugador
  */
  pair<int, int> consultar_juegos() const;

  // Escritura / Lectura

  /** @brief Operación de escritura

      \pre <em>Cierto</em>
      \post Se han escrito en el canal estándar de salida todos los datos del Jugador
  */
  void escribir() const;


private:    // POSICIÓN EN RANKING ?? MIRAR MAIN OPC == listar_jugadores
  string nombre;
  int puntos;
  int torneos_disputados;
  pair<int, int> partidos; // first = ganados, second = perdidos
  pair<int, int> sets;  // first = ganados, second = perdidos
  pair<int, int> juegos;  // first = ganados, second = perdidos

};

#endif
