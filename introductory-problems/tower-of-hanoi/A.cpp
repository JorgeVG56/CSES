#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n; cin >> n;
  
  cout << (1 << n) - 1 << '\n';
  
  auto hanoi = [&](auto & self, int size, int i, int r, int t) -> void {
    if(size == 0) return;
    self(self, size - 1, i, t, r);
    cout << i << ' ' << t << '\n';
    self(self, size - 1, r, i, t);
  }; hanoi(hanoi, n, 1, 2, 3);
 
  return 0;
}