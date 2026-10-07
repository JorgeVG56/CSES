#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  vector<int> a(n); for(int & x : a) cin >> x;
  
  vector<int> head;
  for(int & x : a) {
    auto it = upper_bound(begin(head), end(head), x);
    if(it == end(head)) head.push_back(x);
    else *it = x;
  }

  cout << head.size() << '\n';

  return 0;
}