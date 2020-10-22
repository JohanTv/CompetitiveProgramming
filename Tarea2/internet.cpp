#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

int n, m;
multimap<ll, unordered_set<int>> conexiones;
unordered_map<ll, pair<ll,vector<int>>> routers;
ll min = 1e18;
void calc(){
    for(ll i=1; i<(1<<m);++i){
        ll sum = 0;
        unordered_set<int> pcs;
        for(ll j=0; j<m;++j){
            if(i & (1<<j)){
                sum += routers[j].first;
                pcs.insert(all(routers[j].second));
            }
        }
        conexiones.insert(make_pair(sum,pcs));
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> m;
    ll costo, numpcs;
    REP(i,0,m){
        cin >> costo >> numpcs;
        vector<int> pcs(numpcs);
        REP(j, 0, numpcs) cin >> pcs[j];
        routers[i] = make_pair(costo,pcs);
    }
    calc();
    for(auto it : conexiones){
        if(it.second.size() == n) {
            cout << it.first;
            return 0;
        }
    }
    cout << -1;
}
