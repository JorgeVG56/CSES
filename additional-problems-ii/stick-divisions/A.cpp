#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int x, n; cin >> x >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  priority_queue<int, vector<int>, greater<int>> pq;
  for(int & x : a) pq.push(x);

  ll ans = 0;
  while(size(pq) > 1){
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    ans += x + y; pq.push(x + y);
  }

  cout << ans << '\n';

  return 0;
}