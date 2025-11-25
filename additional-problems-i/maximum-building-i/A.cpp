#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll maxArea(vector<int> & a){
  int n = (int) size(a);

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

  return maxArea;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<char>> a(n, vector<char>(m)); 
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];

  vector<vector<int>> dp(n, vector<int>(m));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      dp[i][j] = a[i][j] == '*' ? 0 : 1 + (i == 0 ? 0 : dp[i - 1][j]);

  ll ans = 0;

  for(int i = 0; i < n; i++) ans = max(ans, maxArea(dp[i]));

  cout << ans;
  
  return 0;
}
