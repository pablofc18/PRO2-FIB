#include "Cjt_estudiants.hh"
#include "Estudiant.hh"


void modif_nota_a_mes_alta(Cjt_estudiants &A, const Cjt_estudiants &B)
/*Pre: els dos objectes Cjt_estudiants tenen els mateixos estudiants
 Post: cambia la nota del Cjt_estudiants A si és més alta (amb la del B)*/
{
  for (int i = 1; i <= A.mida(); ++i) {
    if (A.consultar_iessim(i).te_nota() and B.consultar_iessim(i).te_nota()) {
      if (A.consultar_iessim(i).consultar_nota() < B.consultar_iessim(i).consultar_nota()) {
        A.modificar_iessim(i, B.consultar_iessim(i));
      }
    }
    else if (not A.consultar_iessim(i).te_nota() and B.consultar_iessim(i).te_nota()) {
      A.modificar_iessim(i, B.consultar_iessim(i));
    }
  }
}

int main() {
  Cjt_estudiants Cjt1, Cjt2;
  Cjt1.llegir();
  Cjt2.llegir();

  modif_nota_a_mes_alta(Cjt1, Cjt2);

  Cjt1.escriure();
}
