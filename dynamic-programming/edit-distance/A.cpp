#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int memo[5005][5005];
string s1, s2;

int cost(int a, int b){
  if(s1[a - 1] == s2[b - 1]) return 0;
  else return 1;
}

int dp(int a, int b){
  if(a == 0) return b;
  if(b == 0) return a;
  if(memo[a][b] != -1) return memo[a][b];

  int insert = 1 + dp(a, b - 1);
  int del = 1 + dp(a - 1, b);
  int match = cost(a, b) + dp(a - 1, b - 1);

  memo[a][b] = min({insert, del, match});

  return memo[a][b];
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  memset(memo, -1, sizeof(memo));

  cin >> s1 >> s2;

  int n = (int) s1.size(), m = (int) s2.size();

  cout << dp(n, m) << '\n';

  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= m; j++){
      cout << memo[i][j] << ' ';
    }
    
    cout << '\n';
  }

  return 0;
}