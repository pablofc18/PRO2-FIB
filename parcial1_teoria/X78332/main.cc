#include "BinTree.hh"
#include <stack>
// #include "BinTreeIOint.hh"


int mida(const BinTree<int> &a)
{
  if (a.empty()) return 0;
  else return 1 + mida(a.left()) + mida(a.right());
}

void i_cami_preferent(const BinTree<int>& a, stack<int>& c)
{
  
}

void cami_preferent(const BinTree<int>& a, stack<int>& c)
 /* Pre: c esta vacia */
 /* Post: c contiene el camino preferente de a; si no esta vacia, el primer
          elemento del camino esta en la cima de c */
// {
//   if (not a.empty()) {
//     if (mida(a.left())<mida(a.right())) cami_preferent(a.right(), c);
//     else cami_preferent(a.left(), c);
//     c.push(a.value());
//   }
  i_cami_preferent(a, c);
}

// void write_stack(stack<int> p)
// {
//   while(not p.empty()) {
//     cout << p.top();
//     p.pop();
//   }
// }

// int main() {
//   BinTree<int> a;
//   read_bintree_int(a, 0);
//   stack<int> p;
//
//   cami_preferent(a, p);
//   write_stack(p);
//
// }
