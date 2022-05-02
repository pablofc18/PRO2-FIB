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

void Torneo::confeccionar_cuadro_resultados(const BinTree<string> &results, const BinTree<int> &cuadro_emp)
{

  if (results.left().empty() and not results.right().empty()) {
    confeccionar_cuadro_resultados(results.right(), cuadro_emp.right());
    pair<pair<int,int>, string> val;
    pair<int,int> jugs;
    jugs.first = cuadro_emp.value();
    // jugs.second =
    // mirando el ultimo set del partido entre los dos para ver quien gana
    if (results.right().value()[results.right().value().size() - 1] < results.right().value()[results.right().value().size() - 3]) {
      jugs.second =
    }

    val = make_pair(jugs, results.value());
    cuadro_resultados = BinTree(val);
  }

  else if (results.left().empty() and results.right().empty()) {
    pair<pair<int,int>, string> val;
    pair<int,int> jugs = make_pair(cuadro_emp.left().value(), cuadro_emp.right().value());
    val = make_pair(jugs, results.value());
    return BinTree< pair<pair<int,int>, string> >(val);
  }

  else {
    BinTree< pair< pair<int,int>, string> > l, r;
    l = confeccionar_cuadro_resultados(results.left(), cuadro_emp.left());
    r = confeccionar_cuadro_resultados(results.right(), cuadro_emp.right());

    pair<pair<int,int>, string> val;



    return BinTree< pair< pair<int,int>, string> >(val, l, r);
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

vector<int> Torneo::consultar_jugadores_del_torneo() const
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
    jugadores_del_torneo.push_back(num_rank);
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

// void Torneo::escribir_particip_puntos_ganados() const
// {
//
// }

void Torneo::escribir_cuadro_emparejamientos(const BinTree<int> &cuadro_emp, const Cjt_Jugadores &cjt_jug) const
{
  if (cuadro_emp.left().empty()) cout << cuadro_emp.value() << '.' << cjt_jug.consultar_jugador(jugadores_del_torneo[cuadro_emp.value()-1]).consultar_nombre();
  else {
    cout << '(';
    escribir_cuadro_emparejamientos(cuadro_emp.left(), cjt_jug);
    cout << ' ';
    escribir_cuadro_emparejamientos(cuadro_emp.right(), cjt_jug);
    cout << ')';
  }

}
// NO DEFINITIVO !!
void Torneo::escribir_resultados_torneo() const
{
  if (not cuadro_resultados.empty()) {
    cout << cuadro_resultados.value() << endl; // !!!
    escribir_resultados_torneo(cuadro_resultados.left());
    escribir_resultados_torneo(cuadro_resultados.right());
  }
}
