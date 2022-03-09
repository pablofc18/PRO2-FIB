#include "CuaIOParInt.hh"

int main() {
  ParInt p;
  queue<ParInt> c1;
  queue<ParInt> c2;
  int sum_t1 = 0; int sum_t2 = 0;
  while (p.llegir()) {
    if (sum_t1 <= sum_t2) {
      c1.push(p);
      sum_t1 += p.segon();
    }
    else {
      c2.push(p);
      sum_t2 += p.segon();
    }
  }
  escriureCuaParInt(c1);
  cout << endl;
  escriureCuaParInt(c2);
}
