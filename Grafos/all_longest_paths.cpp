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
vi dist1(mxN, 0); // el camino mas largo partiendo de un vertice pa abajo 
vi dist2(mxN, 0); // el camino mas largo partiendo de un vertice pa arriba
vi dist3(mxN, 0); // el segundo camino mas largo partiendo de un vertice pa abajo
vi sgte(mxN); // cual es el siguiente vertice del camino maximo partiendo de uno 
// p -> parent, x -> node to process
// Cantidad de nodos de todos los subarboles
void dfs1(int x, int p){
  for(auto u : adj[x]){
    if(u == p) continue;
      dfs1(u,x);
      if(dist1[u]+1 > dist1[x]){
        dist3[x] = dist1[x];
        dist1[x] = dist1[u]+1;
        sgte[x] = u;
      }else if(dist1[u]+1> dist3[x]){
        dist3[x] = dist1[u]+1;
      }
  }
}

void dfs2(int x, int p){
  for(auto u: adj[x]){
    if(u == p) continue;
    if(u == sgte[x]){
      dist2[u] = 1 + max(dist3[x], dist2[x]);
    }else{
      dist2[u] = 1 + max(dist2[x], dist1[x]);
    }
    dfs2(u,x); 
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    // V = E-1
    ll nodes; cin>>nodes;
    ll u,v;
    REP(i, 0, nodes-1){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs1(1,1);
    dfs2(1,1);
    REP(i,1,nodes+1){
      cout << max(dist1[i], dist2[i]) << " ";
    } cout << endl;
}
