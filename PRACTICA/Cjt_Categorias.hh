/** @file Cjt_Categorias.hh
    @brief Especificación de la clase Cjt_Categorias
*/

#ifndef _CJT_CATEGORIAS_HH_
#define _CJT_CATEGORIAS_HH_

#include "Categoria.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Cjt_Categorias
    @brief Representa el conjunto de las Categorias del torneo

    Dispone de diferentes operaciones de consulta, lectura y escritura de los
    diferentes atributos del conjunto de categorias.

*/

class Cjt_Categorias
{
public:
  // Constructora

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar Cjt_Categorias
      \pre <em>Cierto</em>
      \post El resultado es un conjunto de Cateogorias sin inicializar
  */
  Cjt_Categorias();

  // Consultoras

  /** @brief Consulta si la categoria es correcta

      \pre <em>Cierto</em>
      \post El resultado indica si la categoria es correcta o no
  */
  bool es_correcta_categoria(int id_categ);

  /** @brief Consulta la matriz de puntos por Categoria y nivel

      \pre <em>Cierto</em>
      \post El resultado es la matriz de puntos por categoria y nivel
  */
  vector< vector<int> > consultar_puntos_categ_nivel() const;

  // Escritura / Lectura

  /** @brief Operación de lectura de Categorias y máximo de niveles

      \pre <em>Cierto</em>
      \post Se leen y almacenan las Categorias en el vector de Categorias y el máximo de niveles
  */
  void leer_categorias_niveles();

  /** @brief Operación de lectura de los puntos por categoria

      \pre <em>Cierto</em>
      \post Se leen y almacenan los puntos en el vector de puntos por categoria y nivel
  */
  void leer_puntos_por_categoria_nivel();

  /** @brief Operación de escritura de la lista de categorias junto con la tabla de puntos

      \pre <em>Cierto</em>
      \post Se escribe por orden creciente de identificador, el nombre y la tabla de puntos
            por niveles de cada categoria del circuito
  */
  void escribir_categorias_puntos() const;

private:
  int num_max_niveles;
  int total_categorias;
  vector<Categoria> cjt_Categorias; // Tamaño: total_categorias
  vector< vector<int> > puntos_por_categoria_nivel; // Tamaño: num_max_niveles * total_categorias
};

#endif
