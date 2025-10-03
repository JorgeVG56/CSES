#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT{
  vector<ll> s;

  BIT(int n) : s(n) {}

  void update(int idx, ll x){
    for(; idx < (int)s.size(); idx |= idx + 1) s[idx] += x;
  }

  ll query(int idx){
    ll x = 0;
    for(; idx > 0; idx &= idx - 1) x += s[idx - 1];
    return x;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  vector<vector<int>> adj(n);
  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v; --u, --v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> in(n, -1), out(n, -1);

  int t = 0;

  auto dfs = [&](auto & self, int u, int p) -> void{
    in[u] = t++;
    for(auto & v : adj[u]) if(v != p) self(self, v, u);
    out[u] = t;
  };

  dfs(dfs, 0, -1);

  BIT bit(n);

  for(int i = 0; i < n; i++){
    bit.update(in[i], a[i]);
    bit.update(out[i], -a[i]);
  }

  for(int i = 0; i < q; i++){
    int type; cin >> type;

    if(type & 1){
      int s, x; cin >> s >> x; s--;

      bit.update(in[s], x - a[s]);
      bit.update(out[s], -x + a[s]);

      a[s] = x;
    } else{
      int s; cin >> s; s--;

      cout << bit.query(in[s] + 1) << '\n';
    }
  }

  return 0;
}