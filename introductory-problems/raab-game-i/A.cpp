#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n, a, b; cin >> n >> a >> b;

    if(a + b > n || (a && !b) || (b && !a)){
      cout << "NO" << '\n';
      continue;  
    }

    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    for(int i = 1; i <= n - a - b; i++) cout << i << ' ';
    for(int i = n - b + 1; i <= n; i++) cout << i << ' ';
    for(int i = n  - a- b + 1; i <= n - b; i++) cout << i << ' ';
    cout << '\n';
  }
  
  return 0;
}