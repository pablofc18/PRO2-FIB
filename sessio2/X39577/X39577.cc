#include "Estudiant.hh"
#include <vector>


void seleccionar_asig(vector<bool> &A, int asig_selec)
/*Pre: recibe vector de bool y el numero de asignaturas*/
/*Post: modifica el vector segun las asignaturas seleccionadas -> TRUE*/
{
  for (int i = 0; i < asig_selec; ++i) {
    int pos;
    cin >> pos;
    A[pos - 1] = true;
  }
}

void llegir_est(vector<Estudiant> &v, const vector<bool> &A, int num_asig, int asig_selec)
/*Pre: recibe vector numero estudiantes, asignaturas y seleccionadas*/
/*Post: modifica el vector estudiantes con la nota media ya hecha*/
{
  for (int i = 0; i < v.size(); ++i) {
    int dni;
    cin >> dni;
    Estudiant tmp(dni);
    v[i] = tmp;

    //Media de notas que queremos
    double media = 0;
    for (int i = 0; i < num_asig; ++i) {
      double notas;
      cin >> notas;
      if (A[i]) media += notas;
    }
    media /= asig_selec;
    v[i].afegir_nota(media);
  }
}

void escribir_vec(const vector<Estudiant> &v)
/*Pre: recibe el vector de estudiantes*/
/*Post: outputs el vector, dni y nota*/
{
  for (int i = 0; i < v.size(); ++i) v[i].escriure();
}


int main() {
  int num_estud, num_asig, asig_selec;
  cin >> num_estud >> num_asig >> asig_selec;
  vector<bool> A(num_asig, false);
  seleccionar_asig(A, asig_selec);

  vector<Estudiant> v(num_estud);
  llegir_est(v, A, num_asig, asig_selec);

  escribir_vec(v);
}
