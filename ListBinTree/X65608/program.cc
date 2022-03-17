#include "BinTreeIOEst.hh"
#include <list>
#include <queue>


void buscar_estud(const BinTree<Estudiant> &a, bool &found, int &mida, const Estudiant &Est)
//Pre: existeix Est en a
//Post: modifica valor de prof i nota
{
  if (a.empty()) found = false;

  else if (Est.consultar_DNI() == a.value().consultar_DNI()) {
    if ((Est.te_nota() and a.value().te_nota()) and Est.consultar_nota() == a.value().consultar_nota()) {
      found = true;
    }
    else if (not Est.te_nota() and not a.value().te_nota()) {
      found = true;
    }
    else {
      found = false;
    }
  }

  else {
    buscar_estud(a.left(), found, mida, Est);
    if (not found) buscar_estud(a.right(), found, mida, Est);
    if (found) ++mida;
  }
}

list<Estudiant> rec_amplada(const BinTree<Estudiant> &a)
//Pre: cert
//Post: devuelve lista de elementos del arbol en orden amplitud
{
  list<Estudiant> l;
  if (not a.empty()) {
    queue< BinTree<Estudiant> > c;
    c.push(a);
    while (not c.empty()) {
      BinTree<Estudiant> aux = c.front();
      c.pop();
      l.push_back(aux.value());
      if (not aux.left().empty()) c.push(aux.left());
      if (not aux.right().empty()) c.push(aux.right());
    }
  }
  return l;
}

bool search_list(const list<Estudiant> &l, int dni, Estudiant &Est)
//Pre: lista no vacía
//Post: true si el dni se encuentra en la lista y devuelve por referencia Est
{
  list<Estudiant>::const_iterator it = l.begin();
  while (it != l.end()) {
    if (it->consultar_DNI() == dni) {
      Est = *it;
      return true;
    }
    ++it;
  }
  return false;
}

int main() {
  BinTree<Estudiant> a;
  read_bintree_est(a);

  list<Estudiant> l = rec_amplada(a);
  int dni;
  while (cin >> dni) {
    bool found;
    int mida = 0;

    Estudiant Est;
    if (search_list(l, dni, Est)) {
      buscar_estud(a, found, mida, Est);
      if (Est.te_nota()) cout << dni << ' ' << mida << ' ' << Est.consultar_nota() << endl;
      else cout << dni << ' ' << mida << ' ' << -1 << endl;
    }
    else cout << dni << ' ' << -1 << endl;
  }
}
