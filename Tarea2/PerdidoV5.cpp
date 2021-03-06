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

bool check_x(){
    ll right = abs((x_sum+x_end)/2);
    ll left = abs((x_sum-x_end)/2);
    ll value;
    if(right == 0) value = left;
    else value = right;
    if(calc2(mov_x,mov_x.size(),value)) return true;
    return calc(mov_x, mov_x.size(),value);
}

bool check_y(){
    ll bottom = abs((y_sum+y_end)/2);
    ll up = abs((y_sum-y_end)/2);
    ll value;
    if(bottom == 0) value = up;
    else value = bottom;
    if(calc2(mov_y,mov_y.size(),value)) return true;
    return calc(mov_y, mov_y.size(), value);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>s>>x_end>>y_end;
    int cont=0;
    bool x = true;
    REP(i,0,s.size()){
        if(s[i]=='F') ++cont;
        else{
            if(cont!=0){
                if(x) mov_x.emplace_back(cont);
                else mov_y.emplace_back(cont);
            }x = !x; cont = 0;
        }
    }
    if(cont!=0){
        if(x) mov_x.emplace_back(cont);
        else mov_y.emplace_back(cont);
    }
    REP(i,0,mov_x.size()) x_sum += mov_x[i];
    REP(i,0,mov_y.size()) y_sum += mov_y[i];
    //if(x_sum+y_sum >= abs(x_end)+abs(y_end)){
        if(check_x()){
            if(check_y()) cout<<"Si";
            else cout<<"No";
        }else cout<<"No";
    //}else cout<<"No";
}