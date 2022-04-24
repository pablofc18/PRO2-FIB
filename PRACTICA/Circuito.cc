#include "Circuito.hh"

Circuito::Circuito()
{
  // map<string, Torneo> cjt_Torneos;
}

void Circuito::anadir_torneo(const Torneo &t)
{
  cjt_Torneos[t.consultar_nombre()] = t;
}

void Circuito::eliminar_torneo(string nombre_torneo)
{
  cjt_Torneos.erase(nombre_torneo);
}

// void Circuito::iniciar_torneo(string nombre_torneo, Cjt_Jugadores &cjt_jug)
// {
//   map<string, Torneo>::iterator it = cjt_Torneos.find(nombre_torneo);
//   it->second.torneo_iniciar();
//   it->second.leer_participantes_torneo(cjt_jug);
//   it->second.confeccionar_cuadro_emparejamientos();
//   it->second.escribir_cuadro_emparejamientos();
// }

// void Circuito::finalizar_torneo(string nombre_torneo)
// {
//
// }

bool Circuito::existe_torneo(string nombre_torneo) const
{
  map<string, Torneo>::const_iterator it;
  it = cjt_Torneos.find(nombre_torneo);
  return it != cjt_Torneos.end();
}

bool Circuito::torneo_disputado(string nombre_torneo) const
{
  map<string, Torneo>::const_iterator it = cjt_Torneos.find(nombre_torneo);
  return it->second.torneo_finalizado();
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
