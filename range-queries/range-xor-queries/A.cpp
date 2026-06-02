#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<int> preffix(n + 1); for(int i = 1; i <= n; i++) preffix[i] = preffix[i - 1] ^ a[i - 1];

  for(int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    cout << (preffix[b] ^ preffix[a - 1]) << '\n';
  }

  return 0;
}