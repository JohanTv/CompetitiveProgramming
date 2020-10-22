#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

int n,m;
vector<pair<ll, ll>> routers;

// Idea: Utilizar las operaciones bitwise 
// Como nos piden el minimo, inicializamos un vector con todos sus elementos en infinito
// luego se hace 2^n-1 iteraciones, donde el ultimo elemento del vector representa el costo
// minimo de conectar a todas las computadoras. Asimismo, cada indice de ese vector
// se utiliza su representacion binaria y las conexiones de cada router es representado
// de la misma forma. Luego de realizar la operacion (a and not b) el resultado
// representa el indice del elemento del vector donde están los óptimos a comparar


// Complejidad temporal: O((2^n)*m)
// Complejidad Espacial: O(m*n)

void calc(){
    vector<ll> best(1<<n, numeric_limits<int>::max());
    best[0] = 0;
    REP(i, 1, best.size()){
        REP(j, 0, m){
            ll val = i & ~routers[j].second;
            if(best[val] != numeric_limits<int>::max())
                best[i] = min(best[i], best[val]+routers[j].first);
        }
    }
    if(best[best.size()-1] != numeric_limits<int>::max())
        cout << best[best.size()-1];
    else cout << -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> m;
    ll costo, numpcs;
    REP(i,0,m){
        cin >> costo >> numpcs;
        ll pc, pcs = 0;
        REP(j, 0, numpcs){
            cin >> pc; 
            pcs |= (1<<(pc-1));
        }
        routers.emplace_back(costo,pcs);
    }
    calc();
}
