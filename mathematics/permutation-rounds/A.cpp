#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = (int)1e9 + 7;

vector<pair<int, int>> factors(int n){
  vector<pair<int, int>> factors;

  for(int i = 2; i * i <= n; i++){
    if(n % i == 0){
      int c = 0;
      while(n % i == 0) n /= i, c++;
      factors.push_back({i, c});
    }
  }

  if(n > 1) factors.push_back({n, 1});

  return factors;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<bool> b(n);
  map<int, int> mp;

  for(int i = 0; i < n; i++){
    if(b[i]) continue;

    int cycleLen = 0, j = i;
    while(!b[j]){ cycleLen ++, b[j] = 1, j = a[j] - 1; }

    for(auto & [p, c] : factors(cycleLen)) mp[p] = max(mp[p], c);
  }

  ll ans = 1;
  
  for(auto & [p, c] : mp){
    for(int i = 0; i < c; i++) ans = (ans * p) % mod;
  }

  cout << ans << '\n';
  
  return 0;
}
