#include <iostream>
#include <algorithm>
#include "PRO2Excepcio.hh"
#include "Cjt_estudiants.hh"

using namespace std;

Cjt_estudiants::Cjt_estudiants()
{
  nest = 0;
  vest = vector<Estudiant>(MAX_NEST);
}

Cjt_estudiants::~Cjt_estudiants(){}

void Cjt_estudiants::afegir_estudiant(const Estudiant &est)
{
  int i = nest-1;
  bool b = false;
  int dni = est.consultar_DNI();
  while (i >= 0 and not b) {
    if ( dni> vest[i].consultar_DNI()) b = true;
    else {
      vest[i+1]=vest[i];
      --i;
    }
  }
  // i ��s la posici�� m��s avan��ada amb el DNI m��s petit que dni, si n'hi ha;
  // si no, i=-1
  vest[i+1] = est;
  ++nest;
}


int Cjt_estudiants::cerca_dicot(const vector<Estudiant> &vest, int left, int right, int x)
/* Pre: vest esta ordenat */
{
  int i;
  bool found=false;
  while (left <= right and not found) {
    i = (left + right)/2;
    if (x < vest[i].consultar_DNI()) right = i-1;
    else if (x > vest[i].consultar_DNI()) left = i + 1;
    else found = true;
  }
  // i es la pos, si l'elem existeix
  if (found) return i;
  else return -1;
}

void Cjt_estudiants::modificar_estudiant(const Estudiant &est)
  /* Pre: existeix un estudiant al par��metre impl��cit amb el dni d'est  */
{
  int x = est.consultar_DNI();
  int i=cerca_dicot(vest,0,nest-1,x);
  vest[i]= est;
}

void Cjt_estudiants::modificar_iessim(int i, const Estudiant &est)
{
  if (i<1 or i>nest) throw PRO2Excepcio("Index no v��lid per a modificar_iessim");
  vest[i-1]= est;
}

int Cjt_estudiants::mida() const
{return nest;}

int Cjt_estudiants::mida_maxima() // las static no llevan const en el cpp
{return MAX_NEST;}

bool Cjt_estudiants::existeix_estudiant(int dni) const
{
  int  i= cerca_dicot(vest,0,nest-1,dni);
  return (i!=-1);
}

Estudiant Cjt_estudiants::consultar_estudiant(int dni) const
{
  int i=cerca_dicot(vest,0,nest-1,dni);
  // i es la pos
  return vest[i];
}

Estudiant Cjt_estudiants::consultar_iessim(int i) const
{
  if (i<1 or i>nest) throw PRO2Excepcio("Index no v��lid per a consultar_iessim");
  return vest[i-1];
}

bool comp(const Estudiant &e1, const Estudiant &e2){
  return (e1.consultar_DNI()<e2.consultar_DNI());
}

void Cjt_estudiants::ordenar_cjt_estudiants (){
  sort(vest.begin(),vest.begin()+nest,comp);
}

void Cjt_estudiants::llegir(){
  // cout << "Escriu la mida del conjunt i els elements" << endl;
  cin >> nest;
  for (int i=0; i<nest; ++i)
    vest[i].llegir();
  ordenar_cjt_estudiants();
}


void Cjt_estudiants::escriure() const{
  for (int i=0; i<nest; ++i)
    vest[i].escriure();
}
