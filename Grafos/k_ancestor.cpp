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
vector<vi> anc(mxN, vi((int)log2(mxN)));
vll adj[mxN];
ll nodes, l;
void dfs(int x, int p){
  anc[x][0] = p;
  for(int i=1; i<=l; i++){
    anc[x][i] = anc[anc[x][i-1]][i-1];
  }
  for(auto v : adj[x]){
    if(v == p) continue;
    dfs(v,x);
  }
}

int query(int x, int k){
  int t = log2(k);
  int an = x;
  for(int p=0; p<=t; ++p){
    if((1<<p) & k){
      an = anc[an][p];
    }
  }
  return an>0 ? an : -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    // V = E-1
    cin>>nodes;
    l = log2(nodes-1);
    ll u,v;
    REP(i, 0, nodes-1){
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1,0);
    ll t; cin>>t;
    while(t--){
      ll x, k; cin >> x >> k;
      cout << query(x,k) << endl;
    }
}
