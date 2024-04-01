#include <algorithm>
#include <cstdio>
#include <vector>

using std::vector;

int main()
{
  freopen("shell.in", "r", stdin);

  int n;
  scanf("%d", &n);

  // shell_at_pos[i] stores the label of the shell located at position i
  vector<int> shell_at_pos(3);
  // Place the shells down arbitrarily
  for (int i = 0; i < 3; i++)
  {
    shell_at_pos[i] = i;
  }

  // counter[i] stores the number of times the shell with label i was picked
  vector<int> counter(3);
  for (int i = 0; i < n; i++)
  {
    int a, b, g;
    scanf("%d %d %d", &a, &b, &g);
    // Zero indexing: offset all positions by 1
    a--, b--, g--;

    // Perform Bessie's swapping operation
    std::swap(shell_at_pos[a], shell_at_pos[b]);
    // Count the number of times Elsie guesses each particular shell
    counter[shell_at_pos[g]]++;
  }

  freopen("shell.out", "w", stdout);
  printf("%d\n", std::max({counter[0], counter[1], counter[2]}));
}