#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double binPow(double a, int b){
  double ret = 1.0;
  while(b){
    if(b & 1) ret = ret * a;
    a = a * a;
    b >>= 1;
  }
  return ret;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  double n, k; cin >> n >> k;
  
  double ans = 0;
  for(double i = 1; i <= k; i++)
    ans += i * (binPow(i / k, n) - binPow((i - 1) / k, n));

  cout << fixed << setprecision(6) << ans << '\n';

  return 0;
}