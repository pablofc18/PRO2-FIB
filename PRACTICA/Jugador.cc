#include "Jugador.hh"

Jugador::Jugador()
{
  puntos = 0;
  participando_torneo = false;
  torneos_disputados = 0;
  partidos = make_pair(0,0);
  sets = make_pair(0,0);
  juegos = make_pair(0,0);
}

Jugador::Jugador(string nombre_jug)
{
  nombre = nombre_jug;
  puntos = 0;
  participando_torneo = false;
  torneos_disputados = 0;
  partidos = make_pair(0,0);
  sets = make_pair(0,0);
  juegos = make_pair(0,0);
}

void Jugador::modificar_ranking(int rank)
{
  ranking = rank;
}

void Jugador::modificar_puntos(int puntos_jug)
{
  puntos += puntos_jug;
}

void Jugador::participando_en_torneo()
{
  participando_torneo = true;
}

void Jugador::no_participando_torneo()
{
  participando_torneo = false;
}

void Jugador::modificar_partidos_jugados(pair<int, int> partidos_jug)
{
  partidos.first += partidos_jug.first;
  partidos.second += partidos_jug.second;
}

void Jugador::modificar_sets_jugados(pair<int, int> sets_jug)
{
  sets.first += sets_jug.first;
  sets.second += sets_jug.second;
}

void Jugador::modificar_juegos_jugados(pair<int, int> juegos_jug)
{
  juegos.first += juegos_jug.first;
  juegos.second += juegos_jug.second;
}

void Jugador::modificar_torneos_disputados(int torneo_disp)
{
  torneos_disputados += torneo_disp;
}

string Jugador::consultar_nombre() const
{
  return nombre;
}

int Jugador::consultar_ranking() const
{
  return ranking;
}

int Jugador::consultar_puntos() const
{
  return puntos;
}

bool Jugador::consultar_participando_torneo() const
{
  return participando_torneo;
}

void Jugador::escribir_jug() const  // Puede que no coincida con el Jutge !?¿!
{
  cout << nombre << " Rk:" << ranking << " Ps:" << puntos
       << " Ts:" << torneos_disputados << " WM:" << partidos.first
       << " LM:" << partidos.second << " WS:" << sets.first << " LS:"
       << sets.second << " WG:" << juegos.first << " LG:" << juegos.second
       << endl;
}
