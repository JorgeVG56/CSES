#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SuffixAutomaton {
  struct State {
    int len = 0, link = -1, nxt[26];
    ll dp = -1;
    State() { 
      fill(nxt, nxt + 26, -1); 
    }
  };
  
  vector<State> st;
  int sz = 1, last = 0;
  
  SuffixAutomaton(string s) {
    st.resize(2 * s.length() + 5);
    for (char c : s) extend(c);
  }
  
  void extend(char c) {
    int x = c - 'a', cur = sz++, p = last;
    st[cur].len = st[last].len + 1;
    
    while (p != -1 && st[p].nxt[x] == -1) st[p].nxt[x] = cur, p = st[p].link;
    
    if (p == -1) st[cur].link = 0;
    else {
      int q = st[p].nxt[x];
      if (st[p].len + 1 == st[q].len) st[cur].link = q;
      else {
        int clone = sz++;
        st[clone] = st[q];
        st[clone].len = st[p].len + 1;
        while (p != -1 && st[p].nxt[x] == q)
        st[p].nxt[x] = clone, p = st[p].link;
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  
  ll dfs(int u) {
    if (st[u].dp != -1) return st[u].dp;
    st[u].dp = 1;
    for (int c = 0; c < 26; c++)
      if (st[u].nxt[c] != -1)
        st[u].dp += dfs(st[u].nxt[c]);
    return st[u].dp;
  }
  
  string kth(ll k) {
    dfs(0);
    if(k > st[0].dp - 1) return ".";
    string ans;
    int u = 0;
    
    while (1) {
      for (int c = 0; c < 26; c++) {
        int v = st[u].nxt[c];
        if (v == -1) continue;
        
        if (k > st[v].dp) k -= st[v].dp;
        else {
          ans += 'a' + c;
          u = v;
          if (--k == 0) return ans;
          break;
        }
      }
    }
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  ll k; cin >> k;
  
  SuffixAutomaton sa(s);

  cout << sa.kth(k) << '\n';

  return 0;
}