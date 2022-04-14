/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH
#define _TORNEO_HH

#include "Categoria.hh"
#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include <map>
#include "BinTree.hh"
#endif

/** @class Torneo
    @brief Representa un Torneo del circuito

Contiene los datos de un Torneo...
*/

class Torneo
{
public:
  // Constructora

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Torneo
      \pre <em>Cierto</em>
      \post El resultado es un Torneo sin inicializar
  */
  Torneo();

  /** @brief Creadora con valores correctos

      \pre Nombre no repetido
      \post El resultado es un Torneo con su nombre y su categoria correspondiente
  */
  Torneo(string nombre_torneo, Categoria categ);

  // Modificadoras

  /** @brief Modifica el atributo de Torneo 'iniciado'

      \pre El Torneo no se ha disputado todavía
      \post El valor correspondiente con si se ha inciado el Torneo pasa a ser true
  */
  void torneo_iniciar();

  /** @brief Modifica el atributo de Torneo 'finalizado'

      \pre El Torneo tiene que estar iniciado anteriormente
      \post El valor correspondiente con si se ha finalizado el Torneo pasa a ser true
  */
  void torneo_finalizar();

  /** @brief Confecciona el cuadro de emparejamientos

      \pre <em>Cierto</em>
      \post Se crea el arbol binario con los emparejamientos
  */
  void confeccionar_cuadro_emparejamientos();

  // Consultoras

  /** @brief Consulta el nombre del Torneo

      \pre <em>Cierto</em>
      \post Devuelve el nombre del Torneo
  */
  string consultar_nombre() const;

  /** @brief Consulta si el Torneo se ha iniciado

      \pre <em>Cierto</em>
      \post El resultado indica si se ha iniciado el Torneo
  */
  bool torneo_iniciado() const;

  /** @brief Consulta si el Torneo ha finalizado

      \pre <em>Cierto</em>
      \post El resultado indica si se ha finalizado el Torneo
  */
  bool torneo_finalizado() const;

  /** @brief Consulta los jugadores que han disputado el Torneo

      \pre <em>Cierto</em>
      \post El resultado es un map de los jugadores que han disputado el Torneo
  */
  map<int, Jugador> consultar_jugadores_del_torneo() const;

  // Escritura / Lectura

  /** @brief Operación de lectura de jugadores que disputan el torneo

      \pre <em>Cierto</em>
      \post Se leen los jugadores que van a disputar el Torneo
  */
  void leer_participantes_torneo();

  /** @brief Operación de lectura de un Torneo

      \pre <em>Cierto</em>
      \post Se lee el nombre y la categoria del torneo
  */
  void leer_torneo();

  /** @brief Operación de lectura de resultados del Torneo

      \pre <em>Cierto</em>
      \post Se leen los resultados del Torneo
  */
  void leer_resultados();

  /** @brief Operación de escritura de los datos de un Torneo

      \pre <em>Cierto</em>
      \post Se escriben los datos del Torneo, nombre y categoria
  */
  void escribir_torneo() const;

  /** @brief Operación de escritura del cuadro de emparejamientos

      \pre <em>Cierto</em>
      \post Se escribe el cuadro de emparejamientos
  */
  void escribir_cuadro_emparejamientos() const;

  /** @brief Operación de escritura de los resultados del torneo

      \pre <em>Cierto</em>
      \post Se escriben los resultados del Torneo
  */
  void escribir_resultados_torneo() const;

private:
  string nombre;
  Categoria categ;
  bool iniciado;
  bool finalizado;
  map<int, Jugador> jugadores_del_torneo;
  // BinTree's de los cuadros de emparejamientos y resultados del Torneo (todavia no se que dato)
  BinTree< pair<Jugador, Jugador> > cuadro_emparejamientos;
  // BinTree<T> resultados;
};

#endif
