#include <bits/stdc++.h>
using namespace std;

int main(){
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int n; cin >> n;
  vector<int> v(26, 0);

  for (int i = 0; i < n; i++){
    string a; cin >> a;
    string b; cin >> b;
    for (int j = 0; j < 26; j++){
      // Adding an int to a char will automatically convert it to its corresponding ASCII value.
      // Also, C++ automatically converts all the chars in the strings to ASCII.
      v[j] += max(count(a.begin(), a.end(), 'a' + j), count(b.begin(), b.end(), 'a' + j));
    }
  }

  for (auto x : v)
    cout << x << endl;
}
