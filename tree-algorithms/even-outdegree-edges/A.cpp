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

  vector<int> parity(n), visited(n);

  vector<pair<int, int>> edges;
  int timer = 0;

  auto dfs = [&](auto & self, int u, int p) -> void {
    visited[u] = ++timer;
    for(int v : adj[u]){
      if(v == p) continue;

      if(!visited[v]){
        self(self, v, u);
        if(parity[v]){
          parity[v] ^= 1;
          edges.push_back({v, u});
        } else{
          parity[u] ^= 1;
          edges.push_back({u, v});
        }
      } else if(visited[u] > visited[v]){
        parity[u] ^= 1;
        edges.push_back({u, v});
      }
    }
  };

  for(int u = 0; u < n; u++)
    if(!visited[u])
      dfs(dfs, u, -1);

  if(accumulate(begin(parity), end(parity), 0)) cout << "IMPOSSIBLE" << '\n';
  else for(auto [u, v] : edges) cout << u + 1 << ' ' << v + 1 << '\n';

  return 0;
}