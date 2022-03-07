#include <stack>
#include <iostream>
using namespace std;


bool es_palindrom(stack<int>&sec, int n_elem)
/*Pre: pila no buida, num elements*/
/*Post: retorna true si es palindrom*/
{
  for (int i = 0; i < n_elem/2; ++i) {
    int n; cin >> n;
    sec.push(n);
  }
  //If es impar
  int x = 0;
  if (n_elem%2 != 0) cin >> x;
  //Par
  for (int i = 0; i < n_elem/2; ++i) {
    int n; cin >> n;
    if (sec.top() != n) return false;
    sec.pop();
  }
  return true;
}




int main() {
  int n_elem;
  cin >> n_elem;
  stack<int> sec_num;
  if (es_palindrom(sec_num, n_elem)) cout << "SI" << endl;
  else cout << "NO" << endl;
}
