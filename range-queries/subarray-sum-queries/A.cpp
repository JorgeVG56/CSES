#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Item{
  ll totalSum, maxSum, maxPreffix, maxSuffix;

  Item (ll n) : totalSum(n), maxSum(max(n, 0ll)), maxPreffix(max(n, 0ll)), maxSuffix(max(n, 0ll)) { }

  Item operator+(Item item){
    Item result(0);

    result.totalSum = totalSum + item.totalSum;
    result.maxSum = max({maxSum, item.maxSum, maxSuffix + item.maxPreffix});
    result.maxPreffix = max(maxPreffix, totalSum + item.maxPreffix);
    result.maxSuffix = max(item.maxSuffix, maxSuffix + item.totalSum);

    return result;
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

int main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<int> a(n); for(auto & x : a) cin >> x;

  SegmentTree st(n); st.build(a);

  for(int i = 0; i < m; i++){
    int idx, x; cin >> idx >> x; idx--;

    st.update(idx, x);

    Item result = st.query(0, n - 1);

    cout << result.maxSum << '\n';
  }

  return 0;
}