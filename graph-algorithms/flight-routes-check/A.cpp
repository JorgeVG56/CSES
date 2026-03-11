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
    visited[u] = 1;
    comp[u] = id;
    for(auto v : adj[u]) if(!visited[v]) findComp(v);
  }

  int compNum(){ return id; }
  int getComp(int u){ return comp[u]; }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<vector<int>> adj(n);
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v; --u, --v;
    adj[u].push_back(v);
  }

  TarjanSolver ts(adj);
  
  int u = -1, v = -1;
  for(int i = 0; i < n; i++){
    if(ts.getComp(i) == 1) v = i;
    else u = i;
  }

  auto isReachable = [&](int u, int w) -> bool {
    queue<int> q; q.push(u); 
    vector<bool> vis(n, false); vis[u] = 1;
    while(!q.empty()){
      int tp = q.front(); q.pop();
      if(tp == w) return true;
      for(int v : adj[u]) if(!vis[v]) vis[v] = 1, q.push(v);
    }
    return false;
  };

  if(u == -1 || v == -1) cout << "YES" << '\n';
  else{
    cout << "NO" << '\n';
    if(isReachable(u, v)) swap(u, v);
    cout << u + 1 << ' ' << v + 1 << '\n';
  }

  return 0;
}