#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

double p;

//Idea: En primer lugar se define la funcion unimodal
//En este caso es la definida por la funcion f(x), el cual
//nos dice el tiempo que consume el algoritmo de acuerdo al valor p

//Espacio espacial = O(1)
//Espacio temporal = O(1) ya que se puede definir la cantidad de
//iteraciones, y es pequeña

double f(double x){
    return x+p/pow(2,x/1.5);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> p;
    double e = 1e-7;
    double a = 0,b = 100;
    double r1, r2, v1, v2;
    for(int i=0; i<60; i++){
        v1 = (2*a+b)/3.0; r1=f(v1);
        v2 = (a+2*b)/3.0; r2=f(v2);
        if(r1 < r2) b = v2;
        else a = v1;
    }
    printf("%.12f\n", f(a));
}