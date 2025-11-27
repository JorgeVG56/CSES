#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;

  set<int> st; for(int & x : a) st.insert(x);

  cout << st.size() << '\n';
  
  return 0;
}
