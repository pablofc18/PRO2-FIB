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
  // Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Jugador.
      \pre <em>Cierto</em>
      \post El resultado es un Jugador sin inicializar
  */
  Jugador();

  /** @brief Creadora con valores correctos.

      \pre <em>Nombre no repetido</em>
      \post El resultado es un jugador con su nombre y todo inicializado a 0
  */
  Jugador(string nombre_jug);

  // Modificadoras

  

  // Consultoras

  /** @brief Consultora si existe Jugador con ese nombre

      \pre <em>Cierto</em>
      \post El resultado es si existe o no el Jugador
  */
  bool existe_jugador(string nombre_jug) const;

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

  /** @brief Operación de lectura

      \pre Hay preparado en el canal estándar d'entrada un string válido
      \post El Jugador pasa a tener el nombre inicializado
  */
  void leer();

  /** @brief Operación de escritura

      \pre <em>Cierto</em>
      \post Se han escrito en el canal estándar de salida todos los datos del Jugador
  */
  void escribir() const;


private:
  string nombre;
  int puntos;
  int torneos_disputados;
  pair<int, int> partidos; // first = ganados, second = perdidos
  pair<int, int> sets;  // first = ganados, second = perdidos
  pair<int, int> juegos;  // first = ganados, second = perdidos

};

#endif
