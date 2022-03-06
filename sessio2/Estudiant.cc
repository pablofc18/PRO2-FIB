#include "Estudiant.hh"

Estudiant::Estudiant()
/* Pre: cert */
/* Post: el resultat  ́es un estudiant amb DNI=0 i sense nota */
{
  dni = 0;
  amb_nota = false;
}

Estudiant::Estudiant(int dni)
/* Pre: dni>=0 */
/* Post: el resultat  ́es un estudiant amb DNI=dni i sense nota */
{
  this->dni = dni;
  amb_nota = false;
}

Estudiant::~Estudiant(){}
// esborra autom`aticament els objectes locals en sortir d’un `ambit de visibilitat
void Estudiant::afegir_nota(double nota)
/* Pre: el par`ametre impl ́ıcit no t ́e nota i 0<="nota"<=nota_maxima() */
/* Post: la nota del par`ametre impl ́ıcit passa a ser "nota" */
{
  this->nota = nota;
  /* una notaci ́o equivalent alternativa  ́es (*this).nota = nota; */
  amb_nota = true;
}

void Estudiant::modificar_nota(double nota)
/* Pre: el par`ametre impl ́ıcit t ́e nota i 0<="nota"<=nota_maxima() */
/* Post: la nota del par`ametre impl ́ıcit passa a ser "nota" */
{
  this->nota = nota;
}

int Estudiant::consultar_DNI() const
/* Pre: cert */
/* Post: el resultat  ́es el DNI del par`ametre impl ́ıcit */
{
  return dni;
}

double Estudiant::consultar_nota() const
/* Pre: el par`ametre impl ́ıcit t ́e nota */
/* Post: el resultat  ́es la nota del par`ametre impl ́ıcit */
{
  return nota;
}

double Estudiant::nota_maxima()
/* Pre: cert */
/* Post: el resultat  ́es la nota m`axima dels elements de la classe */
{
  return MAX_NOTA;
}

bool Estudiant::te_nota() const
/* Pre: cert */
/* Post: el resultat indica si el par`ametre impl ́ıcit t ́e nota o no */
{
  return amb_nota;
}

void Estudiant::llegir()
/* Pre: estan preparats al canal estandar d’entrada un enter no negatiu i
   un double */
/* Post: el par`ametre impl ́ıcit passa a tenir els atributs llegits del canal
   est`andard d’entrada; si el double no pertany a l’interval [0..nota_maxima()],
   el p.i. es queda sense nota */
{
  cin >> dni;
  double x;
  cin >> x;
  if (x >= 0 and x <= MAX_NOTA) {
    nota = x;
    amb_nota = true;
  }
  else amb_nota = false;
}

void Estudiant::escriure() const
/* Pre: cert */
/* Post: s’han escrit els atributs del par`ametre impl ́ıcit al canal est`andard
   de sortida: el dni seguit de un NP o la nota en format double, separats per
   un espai en blanc */
{
  if (amb_nota) cout << dni << " " << nota << endl;
  else cout << dni << " NP" << endl;
}
