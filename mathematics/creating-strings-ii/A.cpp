#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll fact[1000005], invFact[1000005];

ll binPow(ll a, ll b){
  ll ret = 1;
  while(b){
    if(b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  fact[0] = 1; 
  for(ll i = 1; i < 1000005; i++) fact[i] = i * fact[i - 1] % mod;
  invFact[1000004] = binPow(fact[1000004], mod - 2);
  for(ll i = 1000004; i > 0; i--) invFact[i - 1] = i * invFact[i] % mod;

  string s; cin >> s;

  int cnt[26]; memset(cnt, 0, sizeof(cnt));
  for(char c : s) cnt[c - 'a']++;

  ll ans = fact[s.size()];
  for(int i = 0; i < 26; i++) ans = ans * invFact[cnt[i]] % mod;

  cout << ans << '\n';

  return 0;
}