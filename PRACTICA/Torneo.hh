/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH
#define _TORNEO_HH

#include "Categorias.hh"

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
  Torneo(string nombre_torneo, int id_categ);

  // Modificadoras

  // Consultoras

  // Escritura / Lectura

  /** @brief Operación de lectura de un Torneo

      \pre <em>Cierto</em>
      \post Se lee el nombre y la categoria del torneo
  */
  void leer_torneo();

private:
  string nombre;
  int identif_categoria;
};

#endif
