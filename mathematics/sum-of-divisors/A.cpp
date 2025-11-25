#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll rangeSum(ll l, ll r){ return (r * (r + 1) / 2 - l * (l - 1) / 2 + 1000000000 * mod) % mod; }

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  ll ans = 0, cnt = 1;

  while(cnt <= n){
    ll occurrencies = n / cnt;
    ll maxOcurrencies = n / occurrencies - cnt + 1ll;
    ans = (ans + occurrencies * rangeSum(cnt % mod, (cnt + maxOcurrencies - 1) % mod) % mod) % mod;
    cnt += maxOcurrencies;
  }

  cout << ans << '\n';

  return 0;
}