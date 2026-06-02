#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mod = 1e9 + 7;

int fact[1000005], invFact[1000005];

int binPow(int a, int b){
  int ret = 1;
  while(b){
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

int comb(int n, int k){
  return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1;
  for(int i = 1; i < 1000005; i++) fact[i] = fact[i - 1] * i % mod;
  invFact[1000004] = binPow(fact[1000004], mod - 2);
  for(int i = 1000004; i > 0; i--) invFact[i - 1] = invFact[i] * i % mod;

  int n; cin >> n;

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;

    cout << comb(a, b) << '\n';
  }

  return 0;
}