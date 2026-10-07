#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 4e18;

vector<vector<ll>> mul(vector<vector<ll>> & a, vector<vector<ll>> & b) {
  int n = a.size();
  vector<vector<ll>> res(n, vector<ll>(n, INF));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      for(int k = 0; k < n; k++) {
        res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return res;
}

vector<vector<ll>> binPow(vector<vector<ll>> a, ll b) {
  int n = size(a);
  vector<vector<ll>> res(n, vector<ll>(n, INF)); for(int i = 0; i < n; i++) res[i][i] = 0;
  while(b) {
    if(b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k; cin >> n >> m >> k;

  vector<vector<ll>> adj(n, vector<ll>(n, INF));
  for(int i = 0; i < m; i++) {
    ll u, v, w; cin >> u >> v >> w; --u, --v;
    adj[u][v] = min(adj[u][v], w);
  }

  ll res = binPow(adj, k)[0][n - 1];
  cout << (res == INF ? -1 : res) << '\n';

  return 0;
}