#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  int accumulated = 0;
  for(ll x = 5; x <= n; x *= 5) {
    accumulated += n / x;
  }

  cout << accumulated << '\n';

  return 0;
}