#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int t; cin >> t;

  for(int c = 0; c < t; c++){
    int n, a, b; cin >> a >> b;

    if(a + b > n){
      cout << "NO" << '\n';
      continue;
    } else if(a && !b || b && !a){
      cout << "NO" << '\n';
      continue;  
    }
    vector<int> l(n), r(n);
    for(int i = 1; i < a; i++) l[i - 1] = i + 1, r[i - 1] = i;
    l[a - 1] = 1, r[a - 1] = a;
    for(int i = a + 1; i < a + b; i++) l[i - 1] = i + 1, r[i - 1] = i;
    l[a + b - 1] = a, r[a + b - 1] = a + b;
    for(int i = a + b + 1; i <= n; i++) l[i - 1] = i, r[i - 1] = i;

    cout << "YES" << '\n';
    for(int & x : l) cout << x << ' '; cout << '\n';
    for(int & x : r) cout << x << ' '; cout << '\n';
  }
  
  return 0;
}