#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int mxN = 1e5+5;
vi adj[mxN];

// x es la raiz, p es el padre
// DFS
// A partir de un vertice arbitrario(v) encuentro el extremo del camino maximo que
// comienza en v
// Luego se realiza otro dfs del extremo calculado y obtenemos la distancia
pair<int, int> dfs(int x, int p){
  pair<int, int> resx = {0, x};
  for(auto u : adj[x]){
    if(u == p) continue;
    auto resu = dfs(u, x);
    if(resu.first+1 > resx.first){
      resx.first = resu.first + 1;
      resx.second = resu.second;
    }
  }
  return resx;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll nodes; cin >> nodes;
    int u,v;
    REP(i,1, nodes){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    auto res1 = dfs(2,2);
    cout << dfs(res1.second, res1.second).first << endl;
}
