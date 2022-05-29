#include "ArbGIOint.hh"

int main() {
    ArbreGen<int> a;
    llegir_arbre_int(a, 0);
    cout << a.freq(3);
}