#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct TarjanSolver{
  vector<vector<int>> & adj;
  vector<vector<int>> revAdj;
  vector<int> post, comp;
  vector<bool> visited;
  int timer = 0;
  int id = 0;

  TarjanSolver(vector<vector<int>> & adj) : adj(adj), revAdj(adj.size()), post(adj.size()), comp(adj.size()), visited(adj.size()){
    vector<int> nodes(adj.size());
    for(int u = 0; u < (int)adj.size(); u++){
      nodes[u] = u;
      for(int v : adj[u]) revAdj[v].push_back(u);
    }

    for(int u = 0; u < (int)adj.size(); u++) if(!visited[u]) fillPost(u);

    sort(begin(nodes), end(nodes), [&](int u, int v) -> bool { return post[u] > post[v]; });

    visited.assign(adj.size(), false);
    for(auto u : nodes) if(!visited[u]){ findComp(u); id++; }
  }

  void fillPost(int u){
    visited[u] = true;
    for(auto v : revAdj[u]) if(!visited[v]) fillPost(v);
    post[u] = timer++;
  }

  void findComp(int u){
    visited[u] = true;
    comp[u] = id;
    for(auto v : adj[u]) if(!visited[v]) findComp(v);
  }

  int compNum(){ return id; }
  int getComp(int u){ return comp[u]; }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> a(n); for(auto & x : a) cin >> x;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
  }

  TarjanSolver ts(adj);

  vector<ll> comps(ts.compNum());
  for(int i = 0; i < n; i++){
    comps[ts.getComp(i)] += a[i];
  }
  
  vector<vector<int>> adjComp(ts.compNum());
  for(int u = 0; u < n; u++){
    for(int v : adj[u]){
      if(ts.getComp(u) == ts.getComp(v)) continue;
      adjComp[ts.getComp(u)].push_back(ts.getComp(v));
    }
  }

  vector<ll> dp(ts.compNum(), -1);

  auto dfs = [&](auto & self, int u) -> ll{
    if(dp[u] != -1) return dp[u];
    ll mx = 0;
    for(int v : adjComp[u]) mx = max(mx, self(self, v));
    return dp[u] = comps[u] + mx;
  };

  for(int u = 0; u < ts.compNum(); u++) if(dp[u] == -1) dfs(dfs, u);

  cout << *max_element(begin(dp), end(dp)) << '\n';

  return 0;
}