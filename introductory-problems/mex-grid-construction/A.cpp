#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<vector<int>> grid(n, vector<int>(n));

  /*
    0  1  2  3  4  5  6  7  8  9  10 11
    1  0  3  2  5  4  7  6  9  8  11 10
    2  3  0  1  6  7  4  5  10 11 8  9
    3  2  1  0  7  6  5  4  11 10 9  8
    4  5  6  7  0  1  2  3  12 13 14 15
    5  4  7  6  1  0  3  2  13 12 15 14
    6  7  4  5  2  3  0  1  14 15 13 12
    7  6  5  4  3  2  1  0  
    8  9  10 11 12 13 14 
    9  8  11 10 13 12 15 
    10 11 8  9  14 15 13 
    11 10 9  8  15 14 12 
  */

  return 0;
}