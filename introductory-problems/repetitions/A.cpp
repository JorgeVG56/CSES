#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;

  int ans = 1, curAns = 1;

  for(int i = 1; i < (int)s.length(); i++){
    if(s[i] == s[i - 1]) ans = max(ans, ++curAns);
    else curAns = 1;
  }

  cout << ans;

  return 0;
}