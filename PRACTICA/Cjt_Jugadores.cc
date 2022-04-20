#include "Cjt_Jugadores.hh"

Cjt_Jugadores::Cjt_Jugadores()
{
  // map<int, Jugador> ranking;
  // map<string, Jugador> cjt_jugadores;
}

void Cjt_Jugadores::anadir_jugador(const Jugador &p)
{
  cjt_Jugadores[p.consultar_nombre()] = p;
  // ranking
}

void Cjt_Jugadores::eliminar_jugador(string nombre_jug)
{
  cjt_Jugadores.erase(nombre_jug);
  // ranking
}
//
// void Cjt_Jugadores::actualizar_ranking(vector< vector<int> > pts_categ_nivel, map<int, Jugador> jugadores_del_torneo)
// {
// }
//
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

int Cjt_Jugadores::numero_jugadores_totales() const
{
  return cjt_Jugadores.size();
}

void Cjt_Jugadores::leer_jugadores()
{
  int num_jugs; cin >> num_jugs;
  for (int i = 0; i < num_jugs; ++i) {
    string nombre_jug; cin >> nombre_jug;
    Jugador p(nombre_jug);
    cjt_Jugadores[nombre_jug] = p;
    // ranking

  }
}

// void Cjt_Jugadores::escribir_ranking() const
// {
// }

void Cjt_Jugadores::escribir_jugadores() const
{
  map<string, Jugador>::const_iterator it = cjt_Jugadores.begin();
  while (it != cjt_Jugadores.end()) {
    it->second.escribir_jug();
    ++it;
  }
}
