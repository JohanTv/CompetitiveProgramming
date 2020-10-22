#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

const int mxN = 8e3+5;
string s;
vector<int> indicesRotar;
vector<int> indicesMover;
int x_end, y_end;
int x_init = 0, y_init = 0;

bool check_x(int curr, int next, int x_init, bool direccion){
    int end;
    if(next >= indicesRotar.size()) end = s.size();
    else end = indicesRotar[next];

    int val = end-curr; 

    if(direccion) x_init += val;
    else x_init -= val;

    /*while(curr<end){
        if(direccion) ++x_init;
        else --x_init;
        ++curr;
    }*/
    if(next+1 >= indicesRotar.size() || end == s.size()){
        if(x_init == x_end)
            return true;
        return false;
    }
    if(check_x(indicesRotar[next+1]+1,next+2, x_init, !direccion) || 
            check_x(indicesRotar[next+1]+1,next+2, x_init, direccion)) return true;
    return false;
}
bool check_y(int curr, int next, int y_init, bool direccion){
    int end;
    if(next >= indicesRotar.size()) end = s.size();
    else end = indicesRotar[next];
    
    int val = end-curr; 

    if(direccion) x_init += val;
    else x_init -= val;
    
    /*while(curr<end){
        if(direccion) ++y_init;
        else --y_init;
        ++curr;
    }*/
    if(next+1 >= indicesRotar.size() || end == s.size()){
        if(y_init == y_end)
            return true;
        return false;
    }
    if(check_y(indicesRotar[next+1]+1,next+2, y_init, !direccion) || 
            check_y(indicesRotar[next+1]+1,next+2, y_init, direccion)) return true;
    return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> s >> x_end >> y_end;
    REP(i,0,s.size()) {
        if(s[i] == 'F') indicesMover.emplace_back(i);
        else indicesRotar.emplace_back(i);
    }

    if(indicesMover.size() >= abs(x_end)+abs(y_end)){
        if(check_x(indicesMover[0],0,0,true))
            if(check_y(indicesRotar[0]+1,1,0, true) || check_y(indicesRotar[0]+1,1,0, false)){
                cout << "Si";
                return 0;
            }
        cout << "No";
    }
    else cout<<"No";
}
