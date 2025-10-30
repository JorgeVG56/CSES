#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct TarjanSolver{
  vector<vector<int>> & adj;
  vector<vector<int>> revAdj;
  vector<int> post, comp;
  vector<bool> visited;
  int timer = 0;
  int id = 0;

  TarjanSolver(vector<vector<int>> & adj) : adj(adj), revAdj(adj.size()), post(adj.size()), comp(adj.size()), visited(adj.size()){
    vector<int> nodes(adj.size());
    for(int u = 0; u < (int)adj.size(); u++){
      nodes[u] = u;
      for(int v : adj[u]) revAdj[v].push_back(u);
    }

    for(int u = 0; u < (int)adj.size(); u++) if(!visited[u]) fillPost(u);

    sort(begin(nodes), end(nodes), [&](int u, int v) -> bool { return post[u] > post[v]; });

    visited.assign(adj.size(), false);
    for(auto u : nodes) if(!visited[u]){ findComp(u); id++; }
  }

  void fillPost(int u){
    visited[u] = true;
    for(auto v : revAdj[u]) if(!visited[v]) fillPost(v);
    post[u] = timer++;
  }

  void findComp(int u){
    visited[u] = true;
    comp[u] = id;
    for(auto v : adj[u]) if(!visited[v]) findComp(v);
  }

  int compNum(){ return id; }
  int getComp(int u){ return comp[u]; }
};

struct Clause{
  int var1, var2;
  bool neg1, neg2;
};

vector<int> solveSat(vector<Clause> & clauses, int nVar){
  vector<vector<int>> adj(2 * nVar);

  for(auto & c : clauses){
    adj[2 * c.var1 + !c.neg1].push_back(2 * c.var2 + c.neg2);
    adj[2 * c.var2 + !c.neg2].push_back(2 * c.var1 + c.neg1);
  }

  TarjanSolver ts(adj);
  vector<vector<int>> comps(ts.compNum());
  for(int u = 0; u < 2 * nVar; u += 2){
    if(ts.getComp(u) == ts.getComp(u + 1)) return {};
    comps[ts.getComp(u)].push_back(u);
    comps[ts.getComp(u + 1)].push_back(u + 1);
  }

  vector<int> val(2 * nVar,  -1);
  for(auto & comp : comps){
    int setTo = 1;
    for(int u : comp){
      int neg = u % 2 ? u - 1 : u + 1;
      if(val[neg] != -1){
        setTo = !val[neg];
        break;
      }
    }

    for(int u : comp) val[u] = setTo;
  }

  vector<int> actualVal(nVar);
	for (int i = 0; i < nVar; i++) actualVal[i] = val[2 * i];
	return actualVal;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<Clause> clauses(n);
  for(int i = 0; i < n; i++){
    char s1; cin >> s1; 
    int x1; cin >> x1;
    char s2; cin >> s2; 
    int x2; cin >> x2;

    clauses[i] = {x1 - 1, x2 - 1, s1 == '-', s2 == '-'};
  }

  vector<int> solution = solveSat(clauses, m);

  if(solution.empty()){
    cout << "IMPOSSIBLE";
  } else{
    for(int i = 0; i < m; i++){
      cout << "-+"[solution[i]] << ' ';
    }
  }

  cout << '\n';

  return 0;
}