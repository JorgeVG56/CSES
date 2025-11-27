#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, k; cin >> n >> k;

  vector<int> a(n); for(int & x : a) cin >> x;

  map<int, int> mp; 
  for(int i = 0; i < n; i++){
    if(mp.count(k - a[i])){
      cout << (mp[k - a[i]] + 1) << ' ' << (i + 1) << '\n';
      return 0;
    }
    
    mp[a[i]] = i;
  }

  cout << "IMPOSSIBLE" << '\n';
  
  return 0;
}
