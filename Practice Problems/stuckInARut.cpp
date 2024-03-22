#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> north;
vector<array<int, 3>> east;
int myINF = 1e9;

#define f first
#define s second

int main()
{
  int N;
  cin >> N;
  vector<pair<int, int>> pos(N);
  for (int i = 0; i < N; i++)
  {
    char d;
    cin >> d;
    pair<int, int> p;
    cin >> p.first >> p.second;

    array<int, 3> varr = {p.f, p.s, i};
    if (d == 'E')
    {
      east.push_back(varr);
    }
    else
    {
      north.push_back(varr);
    }
    // Pos is for storage of the x and y of the cows by id (i), while the same information is also sorted into distinct north and east vectors. Pos makes it easier to fetch positions later on (without having to loop through both north and south vectors to look up a cow by id).
    pos[i] = p;
  }

  vector<vector<int>> meetTime;

  for (auto nC : north)
  {
    for (auto eC : east)
    {
      // Calculating the distance of the north cow and east cow to the point of collision (using x and y-components, respectively)
      int yT = eC[1] - nC[1];
      int xT = nC[0] - eC[0];

      if (xT == yT)
      {
        // If both cows just pass over each other
        continue;
      }

      if (yT > xT && xT > 0)
      {
        // If the eC stops the nC, the difference (time) on the Y axis will be recorded. the "0" is for identification later on.
        meetTime.push_back({yT, nC[2], eC[2], 0});
      }
      else if (yT < xT && yT > 0)
      {
        // The same thing, but if the nC stops the eC
        meetTime.push_back({xT, eC[2], nC[2], 1});
      }
    }
  }
  // Sorts all possible intersecions (elements of meetTime) into chronological order
  sort(meetTime.begin(), meetTime.end());

  vector<int> ans(N, myINF);

  for (auto mt : meetTime)
  {
    // Where the actual simulation begins
    if (ans[mt[2]] == myINF && ans[mt[1]] == myINF)
    {
      // If the distance of both cows are myINF at the start, then that means this collision hasnt been processed yet and the cow that got stopped (mt[2]) needs to have a distance (mt[1]) assigned to it. In other words, this if statement executes when both cows havent met anything yet.
      ans[mt[1]] = mt[0];
      continue;
    }
    if (ans[mt[1]] == myINF)
    {
      // However, processing every single collison won't be accurate because some mt[2]'s will be stopped before the "collision" with another mt[1] (because the double for loop before this does a full search of EVERY intersection of the paths of mt[1] and mt[2] cows, even the ones that won't be actually possible). 
      // Therefore, if the cow that stopped the other cow (mt[2]) has a value but the cow that got stopped (mt[1]) is still at myINF, we need to know if mt[2] got stopped before or after the potential collision with mt[1].

      if (mt[3])
      {
        // If the eC stopped the nC, this executes
        int start = pos[mt[2]].s;
        int end = start + ans[mt[2]];

        if (pos[mt[1]].s >= start && pos[mt[1]].s <= end)
        {
          // This condition tests if the blockage of mt[2] was before its possible intersection with mt[1]. 
          ans[mt[1]] = mt[0];
        }
      }
      else
      {
        // If the nC stopped the eC
        int start = pos[mt[2]].f;
        int end = start + ans[mt[2]];

        if (pos[mt[1]].f >= start && pos[mt[1]].f <= end)
        {
          ans[mt[1]] = mt[0];
        }
      }
      // And if mt[2] of a collision is stopped before it meets with mt[1], the collision doesn't happen and the latter will still have a distance of myINF (because the array is defaulted to fill with myINF).
      // The program then moves onto the next chronological collision to see if mt[1] (or mt[2]) can possibly collide with others. Since every collision is progressively checked and all previous blockings are considered (the mt[2] of one collision can become the mt[1] of another), every cow will have the correct distance in the end.
    }
  }

  for (auto v : ans)
  {
    if (v == myINF)
    {
      cout << "Infinity" << endl;
    }
    else
    {
      cout << v << endl;
    }
  }
}