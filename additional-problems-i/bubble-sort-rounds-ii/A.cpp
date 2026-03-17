#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  vector<int> a(n); for(int & x : a) cin >> x;

  priority_queue<int, vector<int>, greater<int>> pq(begin(a), begin(a) + min(k + 1, n));

  for(int i = 0; i < n; i++){
    cout << pq.top() << ' '; pq.pop();
    if(i + k + 1 < n) pq.push(a[i + k + 1]);
  }

  cout << '\n';

  return 0;
}