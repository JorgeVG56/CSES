#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  string p; cin >> p;
  
  string sp = p + '#' + s;

  int n = (int)sp.size();
  vector<int> kmp(n);
  for(int i = 1, j = 0; i < n; i++){
    while(j > 0 && sp[j] != sp[i]) j = kmp[j - 1];
    if(sp[i] == sp[j]) j++;
    kmp[i] = j;
  }

  int k = (int)p.size(); 

  // for(int i = 0; i < n; i++) cout << kmp[i] << ' ';

  int ans = 0;
  for(int i = k * 2 - 1; i < n; i++){
    if(kmp[i] >= k) ans++;
  }

  cout << ans << '\n';

  return 0;
}
