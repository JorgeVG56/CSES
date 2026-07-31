#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  for(int x = 0; x < (1 << n); x++){
    int gray = x ^ (x >> 1);
    for(int bit = n - 1; bit >= 0; bit--)
      cout << ((gray >> bit) & 1);
    cout << '\n';
  }

  return 0;
}
