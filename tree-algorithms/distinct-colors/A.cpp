#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct BIT{
  vector<int> bit;
  int n;

  BIT(int n){
    this -> n = n;
    bit.assign(n, 0);
  }

  int sum(int r){
    int ret = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  int sum(int l, int r){
    return sum(r) - sum(l - 1);
  }

  void add(int i, int x){
    for(; i < n; i = i | (i + 1))
      bit[i] += x;
  }
};

int t = 0;
void dfs(int u, vector<vector<int>> & adj, vector<int> & in, vector<int> & out){
  in[u] = t++;

  for(int v : adj[u]) if(in[v] == -1) dfs(v, adj, in, out);

  out[u] = t;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(auto & x : a) cin >> x;

  vector<vector<int>> adj(n);

  for(int i = 0; i < n - 1; i++){
    int u, v; cin >> u >> v;

    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  vector<int> eulers(n, -1), in(n, -1), out(n, -1), change(n, -1);

  dfs(0, adj, in, out);

  for(int i = 0; i < n; i++){
    eulers[in[i]] = a[i];
    change[in[i]] = i;
  }

  map<int, int> mp;
  BIT bit(n);
  vector<int> ans(n);
  for(int i = n - 1; i >= 0; i--){
    if(mp.count(eulers[i])){
      bit.add(mp[eulers[i]], -1);
    }

    mp[eulers[i]] = i;
    bit.add(mp[eulers[i]], 1);
    ans[change[i]] = bit.sum(i, out[change[i]] - 1);
  }

  for(int & x : ans) cout << x << ' ';

  return 0;
}