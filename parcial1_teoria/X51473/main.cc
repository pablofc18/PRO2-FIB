#include <iostream>
#include <list>
using namespace std;

void seleccio(const list<double>& l, list<double>& sel)
 /* Pre: l no es vacia, sol es vacia */
 /* Post: sel es el resultado de extraer de l los elementos debiles en media */
{
  double media = 0;
  int count = 0;
  for (list<double>::const_iterator it = l.begin(); it != l.end(); ++it) {
    ++count;
    media += *it;
    if (count != 1) {
      if (*it >= media/count) sel.push_back(*it);
    }
    else sel.push_back(*it);
  }
}

// int main() {
//   list<double> l;
//   double n; cin >> n;
//   while (n != 0) {
//     l.push_back(n);
//     cin >> n;
//   }
//   list<double> nl;
//   seleccio(l, nl);
//   list<double>::const_iterator n_it = nl.begin();
//   while (n_it != nl.end()) {
//     cout << *n_it << endl; ++n_it;
//   }
// }
