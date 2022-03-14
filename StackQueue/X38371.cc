#include <queue>
#include <iostream>
using namespace std;

void calc_min_max(const queue<int> &c, int &min, int &max) {
  queue<int> copy(c);
  int length = copy.size();
  min = 1001; max = -1002;
  for (int i = 0; i < length; ++i) {
    if (copy.front() < min) min = copy.front();
    if (copy.front() > max) max = copy.front();
    copy.pop();
  }
}

void add_numb(queue<int> &c, int n, int &min, int &max) {
  if (n < min) min = n;
  if (n > max) max = n;
  c.push(n);
}

void remove_numb(queue<int> &c, int n, int &min, int &max) {
  if (n == min or n == max) {
    c.pop();
    calc_min_max(c, min, max);
  }
  else c.pop();
}

int main() {
  queue<int> c;
  int min = 1001, max = -1002, total = 0;
  double media = 0;
  int num = 0;
  while (num <= 1000 and num >= -1001 and cin >> num) {
    if (num != -1001) {
      add_numb(c, num, min, max);
      total += num;
      media = double(total)/c.size();
    }
    else {
      if (not c.empty()) {
        int number = c.front();
        remove_numb(c, number, min, max);
        total -= number;
        media = double(total)/c.size();
      }
    }
    if (num >= -1001 and num <= 1000) {
      if (c.empty()) cout << 0 << endl;
      else {
        cout << "min " << min << "; ";
        cout << "max " << max << "; ";
        cout << "media " << media << endl;
      }
    }
  }
}
