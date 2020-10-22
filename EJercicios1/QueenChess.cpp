#include <bits/stdc++.h>
#define MAXSIZE 1000
using namespace std;
int n, cont, col[MAXSIZE]{0}, diag1[MAXSIZE]{0}, diag2[MAXSIZE]{0};

void generar(int i){
    if(i == n){
        cont++; return;
    }else{
        for(int j=0; j<n; j++){
            if(col[j] || diag1[i+j] || diag2[i-j+n-1]) continue;
            col[j] = diag1[i+j] = diag2[j-i+n-1] = 1;
            generar(i+1);
            col[j] = diag1[i+j] = diag2[j-i+n-1] = 0;
        }
    }
}

int main(){
    cin >> n;
    cont = 0;
    generar(0);
    cout << cont;
}