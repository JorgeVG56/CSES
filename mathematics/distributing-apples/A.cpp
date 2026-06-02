#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll fact[2000005], invFact[2000005];

ll binPow(ll a, ll b){
  ll ret = 1;
  while(b){
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

ll comb(int n, int m){
  return fact[n] * invFact[m] % mod * invFact[n - m] % mod;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1; 
  for(ll i = 1; i < 2000005; i++) fact[i] = i * fact[i - 1] % mod;
  invFact[2000004] = binPow(fact[2000004], mod - 2);
  for(ll i = 2000004; i > 0; i--) invFact[i - 1] = i * invFact[i] % mod;

  ll n, m; cin >> n >> m;

  cout << comb(m + n - 1, n - 1) << '\n';

  return 0;
}