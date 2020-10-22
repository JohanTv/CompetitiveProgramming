#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

int n;
ll num[ll(2e5)];

// Idea: Como se requiere que la secuencia sea numeros consecutivos
// y concuerden con su posicion, con un contador se determina
// cuantos numeros consecutivos existe en la secuencia cada vez
// que se registran los canales
// Espacio temporal: O(n)
// Espacio espacial: O(n)

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int canal = 0;
    REP(i, 0, n){
        cin >> num[i];
        if(canal+1 == num[i]) canal++;
    }
    if(canal == 0) cout << -1;
    else cout << n - canal;
}