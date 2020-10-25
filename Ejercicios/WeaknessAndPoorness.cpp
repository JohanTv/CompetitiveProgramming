#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
using namespace std;

ll n, seq[ll(2e5)];

double f(double x){
    double sumMax, bestMax, sumMin, bestMin;
    sumMax = bestMax = sumMin = bestMin = seq[0]-x;
    REP(i, 1, n){
        sumMax = max(seq[i]-x, sumMax+seq[i]-x); 
        bestMax = max(bestMax, sumMax);
        sumMin = min(seq[i]-x, sumMin+seq[i]-1);
        bestMin = min(bestMin, sumMin);
    }
    return max(abs(bestMax), abs(bestMin));
}

int main(){
    cin >> n;
    REP(i, 0, n){
        cin >> seq[i];
    }
    double a = -1e5;
    double b = +1e5;
    double e = 1e-6;
    double r1, r2;

    for(int i=0; i<200; i++){
        double l1 = (2*a+b)/3.0;
        double l2 = (a+2*b)/3.0;
        r1 = f(l1); r2 = f(l2);
        if(r1 < r2) b = l2;
        else a = l1;
    }
    cout << r1;
}