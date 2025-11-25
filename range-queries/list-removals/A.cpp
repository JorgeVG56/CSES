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
    if(tl == tr) return tl;

    int tm = (tl + tr) >> 1;
    if(st[lp].sum >= x) return query(lp, tl, tm, x);
    else return query(rp, tm + 1, tr, x - st[lp].sum);
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

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;
  SegmentTree st(n); vector<int> b(n, 1); st.build(b);

  for(int i = 0; i < n; i++){
    int p; cin >> p;

    int result = st.query(p);

    st.update(result, 0);

    cout << a[result] << ' ';
  }

  cout << '\n';
  
  return 0;
}
