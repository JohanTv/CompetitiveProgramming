#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int mxN = 200;
map<ll,ll> values;
bool visited[mxN];
ll nodes;

void solve(vector<ll> adj[mxN], int u, int i){
    values[u] = pow(i,2);
    for(auto v: adj[u]){
        if(v == u || visited[v]) continue;
        visited[v] = true;
        values[v] = pow(i+1,2);
        solve(adj, v, i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll t;
    ll u,v;
    cin >> t;
    while(t--){
        vector<ll> adj[mxN];
        cin >> nodes;
        REP(i, 0, nodes) visited[i] = 0;
        values.clear();
        REP(i,0,nodes-1){
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        solve(adj, 1, 1);
        for(auto& it: values){
            cout << it.second << " ";
        }
        cout << "\n";
    }
}
