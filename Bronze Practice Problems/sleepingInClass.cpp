// The main idea is:
// 1. The sum of all of the numbers is always the same.
// And thus if the numbers were initially "1 2 3 1 1 1", the sum is 9,
// and thus the possibilities are '9', '3 3 3', '1 1 1 1 1 1 1 1 1'
// Bruteforce to find the factors of 9, and check each factor.
#include <bits/stdc++.h>
using namespace std;
int T, N;
int a[100'000];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (int i = 0; i != T; ++i) {
    cin >> N;
    int sum = 0;
    for (int i = 0; i != N; ++i) {
      cin >> a[i];
      sum += a[i];
    }
    vector<int> factors;
    if (sum == 0)
      factors = {0};
    else
      for (int i = 1; i <= sum; ++i) {
        if (sum % i == 0) factors.push_back(i);
      }

    int ans = INT32_MAX;
    for (auto f : factors) { // This program structure is interesting: The larger for loop handles resetting cursum/cont, while the nested one handles increasing curm and determining if a factor is going to work or not.
      bool cont = false;
      int curm = 0, cursum = 0;
      if (f == 0) {  // If sum = 0
        ans = 0;
        break;
      }
      for (int i = 0; i != N; ++i) {
        cursum += a[i]; // Increases continuously until the program bails out (when cursum itself is bigger than the factor)
        if (cursum == f) {
          ++curm;
          cursum = 0;  // After every occurence of a multiple of f (let's say 3), resets so that we can detect another multiple.
        } else if (cursum > f) {  // If the cursum is bigger than the factor, it means that the factor by itself can no longer fill out the remaining space. Mathematically, when you subtract a factor from the sum, the remaining amount has to be a factor (or multiple of which) as well.
          cont = true;
          break;
        }
      }
      if (cont) continue;
      // Condition checks if curm * f = sum. In other words, if the cursum was actually in an index where there is a multiple of f. This statement also ONLY triggers at the end. This ensures that the algo won't miss terms.
      // N - curm is called because we only care about the terms that will merge into a three. In {1, 2, 3, 1, 1, 1}, {2, 3, 1} are the important digits. This is also because the entire list of numbers at this point condenses down to either {9}, {3, 3, 3}, or a string of 1's. The if statement is effectively eliminating the double-counted instances of the factors themselves.
      // If the list is just the same string of numbers again and again, curm would increase throughout the entire list (from the if(cursum == f) conditional), meaning that N - curm would be 0.
      if (curm == sum / f) ans = min(ans, N - curm);
    }
    cout << "ans: " << ans << endl;
  }
}