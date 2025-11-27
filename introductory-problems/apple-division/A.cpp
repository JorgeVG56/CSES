#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  ll ans = (ll) 1e18;

  for(int i = (1 << n) - 1; i >= 0; i--){
    ll sumL = 0, sumR = 0;

    for(int j = 0; j < n; j++){
      if((i >> j) & 1) sumL += a[j];
      else sumR += a[j];
    }

    ans = min(ans, abs(sumL - sumR));
  }

  cout << ans;
  
  return 0;
}
