#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> mxLength, adj;

void dfs1(int u, int p){
  mxLength[u][0] = 0;
  mxLength[u][1] = 0;

  for(int & v : adj[u]){
    if(v == p) continue;
    
    dfs1(v, u);

    if(mxLength[v][0] + 1 > mxLength[u][0]){
      mxLength[u][1] = mxLength[u][0];
      mxLength[u][0] = mxLength[v][0] + 1;
      mxLength[u][2] = v;
    } else if(mxLength[v][0] + 1 > mxLength[u][1]){
      mxLength[u][1] = mxLength[v][0] + 1;
    }
  }
}

void dfs2(int u, int p){
  for(int & v : adj[u]){
    if(v == p) continue;

    if(mxLength[u][2] == v){
      if(mxLength[u][1] + 1 > mxLength[v][0]){
        mxLength[v][1] = mxLength[v][0];
        mxLength[v][0] = mxLength[u][1] + 1;
        mxLength[v][2] = u;
      } else if(mxLength[u][1] + 1 > mxLength[v][1]){
        mxLength[v][1] = mxLength[u][1] + 1;
      }
    } else{
      mxLength[v][1] = mxLength[v][0];
      mxLength[v][0] = mxLength[u][0] + 1;
      mxLength[v][2] = u;
    }

    dfs2(v, u);
  }
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  mxLength.assign(n, vector<int>(3));
  adj.resize(n);

  for(int i = 1; i < n; i++){
    int u, v; cin >> u >> v;

    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }

  dfs1(0, -1);
  dfs2(0, -1);

  for(auto & x : mxLength) cout << x[0] << ' ';

  return 0;
}