#include "BinTreeIOParInt.hh"

void read_bintree_parint(BinTree<ParInt>& a)
// Pre: a és buit; el canal estandar d’entrada conté un nombre
// parell d’enters, que representa un arbre binari en preordre,
// on el parell 0 0 representa un arbre buit
// Post: a conté l’arbre que hi havia al canal estandar d’entrada
{
  ParInt p; p.llegir();
  BinTree<ParInt> bl,br;
  if (p.primer() != 0 and p.segon() != 0) {
    read_bintree_parint(bl);
    read_bintree_parint(br);
  }
  BinTree<ParInt> b(p, bl, br);
  a = b;
}

// void write_bintree_parint(const BinTree<ParInt>& a) // (opcional)
// // Pre: a = A
// // Post: s’han escrit al canal estandar de sortida els elements
// // d’a recorrreguts en inordre, a = A
// {
//
// }
