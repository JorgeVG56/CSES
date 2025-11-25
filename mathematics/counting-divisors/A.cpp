#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int divisors(int x){
  int numDivisors = 1;

  for(int i = 2; i * i <= x; i++){
    if(x % i == 0){
      int cnt = 1;
      while(x % i == 0){
        x /= i;
        cnt++;
      }
      numDivisors *= cnt;
    }
  }

  if(x > 1) numDivisors *= 2;

  return numDivisors;
}

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n; 

  for(int i = 0; i < n; i++){
    int x; cin >> x;

    cout << divisors(x) << '\n';
  }

  return 0;
}