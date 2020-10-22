#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
typedef long long ll;
using namespace std;

const int mxN = 5000;

// Idea: Como nos piden los indices de los tres elementos que cumplan la condicion, 
// se inicializa un vector de pares, donde el first es el índice y el second es el valor que se recibe
// Se aplica la misma idea que el ejercicio de 2_sum, con la condicion de fijar un elemento y 
// dos punteros donde uno comienza al inicio y el otro al final

// Espacio temporal: O(n2)
// Espacio espacial: O(n)

ll n, x;
vector<pair<ll,ll>> v(mxN);

void check(){
    ll r, l, sum;
    REP(i, 0, n-2){
        r = i+1;
        l = n-1;
        while(r < l){
            sum = v[i].second + v[r].second + v[l].second;
            if(sum == x){
                cout << v[i].first+1 << " " << v[r].first+1 << " " << v[l].first+1;
                return;
            }else if(sum > x) --l;
            else ++r;
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n >> x;
    ll value;
    REP(i, 0, n) {
        cin >> value;
        v[i].first = i;
        v[i].second = value; 
    }
    sort(v.begin(), v.begin()+n, [](pair<ll,ll> a, pair<ll,ll> b){ return a.second < b.second; });
    check();
}