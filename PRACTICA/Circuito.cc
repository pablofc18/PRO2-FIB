#include "Circuito.hh"

Circuito::Circuito()
{
  // map<string, Torneo> cjt_Torneos;
}

void Circuito::anadir_torneo(const Torneo &t)
{
  cjt_Torneos[t.consultar_nombre()] = t;
}

bool Circuito::eliminar_torneo(string nombre_torneo)
{
  map<string, Torneo>::const_iterator it = cjt_Torneos.find(nombre_torneo);
  if (it != cjt_Torneos.end()) {
    if (it->second.torneo_disputado()) {
      // actualiza ranking
      //cjt_jug.actualizar_ranking(cjt_categ.consultar_puntos_categ_nivel(), circ.consultar_torneo(nombre_torneo).consultar_jugadores_del_torneo());
    }
    cjt_Torneos.erase(it);
    return true;
  }
  else return false;
}

void Circuito::iniciar_torneo(string nombre_torneo, const Cjt_Jugadores &cjt_jug)
{
  map<string, Torneo>::iterator it = cjt_Torneos.find(nombre_torneo);
  it->second.leer_participantes_torneo();
  int val = 1; int pot2nivel = 1;
  it->second.asignar_cuadro_emp(it->second.confeccionar_cuadro_emparejamientos(it->second.consultar_jugadores_del_torneo().size(), val, pot2nivel));
  it->second.escribir_cuadro_emparejamientos(it->second.consultar_emparejamientos(), cjt_jug);
  cout << endl;
}

void Circuito::finalizar_torneo(string nombre_torneo, const Cjt_Jugadores &cjt_jug)
{
  map<string, Torneo>::iterator it = cjt_Torneos.find(nombre_torneo);
  BinTree<string> resultados_partidos;
  it->second.leer_resultados(resultados_partidos);
  //
  BinTree<int> emparej_modif = it->second.consultar_emparejamientos();
  it->second.modificar_cuadro_emparej_con_results(resultados_partidos, emparej_modif);
  BinTree<pair<pair<int,int>, string> > cuadro_res;
  it->second.confeccionar_cuadro_resultados(resultados_partidos, emparej_modif, cuadro_res);
  it->second.escribir_resultados_torneo(cuadro_res, cjt_jug);
  cout << endl;
  // escribir_particip_puntos_ganados();
}

bool Circuito::existe_torneo(string nombre_torneo) const
{
  map<string, Torneo>::const_iterator it;
  it = cjt_Torneos.find(nombre_torneo);
  return it != cjt_Torneos.end();
}

Torneo Circuito::consultar_torneo(string nombre_torneo) const
{
  map<string, Torneo>::const_iterator it = cjt_Torneos.find(nombre_torneo);
  return it->second;
}

int Circuito::numero_torneos_totales() const
{
  return cjt_Torneos.size();
}

void Circuito::leer_cjt_torneos()
{
  int num_torneos; cin >> num_torneos;
  for (int i = 0; i < num_torneos; ++i) {
    string nombre_torneo; cin >> nombre_torneo;
    int id_cat; cin >> id_cat;
    Torneo t(nombre_torneo, id_cat);
    cjt_Torneos[nombre_torneo] = t;
  }
}

void Circuito::escribir_torneos(const Cjt_Categorias &cjt_cat) const
{
  map<string, Torneo>::const_iterator it = cjt_Torneos.begin();
  while (it != cjt_Torneos.end()) {
    it->second.escribir_torneo(cjt_cat);
    ++it;
  }
}
