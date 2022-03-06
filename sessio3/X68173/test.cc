#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

// DONE ¿?

int main() {
  Cjt_estudiants Cest;
  Cest.llegir();

  //Cest.esborrar_estudiant(333);
  cout << "--------------------" << endl;
  Cest.escriure();
  cout << "--------------------" << endl;
  cout << Cest.estudiant_nota_max().consultar_DNI() << endl;
  cout << Cest.estudiant_nota_max().consultar_nota() << endl;
  cout << "--------------------" << endl;
  Estudiant Est(313);
  // Est.afegir_nota(4);
  Cest.afegir_estudiant(Est);
  Estudiant Est2(222);
  Est2.afegir_nota(5);
  Estudiant Est3(111);
  Est3.afegir_nota(5);
  Estudiant Est4(444);
  Est4.afegir_nota(5);
  Cest.afegir_estudiant(Est2);
  Cest.afegir_estudiant(Est3);
  Cest.afegir_estudiant(Est4);

  cout << Cest.estudiant_nota_max().consultar_DNI() << endl;
  cout << Cest.estudiant_nota_max().consultar_nota() << endl;
  cout << "--------------------" << endl;

  Cest.esborrar_estudiant(111);
  cout << Cest.estudiant_nota_max().consultar_DNI() << endl;
  cout << Cest.estudiant_nota_max().consultar_nota() << endl;
  cout << "--------------------" << endl;
  Cest.escriure();
}
