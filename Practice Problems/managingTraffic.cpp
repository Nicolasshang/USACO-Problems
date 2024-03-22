#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void solve() {
  int n;
  cin >> n;

  string type[100];
  int low[100];
  int high[100];

  for (int i = 0; i < n; i++) {
    string t;
    int l, h;
    cin >> t >> l >> h;
    type[i] = t;
    low[i] = l;
    high[i] = h;
  }

  int ans_lower = -10000, ans_higher = 10000;

  for (int i = n - 1; i >= 0; i--) {
    if (type[i] == "none") {
      ans_lower = max(ans_lower, low[i]);
      ans_higher = min(ans_higher, high[i]);
    } else if (type[i] == "off") {
      ans_lower += low[i];
      ans_higher += high[i];
    } else if (type[i] == "on") {
      ans_higher -= low[i];
      ans_lower -= high[i];
    }
  }

  cout << max(0, ans_lower) << ' ' << ans_higher << '\n';

  ans_lower = -10000;
  ans_higher = 10000;

  for (int i = 0; i < n; i++) {
    if (type[i] == "none") {
      ans_lower = max(ans_lower, low[i]);
      ans_higher = min(ans_higher, high[i]);
    } else if (type[i] == "on") {
      ans_lower += low[i];
      ans_higher += high[i];
    } else if (type[i] == "off") {
      ans_higher -= low[i];
      ans_lower -= high[i];
    }
  }

  cout << max(0, ans_lower) << ' ' << ans_higher << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO("traffic");

  solve();

  return 0;
}