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
// p -> parent, x -> node to process
void dfs(int x, int p){
  for(auto u : adj[x]){
    if(u == p) continue;
    dfs(u,x);
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n; cin >> n;
    ll u,v;
    for(int i=1; i<n; ++i){
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1,0);
}
