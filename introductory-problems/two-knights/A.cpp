#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  for(ll k = 1; k <= n; k++){
    ll totalPlacements = k * k * (k * k - 1) / 2;
    ll badPlacements = 4 * (k - 1) * (k - 2);
    cout << totalPlacements - badPlacements << '\n';
  }

  return 0;
}