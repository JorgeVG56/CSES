#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<vector<int>> adj(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> sz(n, 1);

  auto dfs = [&](auto self, int u, int p) -> void{
    for(auto & v : adj[u]){
      if(v != p){
        self(self, v, u);

        sz[u] += sz[v];
      }
    }
  };

  dfs(dfs, 0, -1);

  auto find_centroid = [&](auto self, int u, int p) -> int{
    for(auto & v : adj[u]){
      if(v != p){
        if(sz[v] * 2 > sz[0]){
          return self(self, v, u);
        }
      }
    }

    return u;
  };

  cout << find_centroid(find_centroid, 0, -1) + 1;

  return 0;
}