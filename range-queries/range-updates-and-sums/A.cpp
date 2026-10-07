#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct LazySegmentTree {
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<ll> st, lazyAdd, lazySet;

  LazySegmentTree(int n) : n(n), st(n << 2), lazyAdd(n << 2), lazySet(n << 2) { }

  void applyAdd(int u, ll l, ll x) {
    st[u] += l * x;
    if(lazySet[u] == 0) lazyAdd[u] += x;
    else lazySet[u] += x;
  }

  void applySet(int u, ll l, ll x) {
    if(x == 0) return;
    st[u] = l * x;
    lazySet[u] = x;
    lazyAdd[u] = 0;
  }

  void push(int u, int tl, int tr) {
    int tm = (tl + tr) >> 1;
    applyAdd(lp, tm - tl + 1, lazyAdd[u]);
    applyAdd(rp, tr - tm, lazyAdd[u]);
    applySet(lp, tm - tl + 1, lazySet[u]);
    applySet(rp, tr - tm, lazySet[u]);
    lazyAdd[u] = lazySet[u] = 0;
  }

  void build(int u, int tl, int tr, vector<ll> & a) {
    if(tl == tr) {
      st[u] = a[tl];
      return;
    }
    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  ll query(int u, int tl, int tr, int l, int r) {
    if(r < l) return 0;
    if(tl == l && tr == r) return st[u];
    push(u, tl, tr);
    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void updateAdd(int u, int tl, int tr, int l, int r, ll x) {
    if(r < l) return;
    if(tl == l && tr == r) {
      applyAdd(u, tr - tl + 1, x);
      return;
    }
    push(u, tl, tr);
    int tm = (tl + tr) >> 1;
    updateAdd(lp, tl, tm, l, min(tm, r), x);
    updateAdd(rp, tm + 1, tr, max(l, tm + 1), r, x);
    st[u] = st[lp] + st[rp];
  }

  void updateSet(int u, int tl, int tr, int l, int r, ll x) {
    if(r < l) return;
    if(tl == l && tr == r) {
      applySet(u, tr - tl + 1, x);
      return;
    }
    push(u, tl, tr);
    int tm = (tl + tr) >> 1;
    updateSet(lp, tl, tm, l, min(tm, r), x);
    updateSet(rp, tm + 1, tr, max(l, tm + 1), r, x);
    st[u] = st[lp] + st[rp];
  }

  void build(vector<ll> & a) {
    build(0, 0, n - 1, a);
  }

  ll query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }

  void updateAdd(int l, int r, ll x) {
    updateAdd(0, 0, n - 1, l, r, x);
  }

  void updateSet(int l, int r, ll x) {
    updateSet(0, 0, n - 1, l, r, x);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;
  vector<ll> a(n); for(ll & x : a) cin >> x;

  LazySegmentTree st(n); st.build(a);

  for(int i = 0; i < q; i++) {
    int type; cin >> type;
    if(type == 1) {
      int a, b; cin >> a >> b; --a, --b;
      ll x; cin >> x;
      st.updateAdd(a, b, x);
    } else if(type == 2) {
      int a, b; cin >> a >> b; --a, --b;
      ll x; cin >> x;
      st.updateSet(a, b, x);
    } else {
      int a, b; cin >> a >> b; --a, --b;
      cout << st.query(a, b) << '\n';
    }
  }
  
  return 0;
}