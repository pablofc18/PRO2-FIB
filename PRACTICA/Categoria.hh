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
    como consulta de sus datos.

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
  Categoria(int id_categ);

  /** @brief Creadora con id y nombre de Categoria

      \pre El valor de id es correcto, nombre no repetido
      \post El resultado es una Cateogoria con el id y nombre inicializados
  */
  Categoria(string nombre_categ, int id_categ);

  // Consultoras

  /** @brief Consultora del nombre de la Categoria

      \pre <em>Cierto</em>
      \post El resultado es el nombre de la Categoria
  */
  string consultar_nombre_categ() const;

private:
  /** @brief Nombre de la categoria */
  string nombre;
  /** @brief identificador de la categoria */
  int id;
};

#endif
