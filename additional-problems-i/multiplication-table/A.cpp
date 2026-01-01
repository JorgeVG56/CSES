#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  ll n; cin >> n;

  auto f = [&](ll mi) -> bool {
    ll ret = 0;
    for(int i = 1; i <= n; i++) ret += min(n, mi / i);
    return ret >= (n * n + 1) / 2;
  };

  ll lo = 1, hi = n * n;
  while(lo < hi){
    ll mi = (lo + hi) >> 1;

    if(f(mi)){
      hi = mi - 1;
    } else{
      lo = mi + 1;
    }
  }

  cout << lo + !(f(lo)) << '\n';

  return 0;
}