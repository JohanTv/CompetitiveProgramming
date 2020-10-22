#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

string s;
vector<int> mov_x;
vector<int> mov_y;
ll x_end, y_end;
ll x_sum=0, y_sum=0;

bool calc2(vector<int>num, int n, int x){
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

bool calc(vector<int> mov, int n, int sum){
    bool check[n+1][sum+1];

    REP(i,0,n+1) check[i][0] = true; 
    REP(i,1,sum+1) check[0][i] = false; 

    REP(i,1,n+1){
        REP(j,1,sum+1){
            if (j < mov[i-1]) 
                check[i][j] = check[i-1][j]; 
            if (j >= mov[i-1]) 
                check[i][j] = check[i-1][j] || check[i-1][j-mov[i-1]];
        }
    }
    return check[n][sum];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    return 0;
}