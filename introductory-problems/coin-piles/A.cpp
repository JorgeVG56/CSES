#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;

    if(max(a, b) <= 2 * min(a, b) && (min(a, b) - abs(a - b)) % 3 == 0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }

  return 0;
}