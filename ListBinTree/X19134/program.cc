#include "ParInt.hh"
#include "LlistaIOParInt.hh"

void calcular(const list<ParInt> &l, int n, int &count, int &sum_second)
/*Pre: lista no vacía
Post: count cuenta las apariciones de n y sum_second suma los numeros de la
      pareja que acompañan al numero n*/
{
  list<ParInt>::const_iterator it = l.begin();
  while (it != l.end()) {
    if (it->primer() == n) {
      ++count;
      sum_second += it->segon();
    }
    ++it;
  }
}

int main() {
  //int n;
  list<ParInt> L;
  LlegirLlistaParInt(L);
  int n; cin >> n;
  int count = 0, sum_second = 0;
  calcular(L, n, count, sum_second);
  cout << n << ' ' << count << ' ' << sum_second << endl;
}
