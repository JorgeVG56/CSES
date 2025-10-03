#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<vector<int>> adj(n);

  for(int u = 1; u < n; u++){
    int v; cin >> v; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> depth(n);
  vector<vector<int>> jmp(n, vector<int>(32, -1));

  auto dfs = [&](auto & self, int u, int p) -> void{
    if(p != -1) depth[u] = 1 + depth[p];
    jmp[u][0] = p;

    for(auto & v : adj[u]) if(v != p) self(self, v, u);
  };

  dfs(dfs, 0, -1);

  for(int i = 1; i < 32; i++){
    for(int u = 0; u < n; u++){
      if(jmp[u][i - 1] != -1){
        jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
      }
    }
  }

  for(int i = 0; i < q; i++){
    int x, k; cin >> x >> k; --x;

    for(int j = 0; j < 32; j++){
      if(x != -1 && (k >> j) & 1){
        x = jmp[x][j];
      }
    }

    if(x != -1) x++;

    cout << x << '\n';
  }

  return 0;
}