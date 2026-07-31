#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, x; cin >> n >> x;

  vector<int> prices(n); for(int & price : prices) cin >> price;
  vector<int> pages(n); for(int & page : pages) cin >> page;
  vector<int> copies(n); for(int & copy : copies) cin >> copy;

  vector<int> dp(x + 1);
  for(int bookIndex = 0; bookIndex < n; bookIndex++){
    int accumulated = 0;
    for(int copy = 1; accumulated + copy <= copies[bookIndex]; copy <<= 1){
      accumulated += copy;
      for(int budget = x; budget >= 0; budget--){
        if(budget >= prices[bookIndex] * copy)
          dp[budget] = max(dp[budget], dp[budget - prices[bookIndex] * copy] + pages[bookIndex] * copy);
      }
    }
    int rest = copies[bookIndex] - accumulated;
    for(int budget = x; budget >= 0; budget--){
      if(budget >= prices[bookIndex] * rest)
        dp[budget] = max(dp[budget], dp[budget - prices[bookIndex] * rest] + pages[bookIndex] * rest);
    }
  }

  cout << dp[x] << '\n';

  return 0;
}