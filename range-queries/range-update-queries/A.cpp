#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  ll sum;

  Item () : sum(0) { }
  Item (ll n) : sum(n) { }

  Item operator+(Item item){
    return Item(sum + item.sum);
  }

  void operator+=(ll x){
    sum += x;
  }
};

struct LazySegmentTree{
  #define lp (u << 1) + 1
  #define rp (u << 1) + 2

  int n;
  vector<Item> st;
  vector<ll> lz;

  LazySegmentTree(int n) : n(n), st(n << 2), lz(n << 2) { }
  
  void apply(int u, int len, ll x){
    st[u] += x * len;
    lz[u] += x;
  }

  void push(int u, int tl, int tr){
    int tm = (tl + tr) >> 1;
    apply(lp, tm - tl + 1, lz[u]);
    apply(rp, tr - tm, lz[u]);
    lz[u] = 0;
  }

  void build(int u, int tl, int tr, vector<ll> & a){
    if(tl == tr){
      st[u] = a[tl];
      return ;
    }

    int tm = (tl + tr) >> 1;
    build(lp, tl, tm, a); build(rp, tm + 1, tr, a);
    st[u] = st[lp] + st[rp];
  }

  void update(int u, int tl, int tr, int l, int r, int x){
    if(r < l) return;
    if(tl == l && tr == r){
      apply(u, tr - tl + 1, x);
      return;
    }

    push(u, tl, tr);
    int tm = (tl + tr) >> 1;
    update(lp, tl, tm, l, min(tm, r), x);
    update(rp, tm + 1, tr, max(l, tm + 1), r, x);
    st[u] = st[lp] + st[rp];
  }

  Item query(int u, int tl, int tr, int l, int r){
    if(r < l) return Item();
    if(tl == l && tr == r) return st[u];
    
    push(u, tl, tr);
    int tm = (tl + tr) >> 1;
    return query(lp, tl, tm, l, min(tm, r)) + query(rp, tm + 1, tr, max(l, tm + 1), r);
  }

  void build(vector<ll> & a){
    build(0, 0, n - 1, a);
  }

  void update(int l, int r, int x){
    update(0, 0, n - 1, l, r, x);
  }

  Item query(int l, int r){
    return query(0, 0, n - 1, l, r);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<ll> a(n); for(auto & x : a) cin >> x;

  LazySegmentTree st(n); st.build(a);

  for(int i = 0; i < q; i++){
    int type; cin >> type;

    if(type == 1){
      int a, b, x; cin >> a >> b >> x; --a, --b;
      st.update(a, b, x);
    } else if(type == 2){
      int k; cin >> k; --k;
      Item result = st.query(k, k);
      cout << result.sum << '\n';
    }
  }
  
  return 0;
}
