#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3;
const int TURN_NUMBER = 100;
signed main()
{
  vector<int> capacity(N);
  vector<int> milk(N);
  for (int i = 0; i < N; i++){
    scanf("%d %d", &capacity[i], &milk[i]);
  }

  for (int i = 0; i < TURN_NUMBER; i++){
    int now = i % 3;
    int next = (i + 1) % 3;

    int amt = min(milk[now], capacity[next] - milk[next]);
    milk[now] -= amt;
    milk[next] += amt;
  }
  for (int i : milk){
    cout << i << endl;
  }
}
