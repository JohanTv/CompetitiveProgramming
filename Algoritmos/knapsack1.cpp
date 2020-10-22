#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

const int mxN = 1e5+5;
ll n,x,sum=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n;
    vector<int> pesos(n+1,0);
    REP(i,0,n) cin>>pesos[i+1];
    REP(i,0,n) sum += pesos[i+1];
    
    vector<pair<bool,int>> possible(sum+1,make_pair(false,0));
    vector<vector<int>> combinaciones(sum+1);
    combinaciones[0].emplace_back(0);
    possible[0].first = true;
    for (int k = 1; k <= n; k++) {
        for (int x = sum; x >= 0; x--) {
            if (possible[x].first) {
                int val = x+pesos[k];
                if(possible[val].second == 0){
                    combinaciones[val].insert(combinaciones[val].end(),combinaciones[x].begin(),combinaciones[x].end());
                    combinaciones[val].emplace_back(pesos[k]);
                    possible[val].first = true;
                    possible[val].second = 1;
                }
            }
        }
    }
    string s;
    REP(i,0,sum+1){
        s = possible[i].first ? "Si" : "NO";
        cout << i << ": " << s << " -> ";
        REP(j,0,combinaciones[i].size()) cout << combinaciones[i][j] << " ";
        cout << endl;
    }
    

    /*
        vector<bool> possible(x_sum+1,false);
        possible[0] = true;
        
        for (int k = 1; k <= mov_x.size(); k++) {
            for (int x = x_sum; x >= 0; x--) {
                if (possible[x]) possible[x+mov_x[k-1]] = true;
            }
        }
        return possible[right] && possible[left];*/
}
