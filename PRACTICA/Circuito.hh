/** @file Circuito.hh
    @brief Especificación de la clase Circuito
*/


#ifndef _CIRCUITO_HH_
#define _CIRCUITO_HH_

#include "Torneo.hh"

#ifndef NO_DIAGRAM
#include <vector>
using namespace std;
#endif

/** @class Circuito
    @brief Representa el Circuito de los torneos

Contiene la lista de los torneos...
*/

class Circuito
{
public:
  // Constructora

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Circuito
      \pre <em>Cierto</em>
      \post El resultado es un Circuito sin inicializar
  */
  Circuito();

  // Modificadoras

  /** @brief Da de alta un Torneo

      \pre El párametro implícito no contiene al Torneo t
      \post Se añade el Torneo t a la lista de torneos
  */
  void anadir_torneo(const Torneo &t);

  /** @brief Da de baja un Torneo

      \pre nombre_torneo es un nombre que existe en nuestra lista de torneos
      \post Se elimina el Torneo con nombre nombre_torneo
  */
  void eliminar_torneo(string nombre_torneo);

  /** @brief Inicia un Torneo

      \pre El Torneo existe y no se ha iniciado
      \post Se lee la inscripción del Torneo y se confecciona el cuadro de emparejamientos
  */
  void iniciar_torneo(string nombre_torneo);

  /** @brief Finaliza un Torneo

      \pre El Torneo existe y se ha iniciado
      \post Se lee los resultados del Torneo y se confecciona el cuadro de resultados
  */
  void finalizar_torneo(string nombre_torneo);

  // Consultoras

  /** @brief Consulta si existe el Torneo

      \pre <em>Cierto</em>
      \post El resultado indica si existe o no el Torneo 'nombre_torneo'
  */
  bool existe_torneo(string nombre_torneo) const;

  /** @brief Consulta si se ha disputado el Torneo

      \pre <em>Cierto</em>
      \post El resultado indica si se ha disputado el Torneo 'nombre_torneo'
  */
  bool torneo_disputado(string nombre_torneo) const;

  /** @brief Consultar Torneo con identificador 'nombre_torneo'

      \pre El Torneo con ese nombre existe
      \post El resultado es el Torneo 'nombre_torneo'
  */
  Torneo consultar_torneo(string nombre_torneo) const;

  /** @brief Consulta el total de torneos en la lista

      \pre <em>Cierto</em>
      \post El resultado es el número de torneos totales
  */
  static int numero_torneos_totales();

  // Escritura / Lectura

  /** @brief Operación de lectura de torneos

      \pre <em>Cierto</em>
      \post Se leen y almacenan los torneos en la lista de torneos
  */
  void leer_cjt_torneos();

  /** @brief Operación de escritura de la lista de torneos

      \pre <em>Cierto</em>
      \post Se escribe todos los torneos, en orden creciente de nombre, con su categoria correspondiente
  */
  void escribir_torneos() const;

private:
  vector<Torneo> cjt_torneos;
  // Búsqueda dicotómica para encontrar la posición del torneo
  static int busq_dicot_torneos(const vector<Torneo> &cjt_t, int left, int right, string nombre);
  // Ordenar por nombre creciente
  void ordenar_cjt_torneos();
  static bool sort_vec_torneos(const Torneo &a, const Torneo &b);
};

#endif
