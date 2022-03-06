#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<pair<int,int> > Fila;
typedef vector<Fila> Matriz;

struct equipo {
    int id, pts, gf, gc;
};


void leer_matriz(Matriz& v) {
    int tam = v.size();
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            cin >> v[i][j].first;
            cin >> v[i][j].second;
        }
    }
}


vector<equipo> clasificar(const Matriz& v) {
    int equipos = v.size();
    vector<equipo> clas(equipos);
    
    for (int i = 0; i < equipos; ++i) clas[i].id = i+1;
    
    for (int i = 0; i < equipos; ++i) {
        for (int j = 0; j < equipos; ++j) {
            if (i != j) {
                //puntos
                if(v[i][j].first > v[i][j].second) clas[i].pts += 3;
                else if (v[i][j].first == v[i][j].second) clas[i].pts += 1;
                //goles a favor i en contra
                clas[i].gf += v[i][j].first;
                clas[i].gc += v[i][j].second;
            }
        }
    }
    
    for (int j = 0; j < equipos; ++j) {
        for (int i = 0; i < equipos; ++i) {
            if (i != j) {
                //puntos
                if(v[i][j].second > v[i][j].first) clas[j].pts += 3;
                else if (v[i][j].first == v[i][j].second) clas[j].pts += 1;
                //goles a favor i en contra
                clas[j].gf += v[i][j].second;
                clas[j].gc += v[i][j].first;
            }
        }
    }
    return clas;
}


bool comp(equipo v, equipo u)  {
    if (v.pts == u.pts) {
        if ((v.gf - v.gc) == (u.gf - u.gc)) return v.id < u.id;
        else return (v.gf - v.gc) > (u.gf - u.gc);
    }
    else return v.pts > u.pts;
}


void escribe_matriz(const vector<equipo>& v) {
    int tam = v.size();
    
    for(int i = 0; i < tam; ++i) {
        cout << v[i].id << " ";
        cout << v[i].pts << " ";
        cout << v[i].gf << " ";
        cout << v[i].gc << endl;
    }
}


int main() {
    int equipos;
    cin >> equipos;
    Matriz resultados(equipos, Fila (equipos));
    leer_matriz(resultados);
    vector<equipo> clasificacion;
    clasificacion = clasificar(resultados);
    sort (clasificacion.begin(), clasificacion.end(), comp);
    escribe_matriz(clasificacion);
    
}
