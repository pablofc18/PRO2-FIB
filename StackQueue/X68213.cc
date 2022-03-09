#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void leer_pila(vector<stack<string> > &v)
/*Pre: recibe vector de pilas*/
/*Post: llena la pila*/
{
  string libro; cin >> libro;
  int n_cat; cin >> n_cat;
  v[n_cat-1].push(libro);
}

void eliminar_libros(vector<stack<string> > &v)
/*Pre: recibe el vector de pilas*/
/*Post: elimina x libros de n pila*/
{
  int x; cin >> x;
  int n_cat; cin >> n_cat;
  while (x > 0) {
    v[n_cat-1].pop();
    --x;
  }
}

void escribir_pila(vector<stack<string> > v)
/*Pre: recibe vector de pilas con al menos una pila no vacía*/
/*Post: escribe la pila*/
{
  int n_cat; cin >> n_cat;
  cout << "Pila de la categoria " << n_cat << endl;
  while (not v[n_cat-1].empty()) {
    cout << v[n_cat-1].top() << endl;
    v[n_cat-1].pop();
  }
  cout << endl;
}

void menu(vector<stack<string> > &v)
{
  int opc; cin >> opc;
  while (opc != -4) {
    if (opc == -1) {
      leer_pila(v);
    }
    else if (opc == -2) {
      eliminar_libros(v);
    }
    else if (opc == -3) {
      escribir_pila(v);
    }
    cin >> opc;
  }
}

int main() {
  int num_categ; cin >> num_categ;
  vector<stack<string> > v(num_categ);
  menu(v);
}
