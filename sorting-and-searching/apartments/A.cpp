#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n, m, k; cin >> n >> m >> k;

  vector<ll> applicants(n); for(ll & applicant : applicants) cin >> applicant;
  vector<ll> apartments(m); for(ll & apartment : apartments) cin >> apartment;

  sort(begin(applicants), end(applicants));
  sort(begin(apartments), end(apartments));

  int i = 0, j = 0, ans = 0;

  while(i < n && j < m){
    if(abs(applicants[i] - apartments[j]) <= k) ans++, i++, j++;
    else if(apartments[j] > applicants[i]) i++;
    else j++;
  }

  cout << ans << '\n';

  return 0;
}