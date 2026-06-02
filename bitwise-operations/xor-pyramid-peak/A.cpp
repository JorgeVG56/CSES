#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  int accum = 0;
  for(int i = 0; i < n; i++) 
    if(((n - 1) & i) == i) 
      accum ^= a[i];
  cout << accum << '\n';

  return 0;
}