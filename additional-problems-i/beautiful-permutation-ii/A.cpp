#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  set<int> st; for(int i = 1; i <= n; i++) st.insert(i);

  vector<int> a;

  auto bt = [&](auto & self) -> void{
    if((int)size(a) == n){
      for(int & x : a) cout << x << ' ';
      cout << '\n';
      exit(0);
    }

    for(int x : st){
      if(!a.empty() && abs(a.back() - x) <= 1) continue;
      a.push_back(x);
      st.erase(x);
      self(self);
      st.insert(x);
      a.pop_back();
    }
  };

  bt(bt); cout << "NO SOLUTION" << '\n';
  
  return 0;
}
