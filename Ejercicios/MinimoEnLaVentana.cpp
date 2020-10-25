#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

const int mxN = 1e5+5;
ll n, k;
vector<ll> v(mxN);
deque<ll> controlMin;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> k;
    REP(i, 0, k){
        cin >> v[i];
        while(!controlMin.empty() && controlMin.back()>v[i]) controlMin.pop_back();
        controlMin.push_back(v[i]);
    }
    REP(i, k, n){
        cout << controlMin.front() << " "; 
        cin >> v[i];
        if(v[i-k] == controlMin.front()) controlMin.pop_front();
        while(!controlMin.empty() && controlMin.back()>v[i]) controlMin.pop_back();
        controlMin.push_back(v[i]);
    }
    cout << controlMin.front(); 
}

