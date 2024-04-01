/*

So in order to solve the problem, we first need to codify the strings based on
the type of expression, false/true/and/or.

If we compute the sequences of AND statements, the expression can be reduced to
a list of ORs and we know that if at least one of these variables is true, the
entire expression will be true.

So this leads us to the following idea: we want to find the most recent OR on
the left/right as well as the most recent FALSE on the left/right. Now whenever
we want to convert an entire sequence to a single variable, we know where these
things have last been found as well as when these false variables show.

Basically, all we have to do now is to find for each query where the most recent
OR lays to the left of L / to the right of R and if any of the subexpressions is
true, then the entire expression is true and we can't change anything with just
one variable replacement.

Otherwise, we need to look at the variables in the current range which are
bordered by ORs, and maybe a few other variables left over from the previous
sectors. If at least one of them is false (thing we can check using
lastfalseL/lastfalseR, then it's false no matter what). Else, we can make it
true or false as we want.

*/

#include <bits/stdc++.h>
using namespace std;

int n, q, tip[200002], lastorL[200002], lastorR[200002], lastfalseL[200002],
    lastfalseR[200002];
int evalL[200002], evalR[200002];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s[0] == 'f') tip[i] = 0;
    if (s[0] == 't') tip[i] = 1;
    if (s[0] == 'a') tip[i] = 2;
    if (s[0] == 'o') tip[i] = 3;
  }

  // precompute lastor arrays
  // This loop is smart because any index of the lastorL array you access, you will get the last OR statement at that index.
  for (int i = 1; i <= n; i++)
    if (tip[i] == 3)
      lastorL[i] = i;
    else
      lastorL[i] = lastorL[i - 1];

  lastorR[n + 1] = n + 1;
  for (int i = n; i >= 1; i--)
    if (tip[i] == 3)
      lastorR[i] = i;
    else
      lastorR[i] = lastorR[i + 1];

  // precompute lastfalse arrays
  lastfalseL[0] = -1;
  for (int i = 1; i <= n; i++)
    if (tip[i] == 0)
      lastfalseL[i] = i;
    else
      lastfalseL[i] = lastfalseL[i - 1];

  lastfalseR[n + 1] = n + 2;
  for (int i = n; i >= 1; i--)
    if (tip[i] == 0)
      lastfalseR[i] = i;
    else
      lastfalseR[i] = lastfalseR[i + 1];

  // precompute subexpressions for left/right
  // computation for left subexpression
  int overall = 0;
  for (int i = 1; i <= n;) {
    // i always stays on a true/false term, while j always stays on a conditional operator
    int j = i + 1;
    int val = tip[i];
    while (j <= n && tip[j] != 3) {
      val &= (tip[j + 1]);
      j += 2;
    }
    if (val == 1) overall = 1;
    // This puts the evaluation of the left expression at the index of every OR statement in evalL[]
    evalL[j] = overall;
    // Skip to the next section delineated by OR statements
    i = j + 1;
  }

  // computation for right subexpression
  int overall2 = 0;
  for (int i = n; i >= 1;) {
    int j = i - 1;
    int val = tip[i];
    while (j >= 1 && tip[j] != 3) {
      val &= (tip[j - 1]);
      j -= 2;
    }
    if (val == 1) overall2 = 1;
    evalR[j] = overall2;
    i = j - 1;
  }

  // dealing with the cases and the queries
  for (int i = 1; i <= q; i++) {
    int L, R;
    string x;
    cin >> L >> R;
    cin >> x;

    // Fetches the index of the most recent OR on the left and right, and uses evalL and evalR to check if the statement evaluates to true at that point in time
    // pL is "position of the most recent OR statement on the left" and pR is "position of the most recent OR statement on the right"
    int pL = lastorL[L];
    int pR = lastorR[R];

    // If either the left statement or the right statement is true, then the entire expression is true no matter what
    if (evalL[pL] || evalR[pR]) {
      if (x == "false")
        cout << "N";
      else
        cout << "Y";
    } else {
      // If both left and the right statements are false
      if (x == "false")
        cout << "Y";
      else if (lastfalseL[L - 1] >= pL || lastfalseR[R + 1] <= pR)
        // Detects if a false value is in the central statement, which makes it impossible to make the entire statement true
        cout << "N";
      else
        cout << "Y";
    }
  }
  return 0;
}