
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
#include <iostream>
using namespace std;


double redondear(double r)
{
  return int(10.*(r + 0.05)) / 10.0;
}


void anyadir(Cjt_estudiants &Cest)
/*Pre: objeto Cjt_estudiants
Post: añade un estudiante al conjunto*/
{
  int dni;
  double nota;
  cin >> dni >> nota;
  if (not Cest.existeix_estudiant(dni)) {
    if (Cest.mida() != Cjt_estudiants::mida_maxima()) {
      Estudiant Est(dni);
      if (nota >= 0 and nota <= 10) Est.afegir_nota(nota);
      Cest.afegir_estudiant(Est);
    }
    else cout << "el conjunto esta lleno" << endl << endl;
  }
  else cout << "el estudiante " << dni << " ya estaba" << endl << endl;
}


void modificar(Cjt_estudiants &Cest)
/*Pre: objeto Cjt_estudiants
Post: modifica un estudiante del conjunto*/
{
  int dni;
  double nota;
  cin >> dni >> nota;
  if (Cest.existeix_estudiant(dni)) {
    if (nota >= 0 and nota <= 10) {
      Estudiant Est(dni);
      Est.afegir_nota(nota);
      Cest.modificar_estudiant(Est);
    }
  }
  else cout << "el estudiante " << dni << " no esta" << endl << endl;
}


void consultar(Cjt_estudiants &Cest)
/*Pre: objeto Cjt_estudiants
Post: consulta un estudiante del conjunto*/
{
  int dni;
  cin >> dni;
  if (Cest.existeix_estudiant(dni)) {
    if (Cest.consultar_estudiant(dni).te_nota()) {
      cout << "el estudiante " << dni << " tiene nota "
      << Cest.consultar_estudiant(dni).consultar_nota() << endl << endl;
    }
    else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
  }
  else cout << "el estudiante " << dni << " no esta" << endl << endl;
}


void redondear_cjt(Cjt_estudiants &Cest)
/*Pre: objeto Cjt_estudiants
Post: redondea las notas del conjunto*/
{
  for (int i = 1; i <= Cest.mida(); ++i) {
    if (Cest.consultar_iessim(i).te_nota()) {
      Estudiant Est;
      Est = Cest.consultar_iessim(i);
      Est.modificar_nota(redondear(Est.consultar_nota()));
      Cest.modificar_iessim(i, Est);
    }
  }
}

void menu(Cjt_estudiants &Cest)
/*Pre: recibe el objeto Cjt_estudiants
Post: menu para el usuario*/
{
  int num;
  cin >> num;
  while (num != -6) {
    //Menú de opciones
    //Añadir estudiante
    if (num == -1) {
      anyadir(Cest);
    }
    //Consultar notas a partir de DNI
    else if (num == -2) {
      consultar(Cest);
    }
    //Modificar nota
    else if (num == -3) {
      modificar(Cest);
    }
    //Redondear notas
    else if (num == -4) {
      redondear_cjt(Cest);
    }
    //Escribir cjt estudiantes
    else if (num == -5) {
      Cest.escriure();
      cout << endl;
    }
    cin >> num;
  }
}


int main() {
  Cjt_estudiants Cest;
  Cest.llegir();
  menu(Cest);
}
