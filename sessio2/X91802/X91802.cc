#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v)
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */
{
  pair <int, int> max_min(-1, -1);
  
  int vec_size = v.size();
  for (int i = 0; i < vec_size; ++i) {
    if (v[i].te_nota()) {
      if (max_min.first == -1) {
	max_min.first = max_min.second = i;
      }
      else {
	double nota = v[i].consultar_nota();
	int dni = v[i].consultar_DNI();
	if (nota > v[max_min.first].consultar_nota()) {
	  max_min.first = i;
	}
	else if (nota < v[max_min.second].consultar_nota()) {
	  max_min.second = i;
	}
	else if (nota == v[max_min.first].consultar_nota() and dni < v[max_min.first].consultar_DNI()) {
	  max_min.first = i;
	}
	else if (nota == v[max_min.second].consultar_nota() and dni < v[max_min.second].consultar_DNI()) {
	  max_min.second = i;
	}
      }
    }

  }

  return max_min;
}
