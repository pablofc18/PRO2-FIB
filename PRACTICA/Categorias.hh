/** @file Categorias.hh
    @brief Especificación de la clase Categorias
*/


#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_

#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Categorias
    @brief Representa las Categorias del torneo

Dispone de blabalbalbala...

*/

class Categorias
{
public:
  // Constructora

  /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar Categorias
      \pre <em>Cierto</em>
      \post El resultado es una Cateogoria sin inicializar
  */
  Categorias();

  // Modificadoras

  // Consultoras

  /** @brief Consulta si la categoria es correcta

      \pre <em>Cierto</em>
      \post El resultado indica si la categoria es correcta o no
  */
  bool es_correcta_categoria(int id_categ);

  // Escritura / Lectura

  /** @brief Operación de lectura de Categorias

      \pre <em>Cierto</em>
      \post Se leen y almacenan las Categorias en el vector de Categorias
  */
  void leer_categorias();

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
  struct Categoria {
    int num_identif;
    string nombre;
  };
  int num_max_niveles;
  int total_categorias;
  vector<Categoria> cjt_Categorias; // Tamaño total_categorias
  vector< vector<int> > puntos_por_categoria_nivel; // Tamaño num_max_niveles * total_categorias
};

#endif
