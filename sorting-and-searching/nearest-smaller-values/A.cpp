#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  stack<pair<int, int>> st; st.push({a[0], 1});

  vector<int> b(n);

  for(int i = 1; i < n; i++){
    while(!st.empty() && a[i] <= st.top().first) st.pop();
    b[i] = (st.empty() ? 0 : st.top().second);
    st.push({a[i], i + 1});
  }

  for(int & x : b) cout << x << ' ';
  cout << '\n';
  
  return 0;
}
