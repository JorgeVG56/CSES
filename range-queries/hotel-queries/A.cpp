#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  int mx;

  Item () : mx(-1) { }
  Item (int n) : mx(n) { }

  Item operator+(Item item){
    Item result = max(mx, item.mx);

    return result;
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

  int query(int u, int tl, int tr, int x){
    if(tl == tr) return st[u].mx >= x ? tl : -1;

    int tm = (tl + tr) >> 1;
    if(st[lp].mx >= x) return query(lp, tl, tm, x);
    else if(st[rp].mx >= x) return query(rp, tm + 1, tr, x);

    return -1;
  }

  void build(vector<int> & a){
    build(0, 0, n - 1, a);
  }

  void update(int idx, int x){
    update(0, 0, n - 1, idx, x);
  }

  int query(int x){
    return query(0, 0, n - 1, x);
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> a(n); for(auto & h : a) cin >> h;

  SegmentTree st(n); st.build(a);

  for(int i = 0; i < m; i++){
    int r; cin >> r;
    
    int result = st.query(r);

    cout << result + 1 << ' ';

    if(result >= 0){
      a[result] -= r;
      st.update(result, a[result]);
    }
  }

  return 0;
}