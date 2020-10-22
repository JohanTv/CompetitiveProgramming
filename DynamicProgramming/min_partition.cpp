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

void solve(vll values, ll x){
  ll n = values.size();
  
  vector<pair<ll,ll>> best(1<<n, {n+1,0});
  best[0] = {1, 0};
  for(ll s=1; s<(1<<n); s++){
    for(ll p=0; p<n; p++){
      if(s & (1<<p)){ // identifico el bit prendido, y procedo a quitarlo
        auto temp = best[s ^(1<<p)]; // cantidad minima de particiones si quitamos ese bit
        if(temp.second + values[p] <= x){
          temp.second += values[p];
        }else{
          ++temp.first;
          temp.second = min(temp.second, values[p]);
        }
        best[s] = min(best[s], temp);
      }
    }
  }

  cout << best[(1<<n)-1].first << endl;
}

int main(){
    ll n, x; cin>>n>>x;
    vll v(n);
    REP(i,0,n) cin>>v[i];
    solve(v,x);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
}
