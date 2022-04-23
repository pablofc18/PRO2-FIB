/** @file Jugador.hh
    @brief Especificación de la clase Jugador
*/

#ifndef _JUGADOR_HH
#define _JUGADOR_HH

#ifndef NO_DIAGRAM
#include <utility>
#include <iostream>
using namespace std;
#endif

/** @class Jugador
    @brief Representa un Jugador

    Dispone de diferentes operaciones de modificación, consulta y escritura de un jugador.
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

  /** @brief Modificador del ranking

      \pre <em>Cierto</em>
      \post El ranking del Jugador pasa a ser 'rank'
  */
  void modificar_ranking(int rank);

  /** @brief Modificador de los puntos

      \pre <em>Cierto</em>
      \post Los puntos del Jugador pasan a ser 'puntos_jug'
  */
  void modificar_puntos(int puntos_jug);

  /** @brief Modificar el estado de si participa o no en un Torneo

      \pre El bool participando_torneo es false
      \post El bool participando_torneo ahora es true
  */
  void participando_en_torneo();

  /** @brief Modificar el estado de si participa o no en un Torneo

      \pre El bool participando_torneo es true
      \post El bool participando_torneo ahora es false
  */
  void no_participando_torneo();

  /** @brief Modificador de los partidos jugados

  \pre El pair consta de first = ganados, second = perdidos
  \post Los partidos disputados del Jugador pasan a ser 'partidos_jug'
  */
  void modificar_partidos_jugados(pair<int, int> partidos_jug);

  /** @brief Modificador de los sets jugados

      \pre El pair consta de first = ganados, second = perdidos
      \post Los sets disputados del Jugador pasan a ser 'sets_jug'
  */
  void modificar_sets_jugados(pair<int, int> sets_jug);

  /** @brief Modificador de los juegos jugados

      \pre El pair consta de first = ganados, second = perdidos
      \post Los juegos disputados del Jugador pasan a ser 'juegos_jug'
  */
  void modificar_juegos_jugados(pair<int, int> juegos_jug);

  /** @brief Modificador de los torneos disputados

      \pre torneo_disp = 1 o torneo_disp = -1
      \post Los torneos disputados del Jugador se les suma 'torneo_disp'
  */
  void modificar_torneos_disputados(int torneo_disp);

  // Consultoras

  /** @brief Consultora del nombre del Jugador

      \pre <em>Cierto</em>
      \post El resultado es el nombre del Jugador
  */
  string consultar_nombre() const;

  /** @brief Consultora del ranking del Jugador

      \pre <em>Cierto</em>
      \post El resultado es el ranknig del Jugador
  */
  int consultar_ranking() const;

  /** @brief Consultora de los puntos del Jugador

      \pre <em>Cierto</em>
      \post El resultado son los puntos del Jugador
  */
  int consultar_puntos() const;

  /** @brief Consultora de si el Jugador está participando en un torneo

      \pre <em>Cierto</em>
      \post El resultado indica si el Jugador está participando actualmente en un torneo
  */
  bool consultar_participando_torneo() const;

  // Escritura / Lectura

  /** @brief Operación de escritura

      \pre <em>Cierto</em>
      \post Se han escrito todos los datos del Jugador
  */
  void escribir_jug() const;

private:
  string nombre;
  int ranking;
  int puntos;
  bool participando_torneo;
  int torneos_disputados;
  pair<int, int> partidos; // first = ganados, second = perdidos
  pair<int, int> sets;  // first = ganados, second = perdidos
  pair<int, int> juegos;  // first = ganados, second = perdidos
};

#endif
