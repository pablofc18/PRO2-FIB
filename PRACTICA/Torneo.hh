/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH
#define _TORNEO_HH

#include "Categoria.hh"
#include "Jugador.hh"

#ifndef NO_DIAGRAM
#include "Cjt_Jugadores.hh"
#include "Cjt_Categorias.hh"
#include <map>
#include "BinTree.hh"
#endif

/** @class Torneo
    @brief Representa un Torneo del circuito

    Dispone de diferentes operaciones para modificar el estado de un Torneo,
    el cuadro de emparejamientos, el cuadro de resultados... También ofrece
    diferentes operaciones de lectura y escritura para los datos del Torneo.
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
  Torneo(string nombre_torneo, int id_categ);

  // Modificadoras

  /** @brief Confecciona el cuadro de resultados

      \pre <em>Cierto</em>
      \post Se crea el arbol binario con los resultados
  */
  void confeccionar_cuadro_resultados();

  // Consultoras

  /** @brief Consulta el nombre del Torneo

      \pre <em>Cierto</em>
      \post Devuelve el nombre del Torneo
  */
  string consultar_nombre() const;

  /** @brief Consulta si se ha disputado el Torneo

      \pre <em>Cierto</em>
      \post Devuelve true si se ha disputado y false si no.
  */
  bool torneo_disputado() const;

  /** @brief Consulta los jugadores que han disputado el Torneo

      \pre <em>Cierto</em>
      \post El resultado es un vector de ints correspondiente a los jugadores que han disputado el Torneo
  */
  vector<int> consultar_jugadores_del_torneo() const;

  // Escritura / Lectura

  /** @brief Operación de lectura de jugadores que disputan el torneo

      \pre <em>Cierto</em>
      \post Se leen los jugadores que van a disputar el Torneo
  */
  void leer_participantes_torneo();

  /** @brief Operación de lectura de resultados del Torneo

      \pre <em>Cierto</em>
      \post Se leen los resultados del Torneo
  */
  void leer_resultados();

  /** @brief Operación de escritura de los datos de un Torneo

      \pre <em>Cierto</em>
      \post Se escriben los datos del Torneo, nombre y categoria
  */
  void escribir_torneo(const Cjt_Categorias &cjt_cat) const;

  /** @brief Operación de escritura de los puntos ganados por cada participante en el Torneo

      \pre <em>Cierto</em>
      \post Se escriben los puntos ganados por cada participante en el orden de ranking anterior a disputarse el Torneo
  */
  void escribir_particip_puntos_ganados() const;

  /** @brief Operación de escritura de los resultados del torneo

      \pre <em>Cierto</em>
      \post Se escriben los resultados del Torneo
  */
  void escribir_resultados_torneo() const;

  // MAL !!!
  // Cuadro emparejamientos:
  BinTree<int> confeccionar_cuadro_emparejamientos(int n, int &nivel_actual, int m, int altura, int pot2nivel);
  void escribir_cuadro_emparejamientos();
private:
  string nombre;
  int categ;
  bool disputado;
  vector<int> jugadores_del_torneo; // vector de ints que equivalen al ranking de cada jugador
  // BinTree's de los cuadros de emparejamientos y resultados del Torneo (todavia no se que dato)
  BinTree<int> cuadro_emparejamientos;  // no haría falt
  // BinTree<T> resultados;
};

#endif
