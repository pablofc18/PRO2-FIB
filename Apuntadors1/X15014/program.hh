void arb_sumes(Arbre<int> &asum) const
/* Pre: cert */
/* Post: l'arbre asum Ã©s l'arbre suma del p.i. */
{
  asum.primer_node = i_arb_sumes(primer_node);
}

private:

static node_arbre* i_arb_sumes(node_arbre* m)
{
  node_arbre* n;
  if (m == nullptr) n = nullptr;
  else {
    n = new node_arbre;
    n->info = m->info;
    n->segE = i_arb_sumes(m->segE);
    if (n->segE != nullptr) n->info += (n->segE)->info;
    n->segD = i_arb_sumes(m->segD);
    if (n->segD != nullptr) n->info += (n->segD)->info; 
  }
  return n;
}