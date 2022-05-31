#include "CuaIOint.hh"

int main() {
    Cua<int> c;
    llegir_cua_int(c, 0);
    Cua<int> c2;
    llegir_cua_int(c2, 0);
    c.trenat(c2);
    escriure_cua_int(c);
}