#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; i++)
#define REPI(i,a,b) for(int i=a; i>b; i--)
typedef long long ll;
using namespace std;

// enteros positivos 

int num[ll(1e1)];
int n, x;
bool check(){
    int sum = 0, j = 0;
    for(int i = 0; i < n; i++){
        while(sum < x && j < n){
            sum += num[j];
            j++;
        }
        if(sum == x) return true;
        sum -= num[i];
    }
    return false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    REP(i, 0, n) cin >> num[i];
    if(check()) cout << "yii" << endl;
    else cout << "uwu" << endl;
}