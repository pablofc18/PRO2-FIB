#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct parint {int prim, seg;};
 
parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint r;
    r.prim = v[0];
    r.seg = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > r.prim) r.prim = v[i];
        else if (v[i] < r.seg) r.seg = v[i];
    } 
    return r;
}
 
pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int, int> r = make_pair(v[0],v[0]);
    
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > r.first) r.first = v[i];
        else if (v[i] < r.second) r.second = v[i];
    }
    return r;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = v[0];
    y = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        else if (v[i] < y) y = v[i];
    } 
}
