#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
 
  int n, k; cin >> n >> k;
 
  vector<vector<int>> adj(n);
 
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v; 
 
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
 
  vector<int> sz(n), alive(n, 1);
 
  auto dfsSZ = [&](auto & self, int u, int p) -> int{
    sz[u] = 1;
    for(auto & v : adj[u])
      if(v != p && alive[v])
        sz[u] += self(self, v, u);
    return sz[u];
  };
 
  auto getCentroid = [&](auto & self, int u, int p, int t) -> int{
    for(auto & v : adj[u])
      if(v != p && alive[v])
        if(sz[v] > t)
          return self(self, v, u, t);
 
    return u;
  };
 
  ll ans = 0;
  vector<int> cnt(k + 1);
  int mxD;
  cnt[0] = 1;
 
  auto dfs = [&](auto & self, int u, int p, int f, int d = 1) -> void{
    if(d > k) return;
    mxD = max(mxD, d);
    if(f == 1) ans += cnt[k - d];
    else cnt[d]++;
    for(auto v : adj[u])
      if(v != p && alive[v])
        self(self, v, u, f, d + 1);    
  };
 
  auto solve = [&](auto & self, int u = 0) -> void{
    int centroid = getCentroid(getCentroid, u, -1, dfsSZ(dfsSZ, u, -1) >> 1);
    alive[centroid] = 0;

    mxD = 0;
    
    for(auto & v : adj[centroid])
      if(alive[v]){
        dfs(dfs, v, centroid, 1);
        dfs(dfs, v, centroid, 0);
      }
 
    fill(begin(cnt) + 1, end(cnt) + mxD + 1, 0);

    for(auto & v : adj[centroid])
      if(alive[v])
        self(self, v);
  };

  solve(solve);
 
  cout << ans;
 
  return 0;
}