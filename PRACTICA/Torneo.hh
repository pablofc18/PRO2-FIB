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

  /* @brief Confecciona el cuadro de emparejamientos

      \pre n = numero participantes, val = valor de cada nodo del arbol, pot2nivel = número nodos por nivel
      \post Devuelve un BinTree con el cuadro de emparejamientos
  **/
  BinTree<int> confeccionar_cuadro_emparejamientos(int n, int val, int pot2nivel);

  /** @brief Confecciona el cuadro de resultados

      \pre <em>Cierto</em>
      \post Crea un BinTree con los resultados: cuadro_res
  */
  void confeccionar_cuadro_resultados(const BinTree<string> &results, const BinTree<int> &cuadro_emp, BinTree< pair<pair<int,int>, string> > &cuadro_res);

  /** @brief Asigna el BinTree parametro implícito el arbol por pasado por parametro

      \pre <em>Cierto</em>
      \post cuadro_emp = cuadro_emparejamientos
  */
  void asignar_cuadro_emp(const BinTree<int> &cuadro_emparejamientos);

  /** @brief Crea un arbol a partir de los emparejamientos y los resultados

      \pre <em>Cierto</em>
      \post Crea un BinTree igual que el de emparejamientos pero cada nodo no hijo tiene el ganador del partido disputado
  */
    void modificar_cuadro_emparej_con_results(const BinTree<string> &results, int nivel, BinTree<int> &emparej);

  /** @brief Asigna el atributo de torneo disputado a true

      \pre El atributo está en false
      \post El atributo pasa a estar a true
  */
  void torneo_ya_disputado();

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
  vector< pair<int,int> > consultar_jugadores_del_torneo() const;

  /** @brief

      \pre <em>Cierto</em>
      \post Devuelve el arbol del cuadro de emparejamientos
  */
  BinTree<int> consultar_emparejamientos();

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
  void leer_resultados(BinTree<string> &resultados_partidos);

  /** @brief Operación de escritura de los datos de un Torneo

      \pre <em>Cierto</em>
      \post Se escriben los datos del Torneo, nombre y categoria
  */
  void escribir_torneo(const Cjt_Categorias &cjt_cat) const;

  /** @brief Operación de escritura de los puntos ganados por cada participante en el Torneo

      \pre <em>Cierto</em>
      \post Se escriben los puntos ganados por cada participante en el orden de ranking anterior a disputarse el Torneo
  */
  void escribir_particip_puntos_ganados(const Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat) const;

  /** @brief Operación de escritura de los resultados del torneo

      \pre <em>Cierto</em>
      \post Se escriben los resultados del Torneo
  */
  void escribir_resultados_torneo(const BinTree< pair<pair<int,int>, string> > &cuadro_res, const Cjt_Jugadores &cjt_jug) const;

  /* @brief Operación de escritura del cuadro de emparejamientos

      \pre <em>Cierto</em>
      \post Se escriben los emparejamientos del torneo
  **/
  void escribir_cuadro_emparejamientos(const BinTree<int> &cuadro_emp, const Cjt_Jugadores &cjt_jug) const;

private:
  string nombre;
  int categ;
  bool disputado;
  vector<pair<int,int> > jugadores_del_torneo; // vector de pair que equivalen al ranking de cada jugador y el nivel para luego los puntos
  // BinTree cuadro emparejamientos
  BinTree<int> cuadro_emp;
  // BinTree cuadro resultados ?¿?¿?¿
  BinTree< pair<pair<int,int>, string> > cuadro_resultados;
};

#endif
