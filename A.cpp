#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, p, k; cin >> n >> p >> k;

  vector<pair<ll, int>> a(n); for(auto & [x, idx] : a) cin >> x;
  for(int i = 0; i < n; i++) a[i].second = i;

  vector<vector<ll>> b(n, vector<ll>(p));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < p; j++) {
      cin >> b[i][j];
    }
  }

  sort(rbegin(a), rend(a));
  int totalMask = (1 << p);
  vector<vector<ll>> dp(n + 1, vector<ll>(totalMask, -1)); dp[0][0] = 0;
  for(int i = 1; i <= n; i++) {
    auto [x, idx] = a[i - 1];
    for(int mask = 0; mask < totalMask; mask++) {
      int chosen = __builtin_popcount(mask);
      for(int j = 0; j < p; j++) {
        if((~mask >> j) & 1) continue; 
        int prev = mask ^ (1 << j);
        if(dp[i - 1][prev] == -1) continue;
        dp[i][mask] = max(dp[i][mask], dp[i - 1][prev] + b[idx][j]);
      }

      if(dp[i - 1][mask] == -1) continue;

      if(i - chosen <= k) dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + x);
      else dp[i][mask] = max(dp[i][mask], dp[i - 1][mask]);
    }
  }
  cout << dp[n][totalMask - 1] << '\n';

  return 0;
}