/** @file Circuito.hh
    @brief Especificación de la clase Circuito
*/


#ifndef _CIRCUITO_HH_
#define _CIRCUITO_HH_

#include "Torneo.hh"


/** @class Circuito
    @brief Representa el Circuito de los torneos

    Dispone de operaciones de modificación, consulta, escritura y lectura del
    conjunto de torneos.
*/

class Circuito
{
public:
  // Constructora

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un Circuito
      \pre <em>Cierto</em>
      \post Declara el objeto vacío no inicializa nada
  */
  Circuito();

  // Modificadoras

  /** @brief Da de alta un Torneo

      \pre El párametro implícito no contiene al Torneo t
      \post Se añade el Torneo t a la lista de torneos
  */
  void anadir_torneo(const Torneo &t);

  /** @brief Da de baja un Torneo

      \pre <em>Cierto</em>
      \post Se elimina el Torneo con nombre 'nombre_torneo' si existe, devolviendo true. Y si no devuelve false
  */
  bool eliminar_torneo(string nombre_torneo, Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat);

  /** @brief Inicia un Torneo

      \pre El Torneo existe y no se ha iniciado
      \post Se lee la inscripción del Torneo y se confecciona el cuadro de emparejamientos
  */
  void iniciar_torneo(string nombre_torneo, const Cjt_Jugadores &cjt_jug);

  /** @brief Finaliza un Torneo

      \pre El Torneo existe y se ha iniciado
      \post Se lee los resultados del Torneo y se confecciona el cuadro de resultados
  */
  void finalizar_torneo(string nombre_torneo, Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat);

  /** @brief Borra el registro que tenga el jugador en los torneos que haya participado

      \pre <em>Cierto</em>
      \post Se eliminan los registros de ese jugador en los torneos que ha disputado
  */
  void borrar_registros_jug_de_torneos(string nombre);

  // Consultoras

  /** @brief Consulta si existe el Torneo

      \pre <em>Cierto</em>
      \post El resultado indica si existe o no el Torneo 'nombre_torneo'
  */
  bool existe_torneo(string nombre_torneo) const;

  /** @brief Consulta el total de torneos en la lista

      \pre <em>Cierto</em>
      \post El resultado es el número de torneos totales
  */
  int numero_torneos_totales() const;

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
  void escribir_torneos(const Cjt_Categorias &cjt_cat) const;

private:
  /** @brief Map del conjunto de torneos */
  map<string, Torneo> cjt_Torneos;
};

#endif
