#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<pair<int, ll>>> adj(n + 1);
  for(int i = 0; i < m; i++){
    ll u, v, w; cin >> u >> v >> w; --u;
    adj[u].push_back({v, w});
    adj[v].push_back({u, -w});
  }

  vector<ll> preffix(n + 1, 0);
  vector<bool> vis(n + 1, 0);
  auto bfs = [&](int ini) -> bool {
    queue<int> q; q.push(ini); vis[ini] = 1;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(auto & [v, w] : adj[u]){
        if(vis[v]){
          if(preffix[v] != preffix[u] + w) return false;
          continue;
        }

        vis[v] = 1; preffix[v] = preffix[u] + w; q.push(v);
      }
    }
    return true;
  };

  auto fl = true;
  for(int u = 0; u < n; u++){
    if(!vis[u]) fl &= bfs(u);
  }

  if(fl){
    cout << "YES" << '\n';
    for(int i = 0; i < n; i++) cout << preffix[i + 1] - preffix[i] << ' ';
    cout << '\n';
  } else{
    cout << "NO" << '\n';
  }

  return 0;
}