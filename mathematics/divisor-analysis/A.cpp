/*

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = (int)1e9 + 7;

ll binPow(ll a, ll b){
  ll r = 1;

  while(b){
    if(b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }

  return r;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  ll num = 1, sum = 1, product = 1, aux = 1;

  for(int i = 0; i < n; i++){
    ll p, x; cin >> p >> x;

    num = num * (x + 1) % mod;
    sum = sum * (binPow(p, x + 1) - 1 + mod) % mod * binPow(p - 1, mod - 2) % mod;
    product = binPow(product, x + 1) * binPow(binPow(p, x * (x + 1) / 2), aux) % mod;
    aux = aux * (x + 1) % (mod - 1);
  }

  cout << num << ' ' << sum << ' ' << product << '\n';
  
  return 0;
}
