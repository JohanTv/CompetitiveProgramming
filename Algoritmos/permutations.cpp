#include <bits/stdc++.h>
#define MAXSIZE 10000

using namespace std;

// next_permutacion(v.begin, v.end);


vector<int> p;
int n, usados[MAXSIZE]{0};

void escribir(){
    for(int i=0; i<p.size(); i++){
        cout << p[i];
    }
    cout << endl;
}

void generar(int i){
    if(i == n) {
        escribir(); return;
    }else{
        for(int e = 1; e <= n; e++){
            if(usados[e]) continue;
            p.push_back(e);
            usados[e] = 1;
            generar(i+1);
            p.pop_back();
            usados[e] = 0;
        }
    }

}
int main(){
    cin >> n;
    generar(0);
}