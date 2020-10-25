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

void update(vll& v, ll n){
  ll a, b, value;
  cin >> a >> b >> value;
  a += n-1; b += n-1;
  for(int i = a; i <= b; i++){
    v[i] += value;
  }
  a /= 2; b /= 2;
  while(a <= b && a != 0){
    for(int i=a; i<=b; ++i){
      v[i] = v[2*i] + v[2*i+1];
    }
    a /= 2; b /= 2;
  } 
}

int main(){  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL),cout.tie(NULL);
  ll n, q; cin >> n >> q;
  vll segment(2*n);
  segment[0] = 0;
  for(int i=0; i<n; i++)
    cin>>segment[i+n];
  
  for(int i=n-1; i>0; --i)
    segment[i] = segment[2*i]+segment[2*i+1]; 
  ll op;
  while(q--){
    cin >> op;
    if(op == 1) update(segment, n);
    else{
      ll k; cin >> k;
      cout << segment[k+n-1] << endl;
    }
  }
}
