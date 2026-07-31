#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  string s; cin >> s;
  
  vector<int> cnt(26); for(char c : s) cnt[c - 'A']++;

  int oddLetters = 0; for(int x : cnt) oddLetters += x & 1;

  if((s.size() & 1) != oddLetters){
    cout << "NO SOLUTION" << '\n';
  } else{
    string half = "";
    for(int i = 0; i < 26; i++)
      while(cnt[i] > 1) 
        half += 'A' + i, cnt[i] -= 2;

    cout << half;
    for(int i = 0; i < 26; i++)
      if(cnt[i])
        cout << char('A' + i);
    reverse(begin(half), end(half));
    cout << half << '\n';
  }

  return 0;
}