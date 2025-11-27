#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  vector<string> a(8); for(string & s : a) cin >> s;

  vector<int> b(8); iota(begin(b),  end(b), 0);

  int ans = 0;
  do{
    bool fl = false;
    for(int i = 0; i < 8; i++) fl |= a[i][b[i]] == '*';
    if(fl) continue;

    set<int> st;
    for(int i = 0; i < 8; i++) fl |= !st.insert(i - b[i]).second;
    if(fl) continue;

    st.clear();
    for(int i = 0; i < 8; i++) fl |= !st.insert(i + b[i]).second;
    if(fl) continue;
    ans++;
  } while(next_permutation(begin(b), end(b)));

  cout << ans << '\n';
  
  return 0;
}
