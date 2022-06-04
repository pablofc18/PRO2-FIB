#include "LlistaIOint.hh"

int main() {
    Llista<int> l;
    
    llegir_llista_int(l, 0);

    escriure_llista_int(l);

    l.inici();
    if (not l.dreta_de_tot()) l.avanca();
    if (not l.dreta_de_tot()) l.avanca();
    if (not l.dreta_de_tot()) cout << l.actual();
    cout << "mida" << l.mida();

    l.esborrar_tots(3);

    if (not l.dreta_de_tot()) cout << l.actual();
    cout << "mida" << l.mida();

    escriure_llista_int(l);
}