 void sub_arrel(Arbre& asub, const T& x)
 /* Pre: p.i. = A, asub es buit */
 /* Post: si A conte x, asub es el subarbre d'A resultat de la cerca;
    si A no conte x, asub es buit */
{
    int nivel = 1; int nivel_asub = 0;
    node_arbre* pm_asub = nullptr;
    i_sub_arrel(primer_node, pm_asub, nivel_asub, x, nivel);
    asub.primer_node = pm_asub;
}

private:

static void i_sub_arrel(node_arbre* n, node_arbre*& pm_asub, int &nivel_asub, const T& x, int nivel) 
{
    if (n != nullptr) {
        if (n->info == x and nivel_asub == 0) {
            nivel_asub = nivel;
            pm_asub = copia_node_arbre(n);
        }
        else if (n->info == x) {
            if (nivel < nivel_asub) pm_asub = copia_node_arbre(n);
        }
        i_sub_arrel(n->segE, pm_asub, nivel_asub, x, nivel+1); 
        i_sub_arrel(n->segD, pm_asub, nivel_asub, x, nivel+1);
    }
}