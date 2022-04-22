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

// Inútil ???????
int Categoria::consultar_id_categ() const
{
  return id;
}

string Categoria::consultar_nombre_categ() const
{
  return nombre;
}

// Es lo mismo que consultar nombre !!!!!!!!!!!!!
// void Categoria::escribir_categ() const      /////
// {                                           /////
//   cout << nombre;                           /////
// }                                           /////
/////////////////////////////////////////////////
