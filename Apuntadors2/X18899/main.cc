#include "ArbNIOint.hh"

int main() {
    ArbreNari<int> a(3);
    llegir_arbre_int(a,0);
    ArbreNari<int> b(3);
    b = a;
    b.arbsuma(a);
    escriure_arbre_int(a);
    cout << "---------------\n";
    escriure_arbre_int(b);
}