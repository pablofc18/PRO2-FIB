#include <vector>
#include <iostream>
using namespace std;


int solitaris(const vector<int> &v)
 /* Pre: v.size() > 0 */
 /* Post: el resultat es el nombre de solitaris a v */
{
  int size = v.size();
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (i == 0) {
      if (v[i] != v[i+1]) ++count;
    }
    else if (i == size - 1) {
      if (v[i] != v[i-1]) ++count;
    }
    else if (v[i-1] != v[i] and v[i] != v[i+1]) ++count;

  }
  return count;
}

// int main() {
//   vector<int> n(10);
//   for (int i=0;i < 10;++i) cin >> n[i];
//   cout << solitaris(n) << endl;
// }
