#include<bits/stdc++.h>
#define long long int

using namespace std;
int t, stones;

signed main(){
  cin >> t;
  for (int i = 0; i < t; i++){
    cin >> stones;
    if (stones % 10 != 0){
      cout << "B";
    } else {
      cout << "E";
    }
  }
}