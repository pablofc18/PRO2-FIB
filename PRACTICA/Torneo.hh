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

      \pre Nombre no repetido, categoria válida
      \post El resultado es un Torneo con su nombre y su categoria correspondiente
  */
  Torneo(string nombre_torneo, int id_categ);

  // Modificadoras

  /** @brief Inicia el torneo

      \pre <em>Cierto</em>
      \post Inicia el torneo generando los emparejamientos y escribiéndolos
  */
  void iniciar_torneo(const Cjt_Jugadores &cjt_jug);

  /** @brief Finaliza el torneo

      \pre <em>Cierto</em>
      \post Finaliza el torneo leyendo los resultados, generando el arbol de resultados y escribiéndolo, además de los puntos que gana cada jugador
  */
  void finalizar_torneo(Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat);

  /** @brief Asigna el atributo de torneo disputado a true

      \pre El atributo está en false
      \post El atributo pasa a estar a true
  */
  void torneo_ya_disputado();

  /** @brief Resta los puntos al eliminar un torneo

      \pre <em>Cierto</em>
      \post Resta los puntos de ese torneo que hizo cada jugador que participó
  */
  void restar_puntos_torneo(Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat);

  /** @brief Resta los puntos a los jugadores que participaron en la edición anterior pero no en la más reciente

      \pre <em>Cierto</em>
      \post Se restan los puntos a los jugadores que participaron en la anterior edición pero no la más reciente
  */
  void restar_edicion_no_jugada(Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat);

  /** @brief Borra el registro de ese jugador en el torneo

      \pre el nombre existe en nuestro registro de jugadores
      \post Elimina el registro de ese jugador en el torneo
  */
  void borrar_registro_jug(string nombre_jug);

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

  // Escritura / Lectura

  /** @brief Operación de escritura de los datos de un Torneo

      \pre <em>Cierto</em>
      \post Se escriben los datos del Torneo, nombre y categoria
  */
  void escribir_torneo(const Cjt_Categorias &cjt_cat) const;

private:
  /** @brief Nombre del torneo */
  string nombre;
  /** @brief identificador de la categoria */
  int categ;
  /** @brief Indica si se ha disputado el torneo anteriormente (true) o no (false) */
  bool disputado;

  /** @brief Estructura que tendrán los vectores de los jugadores que participan/aron en el torneo */
  struct Jugador_de_Torneo {
    /** @brief Nombre del jugador */
    string nombre_jug;
    /** @brief Posición del ranking*/
    int rank;
    /** @brief Nivel que consigue al finalizar el torneo, equivalente a los puntos que obtendrá el jugador */
    int nivel;
  };
  /** @brief Vector de los jugadores que están participando en el torneo */
  vector<Jugador_de_Torneo> jugadores_del_torneo;
  /** @brief Vector de los jugadores que participaron en la edición anterior del torneo, solo se utiliza si se disputa por segunda vez el mismo torneo */
  vector<Jugador_de_Torneo> jugadores_del_torneo_anterior;

  /** @brief Asigna el vector de jugadores del torneo a otro vector y vacía el ya utilizado

      \pre No está vacío el vector, torneo se disputa por segunda vez
      \post Guarda los jugadores del torneo en jugadores_del_torneo_anterior y modifica el de jugadores_del_torneo
  */
  void asignar_jugadores_anterior_torneo();

  /** @brief Estructura del cuadro de emparejamientos */
  BinTree<int> cuadro_emp;

  /** @brief Operación de lectura de jugadores que disputan el torneo

      \pre <em>Cierto</em>
      \post Se leen los jugadores que van a disputar el Torneo, devuelve por referencia el numero de participantes
  */
  void leer_participantes_torneo(const Cjt_Jugadores &cjt_jug);

  /* @brief Confecciona el cuadro de emparejamientos

      \pre n = numero participantes, val = valor de cada nodo del arbol, pot2nivel = número nodos por nivel
      \post Devuelve un BinTree con el cuadro de emparejamientos
  **/
  BinTree<int> confeccionar_cuadro_emparejamientos(int n, int val, int pot2nivel);

  /* @brief Operación de escritura del cuadro de emparejamientos

      \pre <em>Cierto</em>
      \post Se escriben los emparejamientos del torneo
  **/
  void escribir_cuadro_emparejamientos(const BinTree<int> &cuadro_emp) const;

  /** @brief Operación de lectura de resultados del Torneo

      \pre El arbol del parámetro está vacío
      \post Se leen los resultados del Torneo
  */
  void leer_resultados(BinTree<string> &resultados_partidos);

  /** @brief Confecciona el cuadro de resultados

      \pre El arbol cuadro_res está inicialmente vacío
      \post Se confecciona el arbol de resultados en cuadro_res
  */
  void confeccionar_cuadro_resultados(const BinTree<string> &results, const BinTree<int> &cuadro_emp, BinTree< pair<pair<int,int>, string> > &cuadro_res, Cjt_Jugadores &cjt_jug);

  /** @brief Crea un arbol a partir de los emparejamientos y los resultados

      \pre nivel = 1, emparej = cuadro_emp
      \post Crea un BinTree igual que el de emparejamientos pero cada nodo no hijo tiene el ganador del partido disputado
  */
  void modificar_cuadro_emparej_con_results(const BinTree<string> &results, int nivel, BinTree<int> &emparej);

  /** @brief Operación de escritura de los resultados del torneo

      \pre <em>Cierto</em>
      \post Se escriben los resultados del Torneo
  */
  void escribir_resultados_torneo(const BinTree< pair<pair<int,int>, string> > &cuadro_res) const;

  /** @brief Operación de escritura de los puntos ganados por cada participante en el Torneo

      \pre <em>Cierto</em>
      \post Se escriben los puntos ganados por cada participante en el orden de ranking anterior a disputarse el Torneo
  */
  void escribir_particip_puntos_ganados(const Cjt_Categorias &cjt_cat, Cjt_Jugadores &cjt_jug);

  /** @brief Consulta los puntos del jugador en la edición anterior

      \pre El jugador ya ha disputado una edición anterior, nombre válido
      \post Devuelve los puntos que hizo en dicha edición
  */
  int consultar_puntos_edicion_anterior(string nombre_jug, const Cjt_Categorias &cjt_cat);

};

#endif
