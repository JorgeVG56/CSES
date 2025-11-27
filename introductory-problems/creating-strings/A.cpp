#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  sort(begin(s), end(s));

  vector<string> permutations;
  do{
    permutations.push_back(s);
  } while(next_permutation(begin(s), end(s)));

  cout << (int)size(permutations) << '\n';
  for(string s : permutations) cout << s << '\n';
  
  return 0;
}
