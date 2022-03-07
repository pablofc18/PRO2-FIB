#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

// DONE ¿?

int main() {
  Cjt_estudiants Cest;
  Cest.llegir();

  cout << Cest.estudiant_nota_max().consultar_DNI() << endl;
  cout << Cest.estudiant_nota_max().consultar_nota() << endl;
  Cest.escriure();
  cout << "-------------\n";
  Estudiant Est(444);
  Est.afegir_nota(4.3);
  Cest.modificar_estudiant(Est);


  cout << Cest.estudiant_nota_max().consultar_DNI() << endl;
  cout << Cest.estudiant_nota_max().consultar_nota() << endl;
  Cest.escriure();
}
