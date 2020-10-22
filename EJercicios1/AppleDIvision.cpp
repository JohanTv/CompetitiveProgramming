#include <bits/stdc++.h>
using namespace std;

long long sumaTotal, p[20], sum, opt;
int n;

void generar(int i){
    if(i == n){
        opt = min(opt, abs(2*sum - sumaTotal));
        return;
    }
    generar(i+1);
    sum += p[i];
    generar(i+1);
    sum -= p[i];

}

int main(){
    cin >> n;
    sumaTotal = 0;
    sum = 0;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        sumaTotal += p[i];
    }
    opt = sumaTotal;
    generar(0);
    cout << opt;
}