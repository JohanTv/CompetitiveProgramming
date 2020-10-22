#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;
const int mxN = 1e6+5;
deque<ll> controlMax;
deque<ll> controlMin;
vector<ll> num(mxN);
ll n, m, c;

// Idea: utilizar dos deques, enseñado en clase, tanto para tener el minimo y maximo en tienpo O(1)
// en cada subarreglo de tamaño m
// Complejidad temporal: O(n)
// Complejidad espacial: O(n) 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> m >> c;
    if(m > n) {cout << "NO"; return 0;}
    REP(i, 0, m){
        cin >> num[i];
        while(!controlMax.empty() && controlMax.back() < num[i]) controlMax.pop_back();
        while(!controlMin.empty() && controlMin.back() > num[i]) controlMin.pop_back();
        controlMax.push_back(num[i]);
        controlMin.push_back(num[i]);
    }
    REP(i, m, n){
        cin >> num[i];
    }
    ll cont = 0;
    for(int i=0; i < n-m+1; i++){
        if(controlMax.front() - controlMin.front() <= c){
            cout << i+1 << "\n";
            cont++;
        }
        if(i+m == n){
            break;
        }
        if(num[i] == controlMax.front()) controlMax.pop_front();
        if(num[i] == controlMin.front()) controlMin.pop_front();
        while(!controlMax.empty() && controlMax.back() < num[i+m]) controlMax.pop_back();
        while(!controlMin.empty() && controlMin.back() > num[i+m]) controlMin.pop_back();
        controlMax.push_back(num[i+m]);
        controlMin.push_back(num[i+m]);
    }
    if(cont == 0) cout << "NO";
}