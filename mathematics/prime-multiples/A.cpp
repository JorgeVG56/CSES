#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k; cin >> n >> k;

  vector<ll> primes(k); for(ll & prime : primes) cin >> prime;

  ll answer = 0;
  for(ll mask = 1; mask < (1 << k); mask++) {
    ll _lcm = 1, bitsOn = 0;
    for(ll i = 0; i < k; i++) {
      if((mask >> i) & 1) {
        if(_lcm > n / primes[i]) { _lcm = n + 1; break; }
        bitsOn++, _lcm *= primes[i];
      }
    }

    ll adding = n / _lcm;
    answer += (bitsOn & 1 ? adding : -adding);
  }

  cout << answer << '\n';

  return 0;
}