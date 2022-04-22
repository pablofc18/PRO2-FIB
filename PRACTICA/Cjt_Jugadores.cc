#include "Cjt_Jugadores.hh"

Cjt_Jugadores::Cjt_Jugadores()
{
  // map<int, Jugador> ranking;
  // map<string, Jugador> cjt_jugadores;
}
// Para ordenar el vector de ranking        ¿¿¿¿¿ PÚBLICO ??????
bool comp_rank(const Jugador &p1, const Jugador &p2)
{
  if (p1.consultar_puntos() == p2.consultar_puntos()) {
    return p1.consultar_ranking() < p2.consultar_ranking();
  }
  return p1.consultar_puntos() > p2.consultar_puntos();
}

void Cjt_Jugadores::ordenar_ranking()
{
  sort(ranking.begin(), ranking.end(), comp_rank);
}

void Cjt_Jugadores::anadir_jugador(string nombre_jug)
{
  // Añadirle el ranking y después añadirlo a las estruct. datos
  Jugador p(nombre_jug);
  p.modificar_ranking(cjt_Jugadores.size() + 1);
  cjt_Jugadores[nombre_jug] = p;
  // Ranking
  ranking.push_back(p);
}

void Cjt_Jugadores::eliminar_jugador(string nombre_jug)
{
  // Eliminar el jugador con it, y así a partir de ese iterador hasta el final disminuye ranking en 1 a los jugadores
  map<string, Jugador>::iterator it = cjt_Jugadores.find(nombre_jug);
  // Ranking del jugador eliminado
  int rank_jug_eliminado =  it->second.consultar_ranking();
  cjt_Jugadores.erase(it);
  // Elminar del ranking y modificar ranking en la lista de jugadores
  for (int i = rank_jug_eliminado; i < ranking.size(); ++i) {
    it = cjt_Jugadores.find(ranking[i].consultar_nombre());
    it->second.modificar_ranking(it->second.consultar_ranking() - 1);
    ranking[i-1] = ranking[i];
  }
  // Borrar el último que estará repetido
  ranking.pop_back();
}

// void Cjt_Jugadores::actualizar_ranking(vector< vector<int> > pts_categ_nivel, vector<int> jugadores_del_torneo)
// {
// }

bool Cjt_Jugadores::existe_jugador(string nombre_jug) const
{
  map<string, Jugador>::const_iterator it;
  it = cjt_Jugadores.find(nombre_jug);
  return it != cjt_Jugadores.end();
}

Jugador Cjt_Jugadores::consultar_jugador(string nombre_jug) const
{
  map<string, Jugador>::const_iterator it;
  it = cjt_Jugadores.find(nombre_jug);
  return it->second;
}

Jugador Cjt_Jugadores::consultar_jugador(int rank) const
{
  return ranking[rank-1];
}

int Cjt_Jugadores::numero_jugadores_totales() const
{
  return cjt_Jugadores.size();
}

void Cjt_Jugadores::leer_jugadores()
{
  int num_jugs; cin >> num_jugs;
  for (int i = 0; i < num_jugs; ++i) {
    string nombre_jug; cin >> nombre_jug;
    // Añadirle el ranking y después añadirlo a las estruct. datos
    Jugador p(nombre_jug);
    p.modificar_ranking(i+1);
    cjt_Jugadores[nombre_jug] = p;
    // Ranking
    ranking.push_back(p);
  }
}

void Cjt_Jugadores::escribir_ranking() const
{
  for (int i = 0; i < ranking.size(); ++i) {
    cout << i+1 << ' ' << ranking[i].consultar_nombre() << ' '
         << ranking[i].consultar_puntos() << endl;
  }
}

void Cjt_Jugadores::escribir_jugadores() const
{
  map<string, Jugador>::const_iterator it = cjt_Jugadores.begin();
  while (it != cjt_Jugadores.end()) {
    it->second.escribir_jug();
    ++it;
  }
}
