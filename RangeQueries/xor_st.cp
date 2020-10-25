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

void query_xor(vll& v, ll& n){
  ll a, b;
  cin >> a >> b;
  a += n-1; b += n-1;
  ll x = 0;
  while(a <= b){
    if(a%2) x = x ^ v[a++];
    if(!(b%2)) x = x ^ v[b--];
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
    segment[i] = segment[2*i] ^ segment[2*i+1]; 
  ll op;
  while(q--){
    query_xor(segment, n);
  }
}
