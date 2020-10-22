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
ll max_subsequence(vll num){
  ll sumMax = num[0];
  REP(i, 1, num.size()){
    sumMax = max(sumMax, sumMax+num[i]);
  }
  return sumMax;
}

ll max_subarray(vll num){
  ll sumMax, bestMax;
  sumMax = bestMax = num[0];
  REP(i, 1, num.size()){
    sumMax = max(num[i], sumMax+num[i]);
    bestMax = max(sumMax, bestMax);
  }
  return bestMax;
}

int main(){
  ll n;
  cin >> n;
  vll values(n); 
  REP(i,0,n) cin >> values[i];
  cout << max_subarray(values) << endl;
  cout << max_subsequence(values) << endl;
}
