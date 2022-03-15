#include "LlistaIOEstudiant.hh"

void apariciones_estudiant(const list<Estudiant> &l, int dni, int &count)
/*Pre: llista no buida
Post: conta les aparicions de dni en count*/
{
  list<Estudiant>::const_iterator it = l.begin();
  while (it != l.end()) {
    if (it->consultar_DNI() == dni) ++count;
    ++it;
  }
}

int main() {
  list<Estudiant> l;
  LlegirLlistaEstudiant(l);
  int dni; cin >> dni;
  int count = 0;
  apariciones_estudiant(l, dni, count);
  cout << dni << ' ' << count << endl;
}
