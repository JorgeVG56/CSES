#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  
  vector<int> succ(n); for(int & x : succ) cin >> x;

  vector<int> vis(n), answer(n);
  int timer = 0, cycleLen = 0;
  auto dfs = [&] (auto & self, int u) -> void {
    if(vis[u]){
      if(!answer[u]) answer[u] = cycleLen = timer - vis[u] + 1;
      return;
    }
    vis[u] = ++timer;
    self(self, succ[u] - 1);
    if(answer[u]) cycleLen = 0;
    else answer[u] = (cycleLen ? cycleLen : answer[succ[u] - 1] + 1);
  };

  for(int u = 0; u < n; u++){
    if(!answer[u]) dfs(dfs, u);
  }

  for(int x : answer) cout << x << ' ';
  cout << '\n';

  return 0;
}