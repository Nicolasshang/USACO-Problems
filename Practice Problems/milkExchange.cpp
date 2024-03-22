#include<bits/stdc++.h>
using namespace std;

#define int long long
#define f first;
#define s second;

int n, temp, minutes, milkSum, amt;
string passes;
vector<int> capacity;
vector<int> milk;

signed main(){
  cin >> n >> minutes >> passes;
  for (int i = 0; i < n; i++){
    cin >> temp;
    temp = milk[i];
    temp = capacity[i];
    milkSum += temp;
  }

  for(int j = 0; j < minutes; j++){
    for (int i = 0; i < n; i++){
      int next = i % (n - 1);
      int prev = (i - 1) % n;

      if (passes[i] == 'R'){
        milk[i]--;
        milk[next]++;
      } else {
        milk[i]--;
        milk[prev]++;
      }
    }
  }

  for(int k = 0; k < milk.size(); k++){
    if (milk[k] > capacity[k]){
      milkSum -= milk[k] - capacity[k];
    }
  }

  cout << milkSum << endl;
}