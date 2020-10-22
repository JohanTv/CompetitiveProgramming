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
vector<int> count_dfs(mxN, 1);
vector<int> adj[mxN];
// e -> parent, s -> node to process
// Cantidad de nodos de todos los subarboles
void dfs_count(int s, int e){
  for(auto u : adj[s]){
    if(u == e) continue;
      dfs_count(u,s);
      count_dfs[s] += count_dfs[u];
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
    dfs_count(1,0);
    REP(i,1,nodes+1){
      cout << count_dfs[i] << " ";
    }
}
