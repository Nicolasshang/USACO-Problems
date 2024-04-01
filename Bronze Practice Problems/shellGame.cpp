#include <bits/stdc++.h>
#define int long long

using namespace std;

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  setIO("shell");

  int n, a, b, g;
  vector<int> pos = {0, 1, 2};
  vector<int> correct(3);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> g;
    a--;
    b--;
    g--;
    swap(pos[a], pos[b]);
    correct[pos[g]]++;
  }
  cout << max({correct[0], correct[1], correct[2]}) << endl;
}