T maxim() const
/* Pre: el p.i. no és buit */
/* Post: el resultat indica el valor més gran que conté el p.i. */
{
    return i_maxim(primer_node)->info;
}

private:

static node_arbreNari* i_maxim(node_arbreNari* n)
// Pre: n = primer_node
// Post: retorna el node amb valor més gran
{
    node_arbreNari* max = n;
    int arit = (n->seg).size();
    for (int i = 0; i < arit; ++i) {
        if (n->seg[i] != nullptr) {
            node_arbreNari* aux = i_maxim(n->seg[i]);
            if (aux->info > max->info) max = aux;           
        }
    }
    return max;
}