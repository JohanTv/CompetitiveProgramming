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
  ll k, value;
  cin >> k >> value;
  k = k + n - 1;
  v[k] = value;
  for(k = k/2; k>=1; k/=2)
   v[k] = min(v[2*k],v[2*k+1]); 
}

void minimum(vll& v, ll& n){
  ll a, b;
  cin >> a >> b;
  a += n-1; b += n-1;
  ll x = v[a];
  while(a <= b){
    if(a%2) x = min(x, v[a++]);
    if(!(b%2)) x = min(x, v[b--]);
    a = a/2; b = b/2;
  }
  cout << x << endl;
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
    segment[i] = min(segment[2*i],segment[2*i+1]); 
  ll op;
  while(q--){
    cin >> op;
    if(op == 1) update(segment, n);
    else minimum(segment, n);
  }
}
