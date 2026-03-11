#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> colour(n);
  auto bfs = [&] (int st) -> bool {
    queue<int> q; q.push(st); colour[st] = 1;
    while(!q.empty()){
      auto u = q.front(); q.pop();
      for(auto & v : adj[u]){
        if(colour[u] == colour[v]) return false;
        if(colour[v]) continue;
        colour[v] = (colour[u] & 1 ? 2 : 1);
        q.push(v);
      }
    }
    return true;
  };

  bool fl = 1;
  for(int i = 0; i < n; i++){
    if(!colour[i]) fl &= bfs(i);
  }

  if(fl) for(auto & x : colour) cout << x << ' ';
  else cout << "IMPOSSIBLE";

  cout << '\n';

  return 0;
}