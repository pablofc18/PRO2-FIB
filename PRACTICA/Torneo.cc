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

BinTree<int> Torneo::confeccionar_cuadro_emparejamientos(int n, int &nivel_actual, int m, int altura, int &pot2nivel)
{
  if (nivel_actual == altura) {
    return BinTree<int>(pot2nivel);
  }
  else if (nivel_actual == altura-1) {
    if (n == m) return BinTree<int>();
    else BinTree<int>(pot2nivel);
  }
  else {
    BinTree<int> l,r;
    l = confeccionar_cuadro_emparejamientos(n, nivel_actual+1, m, altura, 1); // a....b
    r = confeccionar_cuadro_emparejamientos(n, nivel_actual+1, m, altura, pot2nivel+1-a);

    return BinTree<int>(n, l, r);
  }
}

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
// MAL !!!
void Torneo::escribir_cuadro_emparejamientos()
{
  if (cuadro_emparejamientos.left().empty()) return;
  else {
    cout << '(' << endl;
    escribir_cuadro_emparejamientos(cuadro_emparejamientos.left());
    cout << cuadro_emparejamientos.value() << endl;
    escribir_cuadro_emparejamientos(cuadro_emparejamientos.right());
    cout << ')' << endl;
  }
}

// void Torneo::escribir_resultados_torneo() const
// {
//
// }
