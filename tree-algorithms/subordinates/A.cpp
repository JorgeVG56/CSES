#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++){
    int p; cin >> p; p--;
    adj[p].push_back(i);
  }

  vector<int> ans(n);
  auto dfs = [&](auto & self, int u = 0) -> int {
    ans[u] = 0;
    for(auto v : adj[u]) ans[u] += self(self, v);
    return ans[u] + 1;
  };
  dfs(dfs);

  for(int & x : ans) cout << x << ' ';

  return 0;
}