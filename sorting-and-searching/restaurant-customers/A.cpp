#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<int, int>> a(n); for(auto & [x, y] : a) cin >> x >> y;

  vector<pair<int, int>> b; for(auto & [x, y] : a) b.push_back({x, 1}), b.push_back({y, -1});

  sort(begin(b), end(b));

  int mx = 0, cur = 0;
  for(auto & [x, y] : b){
    cur += y;
    mx = max(mx, cur);
  }

  cout << mx << '\n';

  return 0;
}