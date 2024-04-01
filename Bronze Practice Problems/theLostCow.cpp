#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
#define ll long long

void setIO(string s)
{
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void solve(ll x, ll y)
{
  // decides the direction of the target
  bool front = x < y ? 1 : 0;
  ll step = 1;
  bool direction = 1;
  ll totalStep = 0;
  ll worstCase = 9 * abs(x - y); // apparently this is the worst case of the steps traveled
  while (totalStep <= worstCase)
  {
    // determines whether the next move would meet the target
    if ((front && x + step >= y && direction) || (!front && x - step <= y && !direction))
    {
      totalStep += abs(x - y);
      break;
    }
    step *= 2;
    totalStep += step; // or else we have to factor in the steps for the round trip
    direction = !direction;
  }
  cout << totalStep;
}

int main()
{
  ios_base::sync_with_stdio(0);
  setIO("lostcow");
  ll N, M;
  cin >> N >> M;
  solve(N, M);
  return 0;
}