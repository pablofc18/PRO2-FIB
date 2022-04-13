/** @file Torneo.hh
    @brief Especificación de la clase Torneo
*/

#ifndef _TORNEO_HH
#define _TORNEO_HH

#include "Categoria.hh"

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

  // Consultoras

  // Escritura / Lectura

  /** @brief Operación de lectura de un Torneo

      \pre <em>Cierto</em>
      \post Se lee el nombre y la categoria del torneo
  */
  void leer_torneo();

  /** @brief Operación de escritura de los datos de un Torneo

      \pre <em>Cierto</em>
      \post Se escriben los datos del Torneo, nombre y categoria
  */
  void escribir_torneo() const;

private:
  string nombre;
  Categoria categ;
};

#endif
