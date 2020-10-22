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

bool calc(vector<int> pesos, ll sum, ll primero, vector<int>& devolver){
    vector<pair<bool,int>> possible(sum+1,make_pair(false,0));
    vector<vector<int>> combinaciones(sum+1);
    combinaciones[0].emplace_back(0);
    possible[0].first = true;

    for (int k = 1; k <= pesos.size(); k++) {
        for (int x = sum; x >= 0; x--) {
            if (possible[x].first) {
                int val = x+pesos[k-1];
                if(possible[val].second == 0){
                    combinaciones[val].insert(combinaciones[val].end(),combinaciones[x].begin(),combinaciones[x].end());
                    combinaciones[val].emplace_back(pesos[k-1]);
                    possible[val].first = true;
                    possible[val].second = 1;
                }
            }
        }
    }
    if(possible[primero].first){
        devolver = combinaciones[primero];
        return true;
    }return false;
}

bool check_x(){
    //if((x_sum%2==0 && x_end%2==0)||(x_sum%2==1 && x_end%2==1)){
        ll right = abs((x_sum+x_end)/2);
        ll left = abs((x_sum-x_end)/2);
        vector<int> combinacionRight;
        if (calc(mov_x, x_sum, right, combinacionRight)){
            REP(i,0,combinacionRight.size()){
                REP(j,0,mov_x.size()){
                    if(combinacionRight[i] == mov_x[j]){
                        mov_x.erase(mov_x.begin()+j);
                        x_sum -= combinacionRight[i];
                        break;
                    }
                }
            }
            vector<int> combinacionLeft;
            if(x_sum == left) return true;
            if(x_sum > left)
                if (calc(mov_x, x_sum, left, combinacionLeft)) return true;
            return false;
        }else return false;

    //}return false;
}

bool check_y(){
   // if((y_sum%2==0 && y_end%2==0)||(y_sum%2==1 && y_end%2==1)){
        ll bottom = abs((y_sum+y_end)/2);
        ll up = abs((y_sum-y_end)/2);
        vector<int> combinacionBottom;
        if (calc(mov_y, y_sum, bottom, combinacionBottom)){
            REP(i,0,combinacionBottom.size()){
                REP(j,0,mov_y.size()){
                    if(combinacionBottom[i] == mov_y[j]){
                        mov_y.erase(mov_y.begin()+j);
                        y_sum -= combinacionBottom[i];
                        break;
                    }
                }
            }
            vector<int> combinacionUp;
            if(y_sum == up) return true;
            if(y_sum > up)
                if (calc(mov_y, y_sum, up, combinacionUp)) return true;
            return false;
        }else return false;


   // }return false;
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
    if(x_sum+y_sum >= abs(x_end)+abs(y_end)){
        if(check_x()){
            if(check_y()) cout<<"Si";
            else cout<<"No";
        }else cout<<"No";
    }else cout<<"No";
}