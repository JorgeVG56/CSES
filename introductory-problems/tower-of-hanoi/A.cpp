#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;
  
  cout << (1 << n) - 1 << '\n';

  int lastGray = 0;
  for(int i = 1; i < (1 << n); i++){
    int currentGray = i ^ (i >> 1);
    int moving = -1;
    for(int bit = n - 1; bit >= 0; bit--)
      if(((currentGray ^ lastGray) >> bit) & 1) 
        moving = bit;
    cout << moving << '\n';
    lastGray = currentGray;
  }

  return 0;
}