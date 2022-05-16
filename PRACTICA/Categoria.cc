/** @file Categoria.cc
    @brief Código de la clase Categoria
*/

#include "Categoria.hh"

Categoria::Categoria()
{
  id = 0;
}

Categoria::Categoria(int id_categ)
{
  id = id_categ;
}

Categoria::Categoria(string nombre_categ, int id_categ)
{
  nombre = nombre_categ;
  id = id_categ;
}

string Categoria::consultar_nombre_categ() const
{
  return nombre;
}
