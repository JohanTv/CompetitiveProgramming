#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;

int n;
vector<pair<int,int>> coords;
double prom = 0.0;

// Idea: Para evitar el doble conteo, es decir, calcular el peso de la arista entre nodos varias veces
// Lo que hacemos es calcular el peso de todas las aristas dirigidas del grafo que pueden existir.
// y se divide entre la cantidad de nodos, ya que son la cantidad de caminos que empiezan en un
// determinado nodo

// Espacio temporal: O(n!), es factorial de n por la cantidad de aristas dirigidas que
// pueden existir en un grafo con n nodos
// Espacio espacial: O(n)

double get_dist(pair<int,int> a, pair<int,int>b){
    return sqrt(pow(a.first-b.first,2) + pow(a.second-b.second,2));
}

void calc(int m){
    bool visited[8]{0};
    visited[m] = true;
    REP(i, 0, n){
        if(!visited[i]){
            prom += get_dist(coords[m], coords[i]);
            visited[i] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x,y;
    REP(i, 0, n){
        cin >> x >> y;
        coords.push_back(MP(x,y));
    }
    REP(i, 0, n){
        calc(i);
    }
    double result = prom/double(n);
    printf("%.12f", result);
}