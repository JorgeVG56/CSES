#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int OFFSET = 1e6;

struct Event {
  int type, x, l, r;

  bool operator<(Event e) { return x < e.x || (x == e.x && type < e.type); }
};

struct SegmentTree {
  struct Item {
    ll x;
    Item(ll x = 0) : x(x) { }
    Item operator+(Item item) { 
      return Item(x + item.x); 
    }
  };

  #define lp (u << 1) + 1
  #define rp (u << 1) + 2
  
  int n;
  vector<Item>st;

  SegmentTree(int n) : n(n), st(n << 2) { }

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

  void update(int idx, ll x) { 
    update(0, 0, n - 1, idx, x); 
  }

  Item query(int l, int r) { 
    return query(0, 0, n - 1, l, r); 
  };
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<Event> events;
  for(int i = 0; i < n; i++) {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == x2) {
      events.push_back({1, x1, y1, y2});
    } else {
      events.push_back({0, x1, y1, y2});
      events.push_back({2, x2, y1, y2});
    }
  }

  sort(begin(events), end(events));
  SegmentTree st(OFFSET * 2);

  ll ans = 0;
  for(Event & e : events) {
    if(e.type == 0) st.update(e.l + OFFSET, 1);
    else if(e.type == 2) st.update(e.l + OFFSET, 0);
    else ans += st.query(e.l + OFFSET, e.r + OFFSET).x;
  }

  cout << ans << '\n';
  
  return 0;
}