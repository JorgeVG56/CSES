#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct STree{
  int n; 
  vector<int> st;

  STree(int n) : n(n), st(2 * n){}

  void update(int idx, int x){
    for(st[idx += n] = x; idx > 1; idx >>= 1) st[idx >> 1] = max(st[idx], st[idx ^ 1]);
  }

  int query(int l, int r){
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1){
      if(l & 1) res = max(res, st[l++]);
      if(r & 1) res = max(res, st[--r]);
    }
    return res;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(auto & x : a) cin >> x;

  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> parent(n, -1), size(n, 1), head(n), pos(n), depth(n, 0);

  auto dfsSZ = [&](auto & self, int u) -> void{
    if(parent[u] != -1) adj[u].erase(find(begin(adj[u]), end(adj[u]), parent[u]));
    for(auto & v : adj[u]){
      depth[v] = depth[u] + 1;

      parent[v] = u;

      self(self, v);

      size[u] += size[v];

      if(size[v] > size[adj[u][0]]) swap(v, adj[u][0]);
    }
  };

  int t = 0;

  auto dfsHLD = [&](auto & self, int u) -> void{
    pos[u] = t++;
    for(auto & v : adj[u]){
      head[v] = (v == adj[u][0] ? head[u] : v);

      self(self, v);
    }
  };

  dfsSZ(dfsSZ, 0);
  dfsHLD(dfsHLD, 0);

  STree stHLD(n); for(int i = 0; i < n; i++) stHLD.update(pos[i], a[i]);

  auto getMaxPath = [&](int u, int v) -> int{
    int res = 0;

    while(head[u] != head[v]){
      if(depth[head[u]] > depth[head[v]]){
        int q = stHLD.query(pos[head[u]], pos[u] + 1);
        if(res < q) res = q;
        u = parent[head[u]];
      } else{
        int q = stHLD.query(pos[head[v]], pos[v] + 1);
        if(res < q) res = q;
        v = parent[head[v]];
      }
    }

    int q = stHLD.query(min(pos[u], pos[v]), max(pos[u], pos[v]) + 1);
    if(res < q) res = q;

    return res;
  };

  // for(int i = 0; i < n; i++) cout << i << ' '; 
  // cout << '\n';
  // for(int i = 0; i < n; i++) cout << parent[i] << ' ';
  // cout << '\n';
  // for(int i = 0; i < n; i++) cout << head[i] << ' '; 
  // cout << '\n';
  // for(int i = 0; i < n; i++) cout << pos[i] << ' '; 
  // cout << '\n';
  // for(int i = 0; i < n; i++) cout << stHLD.query(i, i + 1) << ' '; 


  for(int i = 0; i < q; i++){
    int type; cin >> type;

    if(type & 1){
      int s, x; cin >> s >> x; --s;

      a[s] = x;
      stHLD.update(pos[s], x);
    } else{
      int u, v; cin >> u >> v; --u, --v;

      cout << getMaxPath(u, v) << ' ';
    }
  }
  return 0;
}