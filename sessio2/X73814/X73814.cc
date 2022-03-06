#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;


void llegir_vector(vector<Estudiant> &v)
/*Pre: recibe el vector que tiene que leer y modificar*/
/*Post: rellena los datos del vector estudiantes*/
{
  int vec_size = v.size();
  for (int i = 0; i < vec_size; ++i) v[i].llegir();
}


vector<Estudiant> eliminar_repetidos(const vector<Estudiant> &v)
/*Pre: recibe parametro constante del vector de entrada*/
/*Post: devuelve el vector eliminando los dni's repetidos y cogiendo la maxima
nota*/
{
  vector<Estudiant> w(v.size());
  int u = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (i != 0 and v[i].consultar_DNI() == v[i - 1].consultar_DNI()) {

      if(v[i].te_nota() and w[u-1].te_nota() and v[i].consultar_nota() > w[u-1].consultar_nota()){
        w[u-1].modificar_nota(v[i].consultar_nota());
      }

      else if(v[i].te_nota() and not w[u-1].te_nota()) {
       w[u-1].afegir_nota(v[i].consultar_nota());
     }

    }
    else {
      w[u] = Estudiant(v[i].consultar_DNI());
      if (v[i].te_nota()) w[u].afegir_nota(v[i].consultar_nota());
      ++u;
    }
  }

  return w;
}


void print_vector(const vector<Estudiant> &v)
/*Pre: recibe el vector que tiene que hacer el output*/
/*Post: escribe el vector de estudiantes*/
{
  int i = 0;
  while (i < v.size() and v[i].consultar_DNI() != 0) {
    v[i].escriure();
    ++i;
  }
}


int main() {
  int num_casos;
  cin >> num_casos;

  vector<Estudiant> v(num_casos);
  llegir_vector(v);

  //vector sin repetidos
  vector<Estudiant> no_repes = eliminar_repetidos(v);
  print_vector(no_repes);
}
