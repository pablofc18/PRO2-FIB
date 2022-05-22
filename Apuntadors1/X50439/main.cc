//#include "Pila.hh"
#include "PilaIOint.hh"
//#include "program.hh"

int main() {
    Pila<int> p;
    llegir_pila_int(p, 0);
    escriure_pila_int(p);

    // cout << "-----------MODIFIED:-----------" << endl;
    // Pila<int> np(p);
    // escriure_pila_int(np);

}