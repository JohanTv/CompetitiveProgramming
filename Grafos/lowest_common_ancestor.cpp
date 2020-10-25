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
vi nivel(mxN);
ll nodes, l;
void dfs(int x, int p){
  anc[x][0] = p;
  nivel[x] = nivel[p]+1;

  for(int i=1; i<=l; i++){
    anc[x][i] = anc[anc[x][i-1]][i-1];
  }
  
  for(auto v : adj[x]){
    if(v == p) continue;
    dfs(v,x);
  }
}

int kanc(int x, int k){
  if (k==0) return x;
  int t = log2(k);
  int an = x;
  for(int i=0; i<=t; i++){
    if((1<<p) & k){
      an = anc[an][i];
    }
  }
  return an>0 ? an : -1;
}

int lowest_common_anc(int a, int b){
  int k = abs(nivel[a]-nivel[b]);
  if(nivel[a]>= nivel[b]) a = kanc(a,k);
  else b = kanc(b,k);
  if (a==b) return a;
  for(int i=l; i>=0; i--){
    if(anc[a][i]!=
  }
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
}
