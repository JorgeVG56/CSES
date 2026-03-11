#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<int, int>> a(n); for(auto & [x, y] : a) cin >> x >> y;

  sort(begin(a), end(a));

  vector<int> st(n), ed(n);
  for(int i = 0; i < n; i++) st[i] = a[i].first, ed[i] = a[i].second;

  vector<int> dp(n); dp[n - 1] = 1;
  for(int i = n - 2; i >= 0; i--){
    int position = lower_bound(begin(st) + i, end(st), ed[i]) - begin(st);
    dp[i] = max(dp[i + 1], 1 + (position == n ? 0 : dp[position]));
  }

  cout << dp[0] << '\n';

  return 0;
}