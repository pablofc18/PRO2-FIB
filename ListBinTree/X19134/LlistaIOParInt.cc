#include "LlistaIOParInt.hh"

void LlegirLlistaParInt(list<ParInt>& l)
// Pre: l és buida; el canal estandar d’entrada conté un nombre
// parell d’enters, acabat pel parell 0 0
// Post: s’han afegit al final de l els parells llegits fins al 0 0 (no inclòs)
{
  ParInt p;
  while (p.llegir()) {
    l.push_back(p);
  }
}


void EscriureLlistaParInt(const list<ParInt>& l) //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
{
  for (list<ParInt>::const_iterator it = l.begin(); it != l.end(); ++it)
    it->escriure();
}
