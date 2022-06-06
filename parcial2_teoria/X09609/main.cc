#include "ArbIOint.hh"

int main() {
    Arbre<int> a;
    llegir_arbre_int(a,0);
    escriure_arbre_int(a);
    cout << endl << "-------------------" << endl;
    Arbre<int> b;
    a.sub_arrel(b,6);
    escriure_arbre_int(b);
}