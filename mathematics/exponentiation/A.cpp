#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = (int)1e9 + 7;

ll binPow(ll a, ll b){
  ll r = 1;

  while(b){
    if(b & 1) r = (r * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }

  return r;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n; 

  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;

    cout << binPow(a, b) << '\n';
  }
  
  return 0;
}
