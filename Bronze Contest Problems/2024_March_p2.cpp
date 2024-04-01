#include <bits/stdc++.h>
#define int long long
#define f first
#define s second

using namespace std;

signed main() {
  int N, P; cin >> N >> P;
  int x1, x2, y1, y2, dir = 0, axis = 0;
  vector<pair<int, int>> posts(P);
  vector<int> segments;

  for (int i = 0; i < P; i++) {
    cin >> posts[i].f >> posts[i].s;
  }

  for (int i = 0; i < N; i++) {
    cin >> x1 >> x2 >> y1 >> y2;
  }
}