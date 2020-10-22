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
// e -> parent, s -> node to process
void dfs(int s, int e){
  for(auto u : adj[s]){
    if(u != e) dfs(u,s);
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
}
