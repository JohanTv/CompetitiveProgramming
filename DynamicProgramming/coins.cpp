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

ll solve_coins(vll coins,ll x){
  vll value(x+1, numeric_limits<int>::max());
  value[0] = 0;
  REP(i,1,x+1){
    for(auto c: coins){
      if(i-c>=0)
        value[i] = min(value[i], value[i-c]+1);
    }
  }
  cout << endl;
  return value[x];
}

ll solve_coins_constructing(vll coins, ll x){
  vll value(x+1, numeric_limits<int>::max());
  vll first(x+1);
  value[0] = 0;
  REP(i, 1, x+1){
    for(auto c : coins){
      if(i-c >= 0 && value[i-c]+1 < value[i]){
          value[i] = value[i-c]+1;
          first[i] = c;
      }
    }
  }
  ll n = x;
  while(n>0){
    cout << first[n] << " ";
    n -= first[n];
  }
  cout << endl;
  return value[x];
}

ll solve_count_solutions(vll coins, ll x){
  vll values(x+1, 0);
  values[0] = 1;
  REP(i, 1, x+1){
    for(auto c:coins){
      if(i-c>=0) values[i] += values[i-c];
    }
  }
  REP(i, 0, x+1) cout << values[i] << " ";
  cout << endl;
  return values[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n, x;
    cin >> n >> x;
    vll v(n);
    REP(i, 0, n) cin>>v[i];
    cout << solve_coins(v, x) << endl;
    cout << solve_coins_constructing(v, x) << endl; 
    cout << solve_count_solutions(v, x) << endl;
}
