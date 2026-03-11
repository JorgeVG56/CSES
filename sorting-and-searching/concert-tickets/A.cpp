#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
 
  int n, m; cin >> n >> m;
 
  vector<ll> prices(n); for(ll & price : prices) cin >> price;
  vector<ll> customers(m); for(ll & customer : customers) cin >> customer;
 
  multiset<ll> ms(begin(prices), end(prices));
  for(ll customer : customers){
    auto it = ms.upper_bound(customer);
    if(it == begin(ms)) cout << -1 << '\n';
    else { cout << *(--it) << '\n'; ms.erase(it); }
  }
 
  return 0;
}