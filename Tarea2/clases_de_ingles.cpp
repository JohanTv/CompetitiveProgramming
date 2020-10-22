#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a; i<b; ++i)
#define REPI(i,a,b) for(int i=a; i>b; --i)
#define all(x) x.begin(), x.end()
#define sub(x,k) x.begin(), x.begin()+k
typedef long long ll;
using namespace std;

const int mxN = 1e3+5;
int n;
vector<char> students(mxN);
int cantH = 0; 
int cantT = 0;
int min_changes = mxN;

// Idea: Como es calcular la cantidad de intercambios minimos para que los 
// mismos tipos de estudiantes se encuentren juntos, por lo tanto iteramos en el string
// y analizamos izquierda y derecha la cantidad de intercambios que se harían y con una
// variable global MIN, encontramos el minimo de intercambios que se tendrian que realizar

// Complejidad temporal: O(max{m,n}2)
// Compljidad espacial: O(n)

void left_check(char eval, int pos){
    int cant = 0;
    int group;
    if(eval == 'H') group = cantH-1;
    else group = cantT-1;
    if(pos == -1) pos = n-1;
    while(group--){
        if(students[pos] != eval) ++cant;
        --pos;
        if(pos == -1) pos = n-1;
    }
    if(cant < min_changes) min_changes = cant;
}
void right_check(char eval, int pos){
    int cant = 0;
    int group;
    if(eval == 'H') group = cantH-1;
    else group = cantT-1;
    if(pos == n) pos = 0;
    while(group--){
        if(students[pos] != eval) ++cant;
        ++pos;
        if(pos == n) pos = 0;
    }
    if(cant < min_changes) min_changes = cant;
}

void calc(){
    REP(i,0,n){
        left_check(students[i], i-1);
        right_check(students[i], i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin >> n;
    char c;
    REP(i,0,n){
        cin >> c;
        if(c == 'H') ++cantH;
        else ++cantT;
        students[i] = c;
    }
    calc();
    cout << min_changes;
}
