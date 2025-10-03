#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(int u, vector<vector<int>> & adj, vector<int> & ans){
  int sub = 0;

  for(int & v : adj[u]) sub += dfs(v, adj, ans);

  ans[u] = sub;

  return sub + 1;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++){
    int p; cin >> p;
    adj[p - 1].push_back(i);
  }

  vector<int> ans(n);

  dfs(0, adj, ans);

  for(int & x : ans) cout << x << ' ';

  return 0;
}