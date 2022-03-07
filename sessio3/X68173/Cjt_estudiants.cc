#include "Cjt_estudiants.hh"
#include <algorithm>


Cjt_estudiants::Cjt_estudiants()
{
  vest = vector<Estudiant>(MAX_NEST);
  nest = 0;
  imax = -1;
}

Cjt_estudiants::~Cjt_estudiants()
{}

bool comp(const Estudiant &a, const Estudiant &b)
{
  return a.consultar_DNI() < b.consultar_DNI();
}

void Cjt_estudiants::ordenar_cjt_estudiants()
{
  sort(vest.begin(), vest.begin()+nest, comp);
}

int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest,
     int left, int right, int x)
{
  int i; bool found = false;
  while(left <= right and not found) {
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i - 1;
    else if (x > vest[i].consultar_DNI()) left = i + 1;
    else found = true;
  }
  if (found) return i;
  else return -1;
}

void Cjt_estudiants::recalcular_posicio_imax()
{
  double maxnotatmp = -1;
  for (int i = 0; i < nest; ++i) {
    if (vest[i].te_nota()) {
      if (maxnotatmp < vest[i].consultar_nota()) {
        maxnotatmp = vest[i].consultar_nota();
        imax = i;
      }
    }
  }
}

void Cjt_estudiants::afegir_estudiant(const Estudiant& est)
{
  int i = nest-1;
  bool found = false;
  int dni = est.consultar_DNI();
  while (i>=0 and not found) {
    if (dni > vest[i].consultar_DNI()) found = true;
    else {
      vest[i+1] = vest[i];
      --i;
    }
  }
  vest[i+1] = est;
  ++nest;
  //recalcular imax sense crida a funció
  if (i+1 <= imax) ++imax;
  if (est.te_nota()) {
    if (est.consultar_nota() > vest[imax].consultar_nota()) imax = i+1;
    else if (est.consultar_nota() == vest[imax].consultar_nota() and est.consultar_DNI() < vest[imax].consultar_DNI()) {
      imax = i+1;
    }
  }
}

void Cjt_estudiants::modificar_estudiant(const Estudiant& est)
{
  int i = cerca_dicot(vest, 0, nest-1, est.consultar_DNI());
  bool imax_changed = false;
  if (i == imax and est.consultar_nota() < vest[imax].consultar_nota()) {
    imax_changed = true;
  }

  vest[i] = est;
  if (imax_changed) recalcular_posicio_imax();
  
  if (est.te_nota() and not imax_changed) {
    if (est.consultar_nota() > vest[imax].consultar_nota()) {
      imax = i;
    }
    else if (est.consultar_nota() == vest[imax].consultar_nota() and est.consultar_DNI() < vest[imax].consultar_DNI()) {
      imax = i;
    }
  }
}

void Cjt_estudiants::modificar_iessim(int i, const Estudiant& est)
{
  bool imax_changed = false;
  if (i-1 == imax and est.consultar_nota() < vest[imax].consultar_nota()) {
    imax_changed = true;
  }

  vest[i-1] = est;
  if (imax_changed) recalcular_posicio_imax();

  if (est.te_nota() and not imax_changed) {
    if (est.consultar_nota() > vest[imax].consultar_nota()) {
      imax = i-1;
    }
    else if (est.consultar_nota() == vest[imax].consultar_nota() and est.consultar_DNI() < vest[imax].consultar_DNI()) {
      imax = i-1;
    }
  }
}

void Cjt_estudiants::esborrar_estudiant(int dni)
{
  int i = cerca_dicot(vest, 0, nest-1, dni);
  int j = i;
  while (i < nest-1) {
    vest[i] = vest[i+1];
    ++i;
  }
  --nest;
  if (imax == j) recalcular_posicio_imax();
  else if (j < imax) --imax;
}

int Cjt_estudiants::mida() const
{
  return nest;
}

int Cjt_estudiants::mida_maxima()
{
  return MAX_NEST;
}

bool Cjt_estudiants::existeix_estudiant(int dni) const
{
  int i = cerca_dicot(vest, 0, nest-1, dni);
  return i != -1;
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
{
  int i = cerca_dicot(vest, 0, nest-1, dni);
  return vest[i];
}

Estudiant Cjt_estudiants::consultar_iessim(int i) const
{
  return vest[i-1];
}

Estudiant Cjt_estudiants::estudiant_nota_max() const
{
  return vest[imax];
}

void Cjt_estudiants::llegir()
{
  cin >> nest;
  for (int i = 0; i < nest; ++i) vest[i].llegir();
  ordenar_cjt_estudiants();
  recalcular_posicio_imax();
}

void Cjt_estudiants::escriure() const
{
  for (int i = 0; i < nest; ++i) vest[i].escriure();
}
