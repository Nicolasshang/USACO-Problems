#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;
  cin >> n;
  int r[n];
  for (int i = 0; i < n; i++)
  {
    cin >> r[i];
  }
  int distance = 999999999;
  for (int i = 0; i < n; i++)
  {
    int current_dis = 0;
    int current_room = i + 1;
    for (int j = 1; j < n; j++)
    {
      current_dis += (j * r[current_room % n]);
      current_room++;
    }
    distance = min(distance, current_dis);
  }

  cout << distance << "\n";

  return 0;
}