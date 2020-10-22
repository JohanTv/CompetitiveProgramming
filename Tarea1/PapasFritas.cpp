#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

ll n;

// Idea: Utilizar fuerza bruta con una modificacion
// Ordenar el vector, y el tercer for recorre de forma inversa para poder
// encontrar el elemento que cumpla con la desigualdad v[i]+v[j] > v[k], ya que
// al recorrer de forma inversa estoy comparando los numeros grandes y el primer elemento
// que cumpla con la condicion es posible realizar un triangulo, entonces por transicion 
// v[k] > v[k-1] > ... > v[j], es decir k-j seria los triangulos que se puede formar y 
// saldriamos de esa iteracion, ya que el resto no es necesario comparar.

// Complejidad espacial = O(n)
// Complejidad temporal = O(n3)

void f(vector<ll>& num){
    sort(num.begin(), num.end());
    ll cant = 0;
    REP(i, 0, num.size()){
        REP(j, i+1, num.size()){
            REPI(k, num.size()-1, j){
                if(num[i]+num[j] > num[k]) {
                    cant+=k-j;
                    break;
                }
            }
        }
    }
    cout << cant;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n;
    vector<ll> num(n);
    REP(i, 0, n){
        cin >> num[i];
    }
    f(num);
}