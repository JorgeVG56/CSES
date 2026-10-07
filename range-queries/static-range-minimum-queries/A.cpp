#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct Querie {
  int l, r, ans;
};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, q; cin >> n >> q;

  vector<int> a(n); for(int & x : a) cin >> x;

  vector<Querie> queries(q);
  for(int i = 0; i < q; i++) {
    int l, r; cin >> l >> r; --l, --r;
    queries[i] = {l, r, -1};
  }

  vector<int> idx(q); iota(begin(idx), end(idx), 0);
  vector<int> left(n), right(n);

  auto calc = [&](auto & self, int l, int r, vector<int> idx) -> void {
    if(idx.empty()) return;
    int m = (l + r) >> 1;
    left[m] = a[m];
    for(int i = m - 1; i >= l; i--) left[i] = min(a[i], left[i + 1]);
    right[m] = a[m];
    for(int i = m + 1; i <= r; i++) right[i] = min(a[i], right[i - 1]);
    vector<int> idxN[2];
    for(int i : idx) {
      if(queries[i].l <= m && m <= queries[i].r) queries[i].ans = min(left[queries[i].l], right[queries[i].r]);
      else idxN[queries[i].l > m].push_back(i);
    }
    self(self, l, m - 1, idxN[0]); self(self, m + 1, r, idxN[1]);
  }; calc(calc, 0, n - 1, idx);

  for(auto & q : queries) cout << q.ans << '\n';
  
  return 0;
}