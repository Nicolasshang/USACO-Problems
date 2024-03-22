#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  int c[n];
  int t[n];

  for (int i = 0; i < n; ++i){
    cin >> c[i];
  }

  int d[n];
  for (int i = 0; i < n; ++i){
    cin >> t[i];

    // Calculates the time when closed - planned time of arrival. If the planned time of arrival is greater than the time closed, then d[i] would be negative. Therefore, all the farms that bessie can visit (not considering S) is positive here.
    d[i] = c[i] - t[i];
  }

  // After this is sorted, the negative (or equal) values will come first, followed by the larger values.  
  sort(d, d + n);
  for (int i = 0; i < q; ++i){
    int v, s;
    cin >> v >> s;

    // d[i] logs the difference between c[i] and t[i]. Therefore, if this difference is bigger than S, then S will "fit" into that gap betwen c[i] and t[i]. This also accounts for negative differences.
    // n - v is plugged into d[i] because now the d[i] vector is now a spectrum: At the end of d, t[i] is small, and thus, there is more "room" for S to fit into. If we work backwards down the vector, the increasing t[i] will give progressively less space for S to fit. But crucially, S must fit past the point d[v], because if it doesn't, that implies that the downward trend of the alloted space had already gone below c[i] - t[i] before d[v] (because the vector is sorted, creating a constant downward trend), making it mathematically impossible to accomodate S anymore. 
    if (d[n - v] > s){
      cout << "YES" << '\n';
    }
    else{
      cout << "NO" << '\n';
    }
  }
}