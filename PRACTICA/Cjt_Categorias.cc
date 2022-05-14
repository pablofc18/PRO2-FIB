/** @file Cjt_Categorias.cc
    @brief Código de la clase Cjt_Categorias 
*/


#include "Cjt_Categorias.hh"

Cjt_Categorias::Cjt_Categorias()
{
  num_max_niveles = 0;
  total_categorias = 0;
}

bool Cjt_Categorias::es_correcta_categoria(int id_categ) const
{
  return (1 <= id_categ and id_categ <= total_categorias);
}

string Cjt_Categorias::consultar_nombre_categ(int id_categ) const
{
  return cjt_Categorias[id_categ-1].consultar_nombre_categ();
}

vector< vector<int> > Cjt_Categorias::consultar_puntos_categ_nivel() const
{
  return puntos_por_categoria_nivel;
}

void Cjt_Categorias::leer_categorias_niveles()
{
  cin >> total_categorias; cin >> num_max_niveles;
  // Inicializa el tamaño del vector de Categorias
  cjt_Categorias = vector<Categoria>(total_categorias);
  // Lee las categorias
  for (int i = 1; i <= total_categorias; ++i) {
    string nombre_categ; cin >> nombre_categ;
    Categoria c(nombre_categ, i);
    cjt_Categorias[i-1] = c;
  }
}

void Cjt_Categorias::leer_puntos_por_categoria_nivel()
{
  // Inicializa el tamaño del vector de puntos por categoria y nivel
  puntos_por_categoria_nivel = vector< vector<int> > (total_categorias, vector<int>(num_max_niveles));
  // Lee los puntos
  for (int i = 0; i < total_categorias; ++i) {
    for (int j = 0; j < num_max_niveles; ++j) {
      int num; cin >> num;
      puntos_por_categoria_nivel[i][j] = num;
    }
  }
}

void Cjt_Categorias::escribir_categorias_puntos() const
{
  cout << total_categorias << ' ' << num_max_niveles << endl;
  for (int i = 0; i < total_categorias; ++i) {
    cout << cjt_Categorias[i].consultar_nombre_categ();
    for (int j = 0; j < num_max_niveles; ++j) {
      cout << ' ' << puntos_por_categoria_nivel[i][j];
    }
    cout << endl;
  }
}
