/** @file Categoria.hh
    @brief Especificación de la clase Categoria
*/

#ifndef _CATEGORIA_HH_
#define _CATEGORIA_HH_

#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif


/** @class Categoria
    @brief Representa la Categoria de un torneo

    Dispone de dos atributos, nombre y identificador, y de diferentes operaciones
    como escritura de sus datos o consulta.

*/

class Categoria
{
public:
  // Constructoras

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar Categoria
      \pre <em>Cierto</em>
      \post El resultado es una Cateogoria sin inicializar
  */
  Categoria();

  /** @brief Creadora con id de Categoria

      \pre El valor de id es correcto
      \post El resultado es una Cateogoria con el id inicializado
  */
  Categoria(int id);

  // Consultoras

  /** @brief Consultora del id de la Categoria

      \pre <em>Cierto</em>
      \post El resultado es el id de la Categoria
  */
  int consultar_id_categ() const;

  /** @brief Consultora del nombre de la Categoria

      \pre <em>Cierto</em>
      \post El resultado es el nombre de la Categoria
  */
  string consultar_nombre_categ() const;

  // Escritura / Lectura

  /** @brief Operación de escritura de una Categoria

      \pre <em>Cierto</em>
      \post Se esriben los datos de una Categoria
  */
  void escribir_categ() const;

private:
  string nombre;
  int id;
};

#endif
