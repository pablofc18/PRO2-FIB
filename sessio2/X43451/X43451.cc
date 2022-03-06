#include <vector>
#include "Estudiant.hh"

void arrodonir_vector(vector<Estudiant>& v)
/* Pre: cert */
/* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
 a la decima mes propera */
{
  int vec_size = v.size();
  int i = 0;
  while (i < vec_size) {
    if (v[i].te_nota()) v[i].modificar_nota(((int) (10. * (v[i].consultar_nota() + 0.05))) / 10.0);
    ++i;
  }
}
