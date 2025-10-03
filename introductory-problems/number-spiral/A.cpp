#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int tc; cin >> tc;

  for(int c = 1; c <= tc; c++){
    int x, y; cin >> x >> y;

    int layer = max(x, y);

    ll end = 1ll * layer * layer;

    if(layer & 1){
      end = end + 1 - x - (layer - y);
    } else{
      end = end + 1 - y - (layer - x);
    }

    cout << end << '\n';
  }

  return 0;
}