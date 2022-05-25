#include "ArbNIOint.hh"

int main() {
    ArbreNari<int> a(2);
    llegir_arbre_int(a,0);
    escriure_arbre_int(a);
    cout << endl << a.maxim() << endl;
}