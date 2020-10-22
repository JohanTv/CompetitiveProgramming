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

ll solve(vll num){
  vll length(num.size(),1);
  REP(k, 1, num.size()){
    REP(i, 0, k){
      if(num[i] < num[k]){
        length[k] = max(length[k], length[i]+1);
      }
    } 
  }
  ll result = *max_element(all(length));
  return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n;
    cin>>n;
    vll v(n);
    REP(i, 0, n) cin>>v[i];
    cout << solve(v) << endl;
}
