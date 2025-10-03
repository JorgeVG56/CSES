#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i];

  ll ans = 0, mx = a[0];

  for(int i = 1; i < n; i++){
    ans += max(0ll, mx - a[i]);

    mx = max(mx, a[i]);
  }

  cout << ans;

  return 0;
}