#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, x; cin >> n >> x;

  vector<int> prices(n); for(int & price : prices) cin >> price;
  vector<int> pages(n); for(int & page : pages) cin >> page;

  vector<int> dp(x + 1);

  for(int bookIndex = 0; bookIndex < n; bookIndex++) {
    for(int budget = x; budget >= 0; budget--){
      if(budget >= prices[bookIndex]) 
        dp[budget] = max(dp[budget], dp[budget - prices[bookIndex]] + pages[bookIndex]);
    }
  }

  cout << dp[x] << '\n';

  return 0;
}