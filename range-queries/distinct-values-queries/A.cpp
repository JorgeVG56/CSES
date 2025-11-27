#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  int sum;

  Item() : sum(0) { }
  Item (int n) : sum(n) { }

  Item operator+(Item item){
    return Item(sum + item.sum);
  }
};

struct SegmentTree{
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<int> & a){
    if(tl == tr){
      st[u] = a[tl];
      return;
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
    if(r < l) return Item();
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

struct Query{
  int l, r, idx;

  bool operator<(Query & query){
    return l < query.l;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<int> b(n, 0);
  SegmentTree st(n); st.build(b);

  vector<Query> c(q); 
  for(int i = 0;  i < q; i++){
    cin >> c[i].l >> c[i].r; c[i].l--, c[i].r--;
    c[i].idx = i;
  }
  sort(rbegin(c), rend(c));

  map<int, int> mp;
  int idx = n;
  vector<int> d(q);
  for(int i = 0; i < q; i++){
    while(c[i].l < idx){
      idx--;
      st.update(idx, 1);
      if(mp.count(a[idx])) st.update(mp[a[idx]], 0);
      mp[a[idx]] = idx;
    }

    Item result = st.query(c[i].l, c[i].r);
    d[c[i].idx] = result.sum;
  }

  for(int & x : d) cout << x << '\n';
  
  return 0;
}
