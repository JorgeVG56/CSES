#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  int maxOnSegment, preffixOnes, preffixZeroes, suffixOnes, suffixZeroes, allOnes, allZeroes;

  Item (int n) : maxOnSegment(1), preffixOnes(n == 1), preffixZeroes(n == 0), suffixOnes(n == 1), suffixZeroes(n == 0), allOnes(n == 1), allZeroes(n == 0) { }

  Item operator+(Item item){
    Item c(0);

    c.preffixOnes = (allOnes ? preffixOnes + item.preffixOnes : preffixOnes);
    c.preffixZeroes = (allZeroes ? preffixZeroes + item.preffixZeroes : preffixZeroes);
    c.suffixOnes = (item.allOnes ? suffixOnes + item.suffixOnes : item.suffixOnes);
    c.suffixZeroes = (item.allZeroes ? suffixZeroes + item.suffixZeroes : item.suffixZeroes);
    c.allOnes = (allOnes & item.allOnes);
    c.allZeroes = (allZeroes & item.allZeroes);
    c.maxOnSegment = max({maxOnSegment, item.maxOnSegment, c.preffixOnes, c.preffixZeroes, c.suffixOnes, c.suffixZeroes, suffixOnes + item.preffixOnes, suffixZeroes + item.preffixZeroes});

    return c;
  }
};

struct SegmentTree{
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2, 0) { }

  void build(int u, int tl, int tr, vector<int> & a){
    if(tl == tr){
      st[u] = a[tl];
      return ;
    }

    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int idx, int x){
    if(tl == tr){
      st[u] = x;
      return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r){
    if(r < l) return 0;
    if(tl == l && tr == r) return st[u];

    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }


  void build(vector<int> & a){
    build(0, 0, n - 1, a);
  }

  void update(int idx, int x){
    update(0, 0, n - 1, idx, x);
  }

  Item query(int l, int r){
    return query(0, 0, n - 1, l, r);
  }
};

using namespace std;
int main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  int n = (int)size(s);
  vector<int> a(n); for(int i = 0; i < n; i++) a[i] = s[i] - '0';

  SegmentTree st(n); st.build(a);

  int m; cin >> m;

  for(int i = 0; i < m; i++){
    int x; cin >> x; --x;

    a[x] ^= 1;
    st.update(x, a[x]);

    Item result = st.query(0, n - 1);
    cout << result.maxOnSegment << ' ';
  }

  cout << '\n';

  return 0;
}