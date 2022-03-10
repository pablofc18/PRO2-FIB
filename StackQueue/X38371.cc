#include <queue>
#include <iostream>
using namespace std;


void calc_min_max_med(queue<int> &c, int &min, int &max, double &media)
{
  int num_tot = c.size();
  while (not c.empty()) {
    media += c.front();
    if (c.front() < min) min = c.front();
    if (c.front() > max) max = c.front();
    c.pop();
  }
  media /= num_tot;
}


void calcular(const queue<int> &c, int &min, int &max, double media)
/*Pre: no vacía*/
/*Post: dice el min el max y la media de los numeros que hay en la queue*/
{
  bool empty = false;
  if (not c.empty()) min = max = c.front();
  else empty = true;

  queue<int> copia = c;
  calc_min_max_med(copia, min, max, media);

  if (not empty) cout << "min " << min << "; max " << max << "; media " << media << endl;
  else cout << 0 << endl;
}

int main() {
  queue<int> c;
  int num; cin >> num;
  int min = 0, max = 0;
  double media = 0;
  while (num <= 1000 and num >= -1001) {
    if (not c.empty() and num == -1001) {
      c.pop();
      calcular(c, min, max, media);
    }
    else if (num != -1001) {
      c.push(num);
      calcular(c, min, max, media);
    }
    else cout << 0 << endl;
    cin >> num;
  }
}
