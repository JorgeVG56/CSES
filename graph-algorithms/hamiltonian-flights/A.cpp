#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MOD = 1e9 + 7;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++) {
    int u, v; cin >> u >> v; --u, --v;
    adj[v].push_back(u);
  }

  int totalMask = (1 << n);
  vector<vector<int>> dp(n, vector<int>(totalMask)); dp[0][1] = 1;
  for(int mask = 2; mask < totalMask; mask++) {
    if(~mask & 1) continue;
    for(int u = 1; u < n; u++) {
      if(~(mask >> u) & 1) continue;
      int prev = mask ^ (1 << u);
      for(int v : adj[u]) {
        dp[u][mask] = (dp[u][mask] + dp[v][prev]) % MOD;
      }
    }
  }
  cout << dp[n - 1][totalMask - 1] << '\n';

  return 0;
}