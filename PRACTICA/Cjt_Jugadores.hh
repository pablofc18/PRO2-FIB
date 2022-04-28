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
      \post El resultado es un map vacío de ranking y otro del listado de jugadores
  */
  Cjt_Jugadores();

  // Modificadoras

  /** @brief Da de alta un Jugador

      \pre El párametro implícito no contiene al Jugador p
      \post Se añade el Jugador p al ranking y a la lista de jugadores
  */
  void anadir_jugador(string nombre_jug);

  /** @brief Da de baja un Jugador

      \pre <em>Cierto</em>
      \post Se elimina al Jugador con nombre nombre_jug, si existe, devolviendo true. Y false si no existe
  */
  bool eliminar_jugador(string nombre_jug);

  /** @brief Actualiza el ranking de jugadores

      \pre Se han modificado los puntos de Jugadores
      \post El resultado es el ranking actualizado con los valores más recientes
  */
  void actualizar_ranking(vector< vector<int> > pts_categ_nivel, vector<int> jugadores_del_torneo);

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

  void ordenar_ranking();
private:
  vector<Jugador> ranking;
  map<string, Jugador> cjt_Jugadores;
};

#endif
