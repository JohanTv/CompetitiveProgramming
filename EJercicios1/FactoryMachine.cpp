#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, machines[2*100000], products;
ll best = ll(1e9);
double calc;
bool check(ll value){
    ll sum=0;
    for(int i=0; i<n; i++){
        sum += value/machines[i];
    }
    return products <= sum;
}

int main(){
    cin >> n >> products;
    calc = 0.0;
    for(int i=0; i<n; i++){
        cin >> machines[i];
        if(machines[i] < best) best = machines[i];
    }   
    ll a = 0, b = products*best, rpta;
    while(a <= b){
        ll k = (a+b)/2;
        if(check(k)){ 
            rpta = k;
            b = k-1;
        }else a = k+1;
    }
    cout << rpta;
    
}