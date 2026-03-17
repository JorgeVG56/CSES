#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<int, int>> a(n); 
  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[i] = {x, i};
  } 

  sort(begin(a), end(a));

  int maxDiff = 0;
  for(int i = 0; i < n; i++) maxDiff = max(maxDiff, a[i].second - i);

  cout << maxDiff << '\n';

  return 0;
}