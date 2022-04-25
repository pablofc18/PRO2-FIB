#include "Torneo.hh"
// INACABADA !!!
Torneo::Torneo()
{
  categ = 0;
  disputado = false;
}

Torneo::Torneo(string nombre_torneo, int id_categ)
{
  nombre = nombre_torneo;
  categ = id_categ;
  disputado = false;
}

// void Torneo::confeccionar_cuadro_emparejamientos()
// {
//   int h = log2 (jugadores_del_torneo.size()) + 1;
//   int m = pow (2, h - 1);
//
//
//
//
//
//
//
// }

// void Torneo::confeccionar_cuadro_resultados()
// {
// }

string Torneo::consultar_nombre() const
{
  return nombre;
}

bool Torneo::torneo_disputado() const
{
  return disputado;
}

vector<int> Torneo::consultar_jugadores_del_torneo() const
{
  return jugadores_del_torneo;
}

void Torneo::leer_participantes_torneo()
{
  int num_jug_inscritos; cin >> num_jug_inscritos;
  for (int i = 0; i < num_jug_inscritos; ++i) {
    int num_rank; cin >> num_rank;
    jugadores_del_torneo[i] = num_rank;
  }
}

// void Torneo::leer_resultados()
// {
//
// }

void Torneo::escribir_torneo(const Cjt_Categorias &cjt_cat) const
{
  // nombre torneo y nombre categoria
  cout << nombre << ' ';
  cout << cjt_cat.consultar_nombre_categ(categ) << endl;
}

// void Torneo::escribir_particip_puntos_ganados() const
// {
//
// }

// void Torneo::escribir_cuadro_emparejamientos() const
// {
//
// }

// void Torneo::escribir_resultados_torneo() const
// {
//
// }
