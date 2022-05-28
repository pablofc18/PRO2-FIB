bool buscar(const T& x) const
/* Pre: cert */
/* Post: el resultat indica si x es troba al p.i. o no */
{
    return i_buscar(primer_node, x);
}

private:

static bool i_buscar(node_arbreGen* n, const T& x)
{
    if (n == nullptr) return false;
    else {
        if (n->info == x) return true;
        int ari = n->seg.size();
        for (int i = 0; i < ari; ++i) {// !!!
            if (i_buscar(n->seg[i], x)) return true;
        }
        return false;
    }
}