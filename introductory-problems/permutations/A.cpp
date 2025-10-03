#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  if(n == 1){
    cout << 1;
  } else if(n == 2 || n == 3){
    cout << "NO SOLUTION";
  } else if(n & 1){
    vector<int> a(n);

    for(int i = 0; i < n; i++){
      a[(i << 1) % n] = i + 1;
    }

    for(int x : a) cout << x << ' ';
  } else{
    vector<int> a(n);

    for(int i = 0; i < n; i++){
      a[((i << 1) + ((n >> 1) > i)) % n] = i + 1;
    }

    for(int x : a) cout << x << ' ';
  }

  return 0;
}