#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegmentTree {
  struct Item {
    ll totalSum, maxPreffix;

    Item (ll x = 0) : totalSum(x), maxPreffix(max(x, 0ll)) { }

    Item operator+(Item item) {
      Item res;
      res.totalSum = totalSum + item.totalSum;
      res.maxPreffix = max({maxPreffix, totalSum + item.maxPreffix});
      return res;
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;

  SegmentTree(int n) : n(n), st(n << 2) { }

  void build(int u, int tl, int tr, vector<ll> & a) {
    if(tl == tr) {
      st[u] = a[tl];
      return;
    }

    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int idx, ll x) {
    if(tl == tr) {
      st[u] = x;
      return;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) update(lp, tl, tm, idx, x);
    else update(rp, tm + 1, tr, idx, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r) {
    if(r < l) return Item();
    if(tl == l && tr == r) return st[u];
    
    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<ll> & a) {
    build(0, 0, n - 1, a);
  }

  void update(int idx, ll x) {
    update(0, 0, n - 1, idx, x);
  }

  Item query(int l, int r) {
    return query(0, 0, n - 1, l, r);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;
  vector<ll> a(n); for(ll & x : a) cin >> x;

  SegmentTree st(n); st.build(a);

  for(int i = 0; i < q; i++) {
    int type; cin >> type;
    if(type == 1) {
      ll k, x; cin >> k >> x; k--;
      st.update(k, x);
    } else {
      int l, r; cin >> l >> r; --l, --r;
      cout << st.query(l, r).maxPreffix << '\n';
    }
  }

  return 0;
}