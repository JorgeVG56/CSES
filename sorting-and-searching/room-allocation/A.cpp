#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
signed main(){
  cin.tie(0)->sync_with_stdio(0);
 
  int n; cin >> n;
 
  vector<pair<pair<int, int>, int>> customers(n); 
  for(int i = 0; i < n; i++){
    int arrival, departure; cin >> arrival >> departure;
    customers[i] = {{arrival, departure}, i};
  }
 
  sort(begin(customers), end(customers));
 
  int lastRoom = 0;
  vector<int> rooms(n);
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++){
    if(pq.empty() || customers[i].first.first <= -pq.top().first){
      pq.push({-customers[i].first.second, ++lastRoom});
      rooms[customers[i].second] = lastRoom;
    } else{
      auto [departure, room] = pq.top(); pq.pop(); 
      pq.push({-customers[i].first.second, room});
      rooms[customers[i].second] = room;
    }
  }
 
  cout << lastRoom << '\n';
  for(int x : rooms) cout << x << ' ';
  cout << '\n';
 
  return 0;
}