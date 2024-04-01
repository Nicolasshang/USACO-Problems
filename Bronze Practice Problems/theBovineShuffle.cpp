#include <bits/stdc++.h>
using namespace std;

void setIO(string s){
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO("shuffle");

  int N;
  cin >> N;
  vector<int> To(N), Cows(N), New(N);
  for (int i = 0; i < N; i++)
    scanf("%d", &To[i]);
  for (int j = 0; j < N; j++)
    scanf("%d", &Cows[j]);

  for (int k = 0; k < 3; k++){
    for (int idx = 0; idx < N; idx++){
      New[idx] = Cows[To[idx] - 1];
    }
    Cows = New;
  }
  for (int temp : New) 
    cout << temp << endl;
}