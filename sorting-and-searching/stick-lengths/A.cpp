#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<ll> a(n); for(ll & x : a) cin >> x;

  sort(begin(a), end(a));

  vector<ll> preffix(n + 1); for(int i = 0; i < n; i++) preffix[i + 1] = preffix[i] + a[i];
  vector<ll> suffix(n + 1); for(int i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + a[i];
  
  set<ll> st(begin(a), end(a)); 
  ll ans = (ll)1e18;
  
  for(auto x : st){
    ll posL = lower_bound(begin(a), end(a), x) - begin(a);
    ll posR = upper_bound(begin(a), end(a), x) - begin(a);
    
    ll curAns = posL * x - preffix[posL] + suffix[posR] - (n - posR) * x;
    ans = min(ans, curAns);
  }

  cout << ans << '\n';

  return 0;
}