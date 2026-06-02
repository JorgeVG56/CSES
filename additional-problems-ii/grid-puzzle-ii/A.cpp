#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const ll INF = 1e9;

struct Edge{
  ll u, v, cap, cost;
};

vector<vector<ll>> adj, cost, cap;

void shortestPaths(int n, int u, vector<ll> & dp, vector<ll> & par){
  dp.assign(n, INF); dp[u] = 0;
  par.assign(n, -1); 
  vector<bool> vis(n); vis[u] = 1;
  queue<int> q; q.push(u);

  while(!q.empty()){
    int u = q.front(); q.pop();
    vis[u] = 0;
    for(int & v : adj[u]){
      if(cap[u][v] <= 0 || dp[v] <= dp[u] + cost[u][v]) continue;
      dp[v] = dp[u] + cost[u][v];
      par[v] = u;
      if(vis[v]) continue;
      vis[v] = 1;
      q.push(v);
    }
  }
}

int minCostFlow(int n, vector<Edge> & edges, int k, int s, int t){
  adj.assign(n, vector<int>());
  cost.assign(n, vector<int>(n));
  cap.assign(n, vector<int>(n));
  for(auto & e : edges){
    adj[e.u].push_back(e.v);
    adj[e.v].push_back(e.u);
    cost[e.u][e.v] = e.cost;
    cost[e.v][e.u] = -e.cost;
    cap[e.u][e.v] = e.cap;
  }

  ll flow = 0, cost = 0;
  vector<ll> dp, par;
  while(flow < k){
    shortestPaths(n, s, dp, par);
    if(dp[t] == INF) break;

    ll f = k - flow, cur = t;
    while(cur != s) f = min(f, cap[par[cur]][cur]), cur = par[cur];

    flow += f, cost += f * dp[t], cur = t;
    while(cur != s) cap[par[cur]][cur] -= f, cap[cur][par[cur]] += f, cur = par[cur];

  }

  if(flow < k) return -1;
  else return cost;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> rows(n); for(int & x : rows) cin >> x;
  vector<int> columns(n); for(int & x : columns) cin >> x;

  vector<vector<int>> grid(n, vector<int>(n)); for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grid[i][j];

  vector<Edge> edges;

  for(int i = 0; i < n; i++)
    edges.push_back({0, i + 1, rows[i], 0});
  
  for(int i = 0; i < n; i++)
    edges.push_back({n + i + 1, 2 * n + 1, columns[i], 0});

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      edges.push_back({i + 1, n + j + 1, 1, -grid[i][j]});

  int flow = accumulate(begin(rows), end(rows), 0);
  int minCost = -minCostFlow(2 * n + 2, edges, flow, 0, 2 * n + 1);
  if(flow != accumulate(begin(columns), end(columns), 0) || minCost == 1) cout << -1 << '\n';
  else{
    cout << minCost << '\n';
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++) cout << (cap[i + 1][n + j + 1] ? '.' : 'X');
      cout << '\n';
    }
  }


  return 0;
}