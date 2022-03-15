#include "LlistaIOEstudiant.hh"

void LlegirLlistaEstudiant(list<Estudiant>& l)
// Pre: l és buida; el canal estandar d’entrada conté parelles
// de valors <enter, double>, acabat per un parell 0 0
// Post: s’han afegit al final de l els estudiants llegits fins al 0 0 (no inclòs)
{
  Estudiant Est;
  Est.llegir();
  while (Est.consultar_nota() != 0 and Est.consultar_DNI() != 0) {
    l.push_back(Est);
    Est.llegir();
  }
}

void EscriureLlistaEstudiant(list<Estudiant>& l) //(opcional)
// Pre: cert
// Post: s’han escrit al canal estandar de sortida els elements de l
{
  list<Estudiant>::const_iterator it = l.begin();
  while (it != l.end()) {
    it -> escriure();
    ++it;
  }
}
