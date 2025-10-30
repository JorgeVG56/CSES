#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct PersistentSegTree{
  struct Node{
    ll sum;
    int l = 0, r = 0;
  };

  int timer = 1, n;
  vector<Node> nodes;

  PersistentSegTree(int n, int mxNodes) : n(n), nodes(mxNodes) {}

  Node join(int l, int r){ return Node{nodes[l].sum + nodes[r].sum, l, r}; }

  int build(int tl, int tr, vector<int> & a){
    if(tl == tr){
      nodes[timer] = {a[tl], 0, 0};
      return timer++;
    }

    int tm = (tl + tr) >> 1;
    nodes[timer] = join(build(tl, tm, a), build(tm + 1, tr, a));

    return timer++;
  }

  int update(int u, int tl, int tr, int idx, int x){
    if(tl == tr){
      nodes[timer] = {x, 0, 0};
      return timer++;
    }

    int tm = (tl + tr) >> 1;
    if(idx <= tm) nodes[timer] = join(update(nodes[u].l, tl, tm, idx, x), nodes[u].r);
    else nodes[timer] = join(nodes[u].l, update(nodes[u].r, tm + 1, tr, idx, x));
    
    return timer++;
  }

  ll query(int u, int tl, int tr, int l, int r){
    if(l > r) return 0;
    if(tl == l && tr == r){
      return nodes[u].sum;
    }

    int tm = (tl + tr) >> 1;
    return  query(nodes[u].l, tl, tm, l, min(tm, r)) + query(nodes[u].r, tm + 1, tr, max(l, tm + 1), r);
  }

  int build(vector<int> & a){ return build(0, n - 1, a); }

  int update(int root, int idx, int x){ return update(root, 0, n - 1, idx, x); }

  ll query(int root, int l, int r){ return query(root, 0, n - 1, l, r); }

  int copy(int root){ nodes[timer] = nodes[root]; return timer++; }
};


signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(auto & x : a) cin >> x;

  int mxNodes = (int)(4 * n +  q * (4 + log2(n)));

  PersistentSegTree st(n, mxNodes);
  vector<int> roots; roots.push_back(st.build(a));
  for(int i = 0; i < q; i++){
    int t; cin >> t;

    if(t == 1){
      int k, a, x; cin >> k >> a >> x;
      roots[k - 1] = st.update(roots[k - 1], a - 1, x);
    } else if(t == 2){
      int k, a, b; cin >> k >> a >> b;
      cout << st.query(roots[k - 1], a - 1, b - 1) << '\n';
    } else{
      int k; cin >> k;
      roots.push_back(st.copy(roots[k - 1]));
    }
  }

  return 0;
}
