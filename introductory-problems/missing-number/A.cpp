#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  ll x = (n % 4 == 0 ? n : (n % 4 == 1 ? 1 : (n % 4 == 2) ? n + 1 : 0));
  
  for(int i = 0; i < n - 1; i++){
    ll a; cin >> a; x ^= a;
  }

  cout << x;

  return 0;
}