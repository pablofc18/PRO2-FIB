#include "BinTree.hh"
// #include "BinTreeIOint.hh"

int alcaria(const BinTree<int> &a)
{
  if (a.empty()) return 0;
  else return 1+max(alcaria(a.left()), alcaria(a.right()));
}

void arbre_graus_desequilibri(const BinTree<int> &a, BinTree<int> &agd)
 /* Pre: a=A */
 /* Post: agd es un arbre amb la mateixa estructura que A on cada
    node conte el grau de desequilibri del subarbre d'A corresponent */
{
  if (not a.empty()) {
    BinTree<int> l = a.left();
    BinTree<int> r = a.right();
    arbre_graus_desequilibri(a.left(), l);
    arbre_graus_desequilibri(a.right(), r);
    agd = BinTree<int>(alcaria(a.left()) - alcaria(a.right()), l, r);
  }
}

// int main() {
//   BinTree<int> a;
//   read_bintree_int(a, 0);
//   cout << endl << "-----------------" << endl;
//   BinTree<int> b;
//   arbre_graus_desequilibri(a, b);
//   write_bintree_int(b);
// //  cout << endl << alcaria(a);
// }
