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
vi diam(mxN);
vi punta(mxN);

// x es la raiz, p es el padre
// DFS
void diamDP(int x, int p){
  diam[x] = 0;
  punta[x] = 0;
  int max1, max2;
  max1 = max2 = -1;
  for(auto v: adj[x]){
    if(v == p) continue;
    diamDP(v, x);
    
    diam[x] = max(diam[x], diam[v]);
    if (punta[v] > max1){
      max2 = max1;
      max1 = punta[v];
    }else if (punta[v] > max2){
      max2 = punta[v];
    }
  }
  if(max1 == -1 && max2 == -1) return;
  if(max2 == -1) diam[x] = max(diam[x], max1+1);
  else diam[x] = max(diam[x], max1+max2+2);
  punta[x] = max1+1;
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
    diamDP(2,2);
    cout << diam[2] << endl;
}
