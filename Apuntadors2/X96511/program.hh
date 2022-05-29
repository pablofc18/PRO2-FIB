int freq(const T& x) const
/* Pre: cert */
/* Post: el resultat indica el nombre d'aparicions de x en el p.i. */
{
    int frq = 0;
    i_freq(primer_node, x, frq);
    return frq;
}

private:

static void i_freq(node_arbreGen* n, const T& x, int &frq)
{
    if (n != nullptr) {
        if (n->info == x) ++frq;
        int ari = n->seg.size();
        for (int i = 0; i < ari; ++i) {
            i_freq(n->seg[i], x, frq);
        }
    }
} 