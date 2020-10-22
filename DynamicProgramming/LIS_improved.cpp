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

ll solve(vll items){
  vll tail(items.size(),0);
  tail[0] = items[0];
  ll length = 1;
  REP(i, 1, items.size()){
    if(items[i] > tail[length-1]){
      tail[length] = items[i];
      length++;
    }
    else{
      ll index = lower_bound(tail.begin(), tail.begin()+length-1, items[i])-tail.begin();
      //cout << "iteration: "<< i << ", result: " << index << endl;
      tail[index]=items[i];
    }
  }
  return length;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n; cin>>n;
    vll v(n); REP(i,0,n) cin>>v[i];
    cout << solve(v)<< endl;
}
