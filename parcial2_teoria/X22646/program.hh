void trenat(Cua &c)
 /* Pre: p.i. = C1, c = C2 */
 /* Post: el p.i. passa a ser el resultat de trenar C1 i C2; c passa a ser buida */
{
    if (primer_node == nullptr and c.primer_node != nullptr) {
        primer_node = c.primer_node;
        ultim_node = c.ultim_node;
        longitud = c.longitud;
    }
    else {
        node_cua* aux_ini = primer_node;
        node_cua* aux_inic = c.primer_node;
        node_cua* aux = nullptr;
        node_cua* aux2 = nullptr;
        while (aux_ini != nullptr and aux_inic != nullptr) {
            aux = aux_ini->seguent;
            aux2 = aux_inic->seguent;
            aux_ini->seguent = aux_inic;
            aux_inic->seguent = aux;

            aux_ini = aux;
            if (aux != nullptr) aux_inic = aux2;
        }

        if (aux == nullptr and aux2 != nullptr) {
            while (aux2 != nullptr) {
                aux_inic->seguent = aux2;
                aux_inic = aux2;
                aux2 = aux2->seguent;
            }
            ultim_node = c.ultim_node;
        }
        longitud += c.longitud;
    }
    // Borrar c
    c.ultim_node = nullptr;
    c.primer_node = nullptr;
    c.longitud = 0;
}