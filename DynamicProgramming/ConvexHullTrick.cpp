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
vector<double> u, p, d;
vector<pair<double, int>> interv;
double xx;

double interseccion(int i, int k){
  return (u[i]-u[k])/(d[k]-d[i]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    ll n; cin>>n;
    
    p.push_back(0);
    REP(i, 1, n+1){
     double a; cin>>a;
     p.push_back(a);
    }

    d.push_back(1);
    REP(i, 1, n+1){
      double a; cin>>a;
      d.push_back(a);
    }
    
    u.resize(n+1);
    u[0] = 0;
    // .first guarda el punto final del i-esimo intervalo
    // .second guarda el item asociado al i-esimo intervalo
    interv.push_back({mxN, 0});
    REP(i, 1, n+1){
      double x = p[i];
      auto idx = lower_bound(all(interv), make_pair(x, 0)) - interv.begin(); // el indice del intervalo
                                                          // donde se encuentra el elemento
      int j = interv[idx].second;
      u[i] = u[j]+d[j]*x; // optimo de i
      /* insertar nueva recta */
      while(interv.size()>0){
        int l = interv.size();
        int k = interv[l-1].second; // item asociado al ultimo intervalo
        xx = interseccion(i,k);
        if(l>2 && xx<interv[l-2].first){ // fi tapa a fk
          interv.pop_back();
        }else{
          interv[l-1].first = xx;
          interv.push_back({mxN,i});
          break;
        }
      }
      
    }
    cout << u[n] << endl;
}
