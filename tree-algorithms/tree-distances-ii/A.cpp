#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> adj;
vector<ll> sons, totalDistances;

void dfs1(ll u, ll p){
  for(ll & v : adj[u]){
    if(v == p) continue;
    dfs1(v, u);
    
    sons[u] += sons[v] + 1;
    totalDistances[u] += totalDistances[v] + sons[v] + 1;
  }
}

void dfs2(ll u, ll p){
  if(p != -1){
    totalDistances[u] += totalDistances[p] - totalDistances[u] + (int)totalDistances.size() - 2 * sons[u] - 2;
  }

  for(ll & v : adj[u]){
    if(v == p) continue;

    dfs2(v, u);
  }
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  sons.resize(n);
  totalDistances.resize(n);
  adj.resize(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;

    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  dfs1(0, -1);
  dfs2(0, -1);

  for(ll & x : totalDistances) cout << x << ' ';

  return 0;
}