#include "BinTreeIOParInt.hh"
#include <iostream>

void buscar(bool &found, BinTree<ParInt> A, int n, int count)
{
  if (A.value().primer() != 0 and A.value().segon() != 0) {
    found = A.value().primer() == n;
    if (found) cout << n << " " << A.value().segon() << " " << count << endl;
    else {
      buscar(found, A.left(), n, count+1);
      if (not found) buscar(found, A.right(), n, count+1);
    }
  }
}

int main() {
  BinTree<ParInt> A;
  read_bintree_parint(A);
  int num, count = 0;
  bool found;
  while (cin >> num) {
    buscar(found, A, num, count);
    if (not found) cout << -1 << endl;
  }
}
