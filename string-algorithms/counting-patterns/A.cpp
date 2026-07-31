#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
  int nxt[26];
  int suffix;
  int dict;
  int id;

  Node(){
    memset(nxt, -1, sizeof(nxt));
    suffix = dict = id = -1;
  }
};

vector<Node> nodes;

struct Trie{
  int root = -1;

  Trie(){
    root = size(nodes); 
    nodes.emplace_back();
  }

  void insert(string s, int id){
    int node = root;
    for(char c : s){
      if(nodes[node].nxt[c - 'a'] == -1){
        nodes[node].nxt[c - 'a'] = size(nodes); 
        nodes.emplace_back();
      }
      node = nodes[node].nxt[c - 'a'];
    }
    if(nodes[node].id == -1) nodes[node].id = id;
  }

  void bfs(){
    queue<int> q;
    for(int i = 0; i < 26; i++){
      if(nodes[root].nxt[i] == -1) continue;
      nodes[nodes[root].nxt[i]].suffix = root;
      q.push(nodes[root].nxt[i]);
    }

    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int i = 0; i < 26; i++){
        int v = nodes[u].nxt[i];
        if(v == -1) continue;

        int node = nodes[u].suffix;
        while(node != root && nodes[node].nxt[i] == -1) 
          node = nodes[node].suffix;

        if(nodes[node].nxt[i] != -1 && nodes[node].nxt[i] != v) nodes[v].suffix = nodes[node].nxt[i];
        else nodes[v].suffix = root;

        if(nodes[nodes[v].suffix].id != -1) nodes[v].dict = nodes[v].suffix;
        else nodes[v].dict = nodes[nodes[v].suffix].dict;

        q.push(v);
      }
    }
  }

  void search(string t, vector<int> & ans){
    int node = root;
    for(char c : t){
      while(node != root && nodes[node].nxt[c - 'a'] == -1) node = nodes[node].suffix;
      if(nodes[node].nxt[c - 'a'] != -1) node = nodes[node].nxt[c - 'a'];

      int cur = (nodes[node].id != -1) ? node : nodes[node].dict;
      while(cur != -1){
        ans[nodes[cur].id]++;
        cur = nodes[cur].dict;
      }
    }
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  int k; cin >> k;
  Trie trie;
  map<string, int> seen;
  vector<int> remap(k);

  for(int i = 0; i < k; i++){
    string p; cin >> p;
    if(seen.count(p)){
      remap[i] = seen[p];
    } else{
      seen[p] = i;
      remap[i] = i;
      trie.insert(p, seen[p]);
    }
  }

  trie.bfs();
  vector<int> ans(k);
  trie.search(s, ans);
  
  for(int & x : remap) cout << ans[x] << '\n';

  return 0;
}
