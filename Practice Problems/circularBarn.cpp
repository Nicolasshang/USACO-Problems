#include<bits/stdc++.h>
#define int long long

using namespace std;

void setIO(string s){
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int findSum(vector<int> capacity, int N, int idx){
  int sum = 0;
  int a = 1;
  for (int i = idx; i < N + (idx - 1); i++){
    sum += capacity[(i + 1) % N] * a;
    a++;
  }
  return sum;
}

signed main(){
  cin.tie(nullptr);
  setIO("cbarn");

  int N; cin >> N;
  vector<int> capacity(N), dist;
  for (int i = 0; i < N; i++){
    scanf("%lld", &capacity[i]);
  }

  for (int i = 0; i < N; i++){
    dist.push_back(findSum(capacity, N, i));
  }

  cout << *min_element(dist.begin(), dist.end());
}