#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

ll n;
ll seq[ll(2e5)];
ll dp[ll(2e5)];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n;
    REP(i, 0, n) cin >> seq[i];

    dp[0] = 1;
    REP(i, 1, n){
        dp[i] = 1;
        REP(j, 0, i){
            if(seq[j] < seq[i]) dp[i] = max(dp[i], dp[j]+1);
        }
    }
    cout << *max_element(dp, dp+n);
}