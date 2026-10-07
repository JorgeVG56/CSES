#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct LazySegmentTree {
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  bool fl;
  int n;
  vector<ll> st, lazy;

  LazySegmentTree(int n, bool fl) : fl(fl), n(n), st(n << 2), lazy(n << 2) { }

  void apply(ll u, ll tl, ll tr, ll x) {
    if(fl) st[u] += (tl + tr) * (tr - tl + 1) * x / 2;
    else st[u] += (tr - tl + 1) * x;
    lazy[u] += x;
  }

  void push(ll u, ll tl, ll tr) {
    ll tm = (tl + tr) >> 1;
    apply(lp, tl, tm, lazy[u]);
    apply(rp, tm + 1, tr, lazy[u]);
    lazy[u] = 0;
  }

  void build(ll u, ll tl, ll tr, vector<ll> & a) {
    if(tl == tr) {
      st[u] = a[tl];
      return;
    }
    ll tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(ll u, ll tl, ll tr, ll l, ll r, ll x) {
    if(r < l) return;
    if(tl == l && tr == r) {
      apply(u, tl, tr, x);
      return;
    }
    push(u, tl, tr);
    ll tm = (tl + tr) >> 1;
    update(lp, tl, tm, l, min(tm, r), x); update(rp, tm + 1, tr, max(l, tm + 1), r, x);
    st[u] = st[lp] + st[rp];
  }

  ll query(ll u, ll tl, ll tr, ll l, ll r) {
    if(r < l) return 0;
    if(tl == l && tr == r) {
      return st[u];
    }
    push(u, tl, tr);
    ll tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;
  vector<ll> a(n + 1, 0); 
  for(int i = 1; i <= n; i++) cin >> a[i];

  LazySegmentTree stA(n + 1, 1), stB(n + 1, 0);
  vector<ll> b(n + 1, 0);
  stA.build(0, 0, n, a); stB.build(0, 0, n, b);
  
  for(int i = 0; i < q; i++) {
    int type; cin >> type;
    if(type == 1) {
      int l, r; cin >> l >> r;
      stA.update(0, 0, n, l, r, 1);
      stB.update(0, 0, n, l, r, l - 1);
    } else{
      int l, r; cin >> l >> r;
      cout << stA.query(0, 0, n, l, r) - stB.query(0, 0, n, l, r) << '\n';
    }
  }

  return 0;
}