#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const int mxN = 1e5+5;
ll n, x;
vector<ll> v(mxN);

bool check(){
    int i = 0, j = n-1;
    ll sum;
    while(i<j){
        sum = v[i]+v[j]; 
        if(sum == x) return true;
        else if(sum >= x) j--;
        else i++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> x;
    REP(i, 0, n) cin >> v[i];
    sort(all(v));
    if(check()) cout << "yiii";
    else cout << "uwu";
}
