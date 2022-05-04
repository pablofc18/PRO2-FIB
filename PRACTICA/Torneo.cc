#include "Torneo.hh"

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

BinTree<int> Torneo::confeccionar_cuadro_emparejamientos(int n, int val, int potencia2)
{
  if (n < potencia2) {
    if ((val <= potencia2-n and val >= 1) or (val > n)) return BinTree<int>();
    else return BinTree<int>(val);
  }
  else if (n == potencia2) {
    return BinTree<int>(val);
  }
  else {
    BinTree<int> l,r;
    l = confeccionar_cuadro_emparejamientos(n, val, potencia2*2);
    r = confeccionar_cuadro_emparejamientos(n, potencia2*2+1-val, potencia2*2);
    return BinTree<int>(val, l, r);
  }
}

void Torneo::asignar_cuadro_emp(const BinTree<int> &cuadro_emparejamientos)
{
  cuadro_emp = cuadro_emparejamientos;
}

void Torneo::torneo_ya_disputado()
{
  disputado = true;
}


void Torneo::modificar_cuadro_emparej_con_results(const BinTree<string> &results, int nivel, BinTree<int> &emparej)
{
  if (emparej.left().empty()) {
    emparej = BinTree<int>(emparej.value());
    jugadores_del_torneo[emparej.value() - 1].second = nivel;
  }

  else {
    BinTree<int> l_emp = emparej.left(), r_emp = emparej.right();
    modificar_cuadro_emparej_con_results(results.left(), nivel+1, l_emp);
    modificar_cuadro_emparej_con_results(results.right(), nivel+1, r_emp);

    int val;
    string res = results.value();
    int res_size = results.value().size();
    if (res[res_size - 1] < res[res_size - 3]) {
      val = l_emp.value();
      jugadores_del_torneo[l_emp.value() - 1].second = nivel;
    }
    else {
      val = r_emp.value();
      jugadores_del_torneo[r_emp.value() - 1].second = nivel;
    }

    emparej = BinTree<int>(val, l_emp, r_emp);
  }
}

void Torneo::confeccionar_cuadro_resultados(const BinTree<string> &results, const BinTree<int> &cuadro_emparej, BinTree< pair<pair<int,int>, string> > &cuadro_res)
{
  if (results.left().empty() and results.right().empty()) {
    pair<pair<int,int>, string> val;
    int a = cuadro_emparej.left().value();
    int b = cuadro_emparej.right().value();
    pair<int,int> jugs = make_pair(a,b);
    val = make_pair(jugs, results.value());

    cuadro_res = BinTree< pair<pair<int,int>, string> >(val);
  }

  else {
    BinTree< pair< pair<int,int>, string> > l, r;
    BinTree<int> l_e = cuadro_emparej.left(), r_e = cuadro_emparej.right();
    if (not results.left().empty()) confeccionar_cuadro_resultados(results.left(), l_e, l);
    confeccionar_cuadro_resultados(results.right(), r_e, r);

    pair<pair<int,int>, string> val;
    pair<int,int> jugs;
    jugs.first = cuadro_emparej.left().value();
    jugs.second = cuadro_emparej.right().value();
    val = make_pair(jugs, results.value());

    cuadro_res = BinTree< pair< pair<int,int>, string> >(val, l, r);
  }
}

string Torneo::consultar_nombre() const
{
  return nombre;
}

bool Torneo::torneo_disputado() const
{
  return disputado;
}

vector< pair<int,int> > Torneo::consultar_jugadores_del_torneo() const
{
  return jugadores_del_torneo;
}

BinTree<int> Torneo::consultar_emparejamientos()
{
  return cuadro_emp;
}

void Torneo::leer_participantes_torneo()
{
  int num_jug_inscritos; cin >> num_jug_inscritos;
  for (int i = 0; i < num_jug_inscritos; ++i) {
    int num_rank; cin >> num_rank;
    pair<int,int> p(num_rank, 0);
    jugadores_del_torneo.push_back(p);
  }
}

void Torneo::leer_resultados(BinTree<string> &resultados_partidos)
{
  string resultado;
  cin >> resultado;

  if (resultado.size() == 3 or resultado.size() == 7 or resultado.size() == 11) {
    BinTree<string> l;
    leer_resultados(l);
    BinTree<string> r;
    leer_resultados(r);
    resultados_partidos = BinTree<string>(resultado, l, r);
  }
}

void Torneo::escribir_torneo(const Cjt_Categorias &cjt_cat) const
{
  // nombre torneo y nombre categoria
  cout << nombre << ' ';
  cout << cjt_cat.consultar_nombre_categ(categ) << endl;
}

void Torneo::escribir_particip_puntos_ganados(const Cjt_Jugadores &cjt_jug, const Cjt_Categorias &cjt_cat) const
{
  for (int i = 0; i < jugadores_del_torneo.size(); ++i) {
    cout << i+1 << '.' << cjt_jug.consultar_jugador(jugadores_del_torneo[i].first).consultar_nombre() << ' '
         << cjt_cat.consultar_puntos_categ_nivel()[categ-1][jugadores_del_torneo[i].second - 1] << endl;
  }
}

void Torneo::escribir_cuadro_emparejamientos(const BinTree<int> &cuadro_emp, const Cjt_Jugadores &cjt_jug) const
{
  if (cuadro_emp.left().empty()) cout << cuadro_emp.value() << '.' << cjt_jug.consultar_jugador(jugadores_del_torneo[cuadro_emp.value()-1].first).consultar_nombre();
  else {
    cout << '(';
    escribir_cuadro_emparejamientos(cuadro_emp.left(), cjt_jug);
    cout << ' ';
    escribir_cuadro_emparejamientos(cuadro_emp.right(), cjt_jug);
    cout << ')';
  }

}

void Torneo::escribir_resultados_torneo(const BinTree< pair<pair<int,int>, string> > &cuadro_res, const Cjt_Jugadores &cjt_jug) const
{
  if (not cuadro_res.empty()) {
    cout << '(' << cuadro_res.value().first.first << '.'
    << cjt_jug.consultar_jugador(jugadores_del_torneo[cuadro_res.value().first.first - 1].first).consultar_nombre()
    << " vs " << cuadro_res.value().first.second << '.'
    << cjt_jug.consultar_jugador(jugadores_del_torneo[cuadro_res.value().first.second - 1].first).consultar_nombre()
    << ' ' << cuadro_res.value().second;
    escribir_resultados_torneo(cuadro_res.left(), cjt_jug);
    escribir_resultados_torneo(cuadro_res.right(), cjt_jug);
    cout << ')';

  }
}
