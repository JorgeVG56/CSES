#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  ll n; cin >> n; cout << n;

  while(n != 1){
    if(n & 1){
      n = n * 3 + 1;
    } else{
      n >>= 1;
    }

    cout << ' ' << n;
  }

  return 0;
}