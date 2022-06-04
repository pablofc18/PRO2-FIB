 void esborrar_tots(const T& x)
 /* Pre: parametre implicit = P */
 /* Post: s'han eliminat del parametre implicit totes les aparicions d'x (la
    resta d'elements queda en el mateix ordre que a P); si el punt d'interes de P
    referenciava a una aparicio d'x, passa a referenciar al primer element
    diferent d'x posterior a aquesta (si no hi ha cap element diferent d'x, passa
    a la dreta el tot); en cas contrari, el punt d'interes no canvia */
{
    node_llista* n = primer_node;
    int count_esborrados = 0;

    while (n != nullptr) {
        if (n->info == x and n == primer_node and n == ultim_node) {
            primer_node = nullptr;
            ultim_node = nullptr;
            act = nullptr;
            delete n;
            ++count_esborrados;
        }
        else if (n->info == x and n == primer_node) {
            primer_node = n->seg;
            (n->seg)->ant = nullptr;
            if (act == n) act = n->seg;
            node_llista* aux = n->seg;
            delete n;
            n = aux;
            ++count_esborrados;
        }
        else if (n->info == x and n == ultim_node) {
            ultim_node = n->ant;
            (n->ant)->seg = nullptr;
            if (act == n) act = n->seg;
            node_llista* aux = n->seg;
            delete n;
            n = aux;
            ++count_esborrados;
        }
        else if (n->info == x) {
            (n->ant)->seg = n->seg;
            (n->seg)->ant = n->ant;
            if (act == n) act = n->seg;
            node_llista* aux = n->seg;
            delete n;
            n = aux;
            ++count_esborrados;
        }
        else n = n->seg;
    }
    longitud -= count_esborrados;
}
