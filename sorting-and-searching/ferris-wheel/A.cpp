#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n, x; cin >> n >> x;

  vector<ll> weights(n); for(ll & weight : weights) cin >> weight;

  sort(begin(weights), end(weights));

  int l = 0, r = n - 1, ans = 0;

  while(l <= r){
    if(l == r || weights[l] + weights[r] <= x) ans++, l++, r--;
    else ans++, r--;
  }

  cout << ans << '\n';

  return 0;
}