#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  ll totalSum = n * (n + 1ll) / 2;

  if(totalSum & 1){
    cout << "NO" << '\n';
  } else{
    cout << "YES" << '\n';

    vector<bool> used(n + 1);
    vector<int> setA, setB;
    ll sumA = 0, targetSum = totalSum / 2;
    for(int x = n; x > 0; x--){
      if(x + sumA <= targetSum){
        sumA += x;
        setA.push_back(x);
        used[x] = true;
      }
    }

    for(int x = n; x > 0; x--){
      if(!used[x]){
        setB.push_back(x);
      }
    }

    cout << setA.size() << '\n';
    for(int x : setA) cout << x << ' ';
    cout << '\n';

    cout << setB.size() << '\n';
    for(int x : setB) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}