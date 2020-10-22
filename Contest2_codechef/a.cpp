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
ll t, size;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> t;
    string A, B;
    bool possible;
    while(t--){
        cin >> size >> s;
        /*possible = false;
        for(int i=size-2; i>=size/2; --i){
            A = s.substr(0, i);
            B = s.substr(i+1, size-i-1);
            if(A.find(B) != std::string::npos){
                possible = true;
                break;
            }
        }
        if(possible) cout << "YES\n";
        else cout << "NO\n";*/
        possible = false;
        for(int i=0; i<size-1; i++){
            if(s[i] == s[size-1]){
                possible = true;
                break;
            }
        }
        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }

}
