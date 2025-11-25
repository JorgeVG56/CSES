#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<int> a(n); for(int & x : a) cin >> x;
  vector<int> b((int)1e6 + 5); for(int & x : a) b[x]++;

  int ans = 0;
  for(int i = (int)1e6 + 5; i > 0; i--){
    int cnt = 0;
    for(int j = i; j < (int)1e6 + 5; j += i) cnt += b[j];
    if(cnt > 1){
      ans = i;
      break;
    }
  }

  cout << ans << '\n';
  
  return 0;
}
