#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx [] = {-1, 0, 1, 0};
const int dy [] = {0, 1, 0, -1};

signed main(){
  cin.tie(0)->sync_with_stdio(0);

  int n, m; cin >> n >> m;

  vector<string> grid(n);

  for(int i = 0; i < n; i++) 
    cin >> grid[i];

  vector<vector<int>> visited(n, vector<int>(m));
  int rooms = 0;
  auto bfs = [&] (int x, int y) -> void {
    queue<pair<int, int>> q; q.push({x, y}); visited[x][y] = rooms;
    while(!q.empty()){
      auto [x, y] = q.front(); q.pop();
      for(int i = 0; i < 4; i++){
        int newX = x + dx[i], newY = y + dy[i];
        if(newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newX][newY] == '#' || visited[newX][newY]) 
          continue;
        q.push({newX, newY}); visited[newX][newY] = rooms;
      }
    }
  };

  for(int i = 0; i < n; i++) 
    for(int j = 0; j < m; j++) 
      if(grid[i][j] == '.' && !visited[i][j]) 
        ++rooms, bfs(i, j);

  cout << rooms << '\n';

  return 0;
}