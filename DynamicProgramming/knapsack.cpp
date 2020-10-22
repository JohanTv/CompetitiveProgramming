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

vector<bool> solve_knapsacks_possibles(vll num){
  ll sum = 0;
  for(auto item : num) sum += item;
  vector<bool> possible(sum+1,false);
  possible[0] = true;
  REP(i, 0, num.size()){
    for(ll x=sum; x>=0; --x)
      if(possible[x]) possible[x+num[i]] = true;
  }
  return possible;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n; cin >> n;
    vll num(n);
    REP(i,0,n) cin >> num[i];
    ll sum = 0;
    REP(i, 0, n) sum += num[i];
    if(solve_knapsacks_possibles(num)[sum]) cout << "yes" << endl;
    else cout << "no" << endl;
}
