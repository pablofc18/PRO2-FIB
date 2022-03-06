#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
{
  int i = nest-1;
  bool found = true;
  int dni = est.consultar_DNI();
  int j = cerca_dicot(vest, )
  if (not b) {

    while (i >= 0 and found) {
      if (dni > vest[i].consultar_DNI()) found = true;
      else {
        v[i+1] = v[i];
        --i;
      }
    }
    v[i+1] = est;
    ++nest;
    if (est.te_nota()) {
      ++nest_amb_nota;
      suma_notes += est.consultar_nota();
    }
  }

}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
{
  int i = cerca_dicot(vest, 0, nest-1, dni);
}
