#include <bits/stdc++.h>
using namespace std;

int n;

 vector<int> s;

 void escribir(){
  cout << "{";
  for(int i=0; i<(int)s.size(); i++){
    cout << s[i] << ",";
  }
  cout << "}" << endl;
 }

void generar(int i){
  if(i == n) escribir();
  else{
    generar(i+1);
    s.push_back(i+1);
    generar(i+1);
    s.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  generar(0);
  return 0;
}
