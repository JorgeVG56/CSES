#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n; cin >> n;

  vector<pair<ll, ll>> tasks(n); for(auto & [duration, deadline] : tasks) cin >> duration >> deadline;

  sort(begin(tasks), end(tasks));

  ll answer = 0, currentTime = 0;
  for(int i = 0; i < n; i++)
    answer += tasks[i].second - (tasks[i].first + currentTime), currentTime += tasks[i].first;

  cout << answer << '\n';

  return 0;
}