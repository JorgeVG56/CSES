#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0); 

  int n; cin >> n;

  vector<vector<int>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  vector<int> vis(n); vis[0] = 1;
  queue<pair<int, int>> q; q.push({0, 0});
  int lastVisited = -1;
  while(!q.empty()){
    auto [u, d] = q.front(); q.pop();
    lastVisited = u;

    for(int & v : adj[u]){
      if(vis[v]) continue;

      vis[v] = 1;
      q.push({v, d + 1});
    }
  }

  vis.assign(n, 0); vis[lastVisited] = 1;
  q.push({lastVisited, 0});
  int lastDistance = -1;
  while(!q.empty()){
    auto [u, d] = q.front(); q.pop();
    lastDistance = d;

    for(int & v : adj[u]){
      if(vis[v]) continue;

      vis[v] = 1;
      q.push({v, d + 1});
    }
  }

  cout << lastDistance;

  return 0;
}