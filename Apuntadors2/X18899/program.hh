void arbsuma(ArbreNari& asum) const
/* Pre: cert */
/* Post: asum és un arbre amb la mateixa estructura que el p.i.
         i cada node és la suma del node corresponent al p.i
         i tots els seus descendents al p.i. */
{
    int sum;
    asum.primer_node = i_arbsuma(primer_node, sum);
}

private:

static node_arbreNari* i_arbsuma(node_arbreNari* m, int &sum)
{
    node_arbreNari* n;
    if (m == nullptr) {
        n = nullptr;
        sum = 0;
    }
    else {
        n = new node_arbreNari;
        n->seg = vector<node_arbreNari*>(m->seg.size());
        sum = m->info;
        int ari = m->seg.size();
        for (int i = 0; i < ari; ++i) {
            if (m->seg[i] != nullptr) {
                int sum2;
                n->seg[i] = i_arbsuma(m->seg[i], sum2);
                sum += sum2;
            }
        }
        n->info = sum;
    }
    return n;

}