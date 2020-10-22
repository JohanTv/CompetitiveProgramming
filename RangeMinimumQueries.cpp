#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int mxN = 2e5+5;
ll n, q;
vector<vll> matrix(30, vll(mxN, numeric_limits<int>::max()));

void preprocessing(){
  for(int i=1; i<=log2(n); ++i){
    for(int j=0; j<=n-pow(2,i); ++j){
      matrix[i][j] = min(matrix[i-1][j], matrix[i-1][j+(int)pow(2,i-1)]);
    }
  }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> q;
    REP(i,0,n) cin >> matrix[0][i];
    preprocessing();/
    ll a,b;
    while(q--){
      cin >> a >> b;
      --a; --b;
      int i = log2(b-a+1);
      cout << min(matrix[i][a], matrix[i][b-(int)pow(2,i)+1]) << '\n';
    }
}
