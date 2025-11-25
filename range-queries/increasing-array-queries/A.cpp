#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Query{
  ll l, r, idx;

  bool operator<(Query & q){
    return q.l < l;
  }
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;
  
  vector<int> a(n); for(int & x : a) cin >> x; 
  vector<Query> b(q); for(int i = 0; i < q; i++){ cin >> b[i].l >> b[i].r; b[i].idx = i; }
  
  sort(begin(b), end(b));

  stack<pair<ll, pair<ll, ll>>> st;

  vector<ll> c(q);

  int idx = n;
  for(int i = 0; i < q; i++){ 
    while(b[i].l < idx){
      idx--;
      int jdx = n - 1;
      while(!st.empty() && st.top().first >= a[i]){
        auto [x, range] = st.top(); st.pop();
        auto [l, r] = range;
        // st.upd(l, r, a[i] - x)
        jdx = r;
      }
      st.push({a[idx], {idx, jdx}});
    }

    // c[b[i].idx] = st.query(b[i].l, b[i].r);
  }
  
  return 0;
}
