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

  auto farthest = [&] (int u = 0) -> pair<int, int> {
    vector<int> vis(n); vis[u] = 1;
    queue<pair<int, int>> q; q.push({u, 0});
    pair<int, int> last;
    while(!q.empty()){
      last = q.front(); q.pop();
      auto [u, d] = last;

      for(int & v : adj[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        q.push({v, d + 1});
      }
    }
    return last;
  };

  pair<int, int> firstSearch = farthest();

  cout << farthest(firstSearch.first).second << '\n';

  return 0;
}