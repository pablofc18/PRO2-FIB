#include "BinTree.hh"
#include <iostream>


bool poda_subarbre(BinTree<int> &a, int x)
{
  if (a.empty()) return false;
  else if (a.value() == x) {
    a = BinTree<int>();
    return true;
  }
  else {
    BinTree<int> l = a.left();
    BinTree<int> r = a.right();
    bool found = poda_subarbre(l, x);
    if (not found) found = poda_subarbre(r, x);
    a = BinTree<int>(a.value(), l, r);
    return found;
  }
}

// void llegir_bintree(BinTree<int> &a)
// {
//   int x; cin >> x;
//   if (x != 0) {
//     BinTree<int> l;
//     llegir_bintree(l);
//     BinTree<int> r;
//     llegir_bintree(r);
//     a = BinTree<int>(x, l, r);
//   }
// }
//
// void escribirarbol(const BinTree<int> &a)
// {
//   if (not a.empty()) {
// 		int x = a.value();
// 		escribirarbol(a.left());
// 		cout << " " << x;
// 		escribirarbol(a.right());
//   }
// }
//
// int main() {
//   BinTree<int> a;
//   llegir_bintree(a);
//   int n;
//   cout << "-................................-" << endl;
//   while (cin >> n) {
//     //cout << poda_subarbre(a, n);
//     poda_subarbre(a, n);
//     escribirarbol(a);
//   }
// }
