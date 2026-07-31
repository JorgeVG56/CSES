#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll binPow(ll a, ll b){
  ll ret = 1;
  while(b){
    if(b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  cout << binPow(2, n) << '\n';

  return 0;
}