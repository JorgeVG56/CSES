#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int n, k1, k2; cin >> n >> k1 >> k2;
  
  vector<vector<int>> adj(n);
  
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;
    
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  ll ans = 0;
  vector<int> sz(n), alive(n, 1);
  vector<int> cnt(k2 + 1), acum(k2 + 1); acum[0] = 1;
  int curD, maxD;
  
  auto dfsSZ = [&] (auto & self, int u, int p = -1) -> int {
    sz[u] = 1;
    for(int & v : adj[u]) if(alive[v] && v != p) sz[u] += self(self, v, u);
    return sz[u];
  };
  
  auto getCentroid = [&](auto & self, int u, int t, int p = -1) -> int {  
    for(int & v : adj[u]) if(alive[v] && v != p && sz[v] > t) return self(self, v, t, u);
    return u;
  };
  
  auto dfs = [&] (auto & self, int u, int p, int d = 1) -> void {
    if (d > k2) return;
    curD = max(curD, d);
    cnt[d] ++;
    for(int & v : adj[u]) if(alive[v] && v != p) self(self, v, u, d + 1);
  };
  
  auto solve = [&](auto & self, int u = 0) -> void{
    int centroid = getCentroid(getCentroid, u, dfsSZ(dfsSZ, u) >> 1);
    alive[centroid] = 0;
    maxD = 0;
    
    ll windowInit = (k1 == 1 ? 1ll : 0ll);
    for(int & v : adj[centroid]){
      if(alive[v]){
        curD = 0;
        dfs(dfs, v, centroid);

        ll window = windowInit; 
        for(int i = 1; i <= curD; i++){
          ans += cnt[i] * window;

          int idxRemove = k2 - i;
          if(idxRemove >= 0) window -= acum[idxRemove];
          int idxAdd = k1 - i - 1;
          if(idxAdd >= 0) window += acum[idxAdd];
        }
        
        for(int i = k1 - 1; i < k2 && i <= curD; i++)
          windowInit += cnt[i];

        for(int i = 1; i <= curD; i++)
          acum[i] += cnt[i];

        maxD = max(maxD, curD);
        
        fill(cnt.begin(), cnt.begin() + curD + 1, 0);
      }
    }
    
    fill(acum.begin() + 1, acum.begin() + 1 + maxD, 0);

    for(int & v : adj[centroid]) if(alive[v]) self(self, v);
  };

  solve(solve);
  
  cout << ans;
  
  return 0;
}