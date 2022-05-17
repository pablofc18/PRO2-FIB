/** @file Cjt_Jugadores.hh
    @brief Especificación de la clase Cjt_Jugadores
*/

#ifndef _CJT_JUGADORES_HH
#define _CJT_JUGADORES_HH

#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#include <algorithm>
#endif

/** @class Cjt_Jugadores
    @brief Representa el conjunto de los jugadores

    Dispone de operaciones para poder modificar el conjunto de jugadores, consultarlo
    y leer o escribir sus datos.
*/

class Cjt_Jugadores
{
public:
  // Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Conjunto de Jugadores
      \pre <em>Cierto</em>
      \post Declara el objeto vacío, no se inicializa nada
  */
  Cjt_Jugadores();

  // Modificadoras

  /** @brief Da de alta un Jugador

      \pre El párametro implícito no contiene al Jugador p, (nombres reales)
      \post Se añade el Jugador p al ranking y a la lista de jugadores
  */
  void anadir_jugador(string nombre_jug);

  /** @brief Da de baja un Jugador

      \pre <em>Cierto</em>
      \post Se elimina al Jugador con nombre nombre_jug, si existe, devolviendo true. Y false si no existe
  */
  bool eliminar_jugador(string nombre_jug);

  /** @brief Actualiza estadísticas de jugador

      \pre <em>Cierto</em>
      \post Se modifican las estadisticas en el map de cjt_Jugadores según el resultado
  */
  void modificar_estadisticas_jug(string nombre_jug_a, string nombre_jug_b, string result);

  /** @brief Suma puntos al jugador (tanto en el map como en el vector)

      \pre <em>Cierto</em>
      \post Se suman los puntos al jugador en ambas estructuras de datos
  */
  void sumar_puntos_jug(string nombre_jug, int pts);

  /** @brief Resta los puntos del jugador si se ha disputado dos veces el mismo torneo

      \pre El jugador ha disputado el mismo torneo anteriormente
      \post Resta los puntos de la edición anterior del torneo disputado
  */
  void restar_puntos_jug(string nombre_jug, int pts);

  /** @brief Modifica aumentando los torneos disputados

      \pre <em>Cierto</em>
      \post Se incrementa los torneos disputados
  */
  void sumar_torneo_disputado(string nombre_jug);

  /** @brief Ordena el ranknig (vector) y modifica datos ranking en map y vector

      \pre <em>Cierto</em>
      \post Se ordena el ranking y modifican los datos de ranking del map y del vector
  */
  void ordenar_ranking();

  // Consultoras

  /** @brief Consulta si existe el Jugador

      \pre <em>Cierto</em>
      \post El resultado indica si existe o no el Jugador con nombre nombre_jug
  */
  bool existe_jugador(string nombre_jug) const;

  /** @brief Consulta de un Jugador

      \pre nombre_jug tiene que ser un nombre de un Jugador que esté en la lista
      \post El resultado es el Jugador de nombre nombre_jug
  */
  Jugador consultar_jugador(string nombre_jug) const;

  /** @brief Consulta de un Jugador

      \pre rank es válido
      \post El resultado es el Jugador de ranking rank
  */
  Jugador consultar_jugador(int rank) const;

  /** @brief Consulta el total de jugadores en la lista

      \pre <em>Cierto</em>
      \post El resultado es el número de jugadores totales
  */
  int numero_jugadores_totales() const;

  // Escritura / Lectura

  /** @brief Operación de lectura de jugadores

      \pre <em>Cierto</em>
      \post Se leen y almacenan los jugadores en la lista de jugadores y ranking
  */
  void leer_jugadores();

  /** @brief Operación de escritura del ranking

      \pre <em>Cierto</em>
      \post Se escribe todo el ranking
  */
  void escribir_ranking() const;

  /** @brief Operación de escritura de la lista de jugadores

      \pre <em>Cierto</em>
      \post Se escribe todos los jugadores, en orden creciente de nombre, con todos sus datos
  */
  void escribir_jugadores() const;

private:
  /** @brief Vector del ranking de los jugadores */
  vector<Jugador> ranking;
  /** @brief Map de la lista de los jugadores (para poder ver todas sus estadísticas) */
  map<string, Jugador> cjt_Jugadores;
};

#endif
