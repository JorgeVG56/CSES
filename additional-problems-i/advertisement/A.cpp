#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(ll & x : a) cin >> x;

  stack<pair<ll, ll>> st;

  ll maxArea = 0;

  for(int i = 0; i < n; i++){
    ll start = i;
    while(!st.empty() && a[i] < st.top().second){
      pair<ll, ll> tp = st.top(); st.pop();
      start = tp.first;
      maxArea = max(maxArea, tp.second * (i - tp.first));
    }
    st.push({start, a[i]});
  }

  while(!st.empty()){
    pair<ll, ll> tp = st.top(); st.pop();
    maxArea = max(maxArea, tp.second * (n - tp.first));
  }

  cout << maxArea << '\n';
  
  return 0;
}
