#include<bits/stdc++.h>
using namespace std;
using ll = long long;

signed main(){
  cin.tie(0)->sync_with_stdio(0);
  
  int t; cin >> t;
  
  for(int c = 0; c < t; c++){
    int n, m, t = 0; cin >> n >> m;
    
    if((n * m) % 3 != 0 || n == 1 || m == 1){
      cout << "NO\n";
      continue;
    }
    
    if(m % 3 == 0){
      t ^= 1;
      swap(n, m);
    }
    
    if(m % 3 == 0 && m < n){
      t ^= 1;
      swap(n, m);
    }
    
    vector<vector<char>> grid(n, vector<char>(m));
    
    if(n % 3 == 0 && !(m & 1)){
      int j = 0;
      
      for(; j < m - 3; j += 4){
        for(int k = 0; k < n - 2; k += 3){
          grid[k][j] = 'A'; grid[k][j + 1] = 'A'; grid[k][j + 2] = 'C'; grid[k][j + 3] = 'C';
          grid[k + 1][j] = 'A'; grid[k + 1][j + 1] = 'B'; grid[k + 1][j + 2] = 'C'; grid[k + 1][j + 3] = 'D';
          grid[k + 2][j] = 'B'; grid[k + 2][j + 1] = 'B'; grid[k + 2][j + 2] = 'D'; grid[k + 2][j + 3] = 'D';
        }
      }
      
      for(; j < m - 1; j += 2){
        for(int k = 0; k < n - 2; k += 3){
          grid[k][j] = 'A'; grid[k][j + 1] = 'A';
          grid[k + 1][j] = 'A'; grid[k + 1][j + 1] = 'B';
          grid[k + 2][j] = 'B'; grid[k + 2][j + 1] = 'B';
        }
      }
    } else if(n % 6 == 0){
      for(int k = 0; k < n - 5; k += 6){
        grid[k][0] = 'A'; grid[k][1] = 'A'; grid[k][2] = 'B';
        grid[k + 1][0] = 'A'; grid[k + 1][1] = 'B'; grid[k + 1][2] = 'B';
        grid[k + 2][0] = 'C'; grid[k + 2][1] = 'C'; grid[k + 2][2] = 'D';
        grid[k + 3][0] = 'C'; grid[k + 3][1] = 'D'; grid[k + 3][2] = 'D';
        grid[k + 4][0] = 'E'; grid[k + 4][1] = 'E'; grid[k + 4][2] = 'F';
        grid[k + 5][0] = 'E'; grid[k + 5][1] = 'F'; grid[k + 5][2] = 'F';
      }
      
      int j = 3;      
      for(; j < m - 3; j += 4){
        for(int k = 0; k < n - 5; k += 6){
          grid[k][j] = 'G'; grid[k][j + 1] = 'G'; grid[k][j + 2] = 'K'; grid[k][j + 3] = 'K';
          grid[k + 1][j] = 'G'; grid[k + 1][j + 1] = 'H'; grid[k + 1][j + 2] = 'K'; grid[k + 1][j + 3] = 'L';
          grid[k + 2][j] = 'H'; grid[k + 2][j + 1] = 'H'; grid[k + 2][j + 2] = 'L'; grid[k + 2][j + 3] = 'L';
          grid[k + 3][j] = 'I'; grid[k + 3][j + 1] = 'I'; grid[k + 3][j + 2] = 'M'; grid[k + 3][j + 3] = 'M';
          grid[k + 4][j] = 'I'; grid[k + 4][j + 1] = 'J'; grid[k + 4][j + 2] = 'M'; grid[k + 4][j + 3] = 'N';
          grid[k + 5][j] = 'J'; grid[k + 5][j + 1] = 'J'; grid[k + 5][j + 2] = 'N'; grid[k + 5][j + 3] = 'N';
        }
      }

      for(; j < m - 1; j += 2){
        for(int k = 0; k < n - 5; k += 6){
          grid[k][j] = 'G'; grid[k][j + 1] = 'G';
          grid[k + 1][j] = 'G'; grid[k + 1][j + 1] = 'H';
          grid[k + 2][j] = 'H'; grid[k + 2][j + 1] = 'H';
          grid[k + 3][j] = 'I'; grid[k + 3][j + 1] = 'I';
          grid[k + 4][j] = 'I'; grid[k + 4][j + 1] = 'J';
          grid[k + 5][j] = 'J'; grid[k + 5][j + 1] = 'J';
        }
      }
    } else if(n == 3){
      cout << "NO\n";
      continue;
    } else{
      grid[0][0] = 'E'; grid[0][1] = 'E'; grid[0][2] = 'D'; grid[0][3] = 'A'; grid[0][4] = 'A';
      grid[1][0] = 'E'; grid[1][1] = 'D'; grid[1][2] = 'D'; grid[1][3] = 'C'; grid[1][4] = 'A';
      grid[2][0] = 'F'; grid[2][1] = 'F'; grid[2][2] = 'C'; grid[2][3] = 'C'; grid[2][4] = 'B';
      grid[3][0] = 'G'; grid[3][1] = 'F'; grid[3][2] = 'H'; grid[3][3] = 'B'; grid[3][4] = 'B';
      grid[4][0] = 'G'; grid[4][1] = 'G'; grid[4][2] = 'H'; grid[4][3] = 'H'; grid[4][4] = 'I';
      grid[5][0] = 'K'; grid[5][1] = 'J'; grid[5][2] = 'J'; grid[5][3] = 'I'; grid[5][4] = 'I';
      grid[6][0] = 'K'; grid[6][1] = 'K'; grid[6][2] = 'J'; grid[6][3] = 'L'; grid[6][4] = 'L';
      grid[7][0] = 'O'; grid[7][1] = 'N'; grid[7][2] = 'N'; grid[7][3] = 'M'; grid[7][4] = 'L';
      grid[8][0] = 'O'; grid[8][1] = 'O'; grid[8][2] = 'N'; grid[8][3] = 'M'; grid[8][4] = 'M';

      for(int j = 9; j < n - 5; j += 6){
        grid[j][0] = 'P'; grid[j][1] = 'P'; grid[j][2] = 'R'; grid[j][3] = 'R'; grid[j][4] = 'S';
        grid[j + 1][0] = 'P'; grid[j + 1][1] = 'Q'; grid[j + 1][2] = 'R'; grid[j + 1][3] = 'S'; grid[j + 1][4] = 'S';
        grid[j + 2][0] = 'Q'; grid[j + 2][1] = 'Q'; grid[j + 2][2] = 'T'; grid[j + 2][3] = 'T'; grid[j + 2][4] = 'U';
        grid[j + 3][0] = 'V'; grid[j + 3][1] = 'V'; grid[j + 3][2] = 'T'; grid[j + 3][3] = 'U'; grid[j + 3][4] = 'U';
        grid[j + 4][0] = 'V'; grid[j + 4][1] = 'W'; grid[j + 4][2] = 'X'; grid[j + 4][3] = 'X'; grid[j + 4][4] = 'Y';
        grid[j + 5][0] = 'W'; grid[j + 5][1] = 'W'; grid[j + 5][2] = 'X'; grid[j + 5][3] = 'Y'; grid[j + 5][4] = 'Y';
      }

      int j = 5;
      
      for(; j < m - 3; j += 4){
        for(int k = 0; k < n - 2; k += 3){
          grid[k][j] = 'E'; grid[k][j + 1] = 'E'; grid[k][j + 2] = 'C'; grid[k][j + 3] = 'C';
          grid[k + 1][j] = 'E'; grid[k + 1][j + 1] = 'F'; grid[k + 1][j + 2] = 'C'; grid[k + 1][j + 3] = 'D';
          grid[k + 2][j] = 'F'; grid[k + 2][j + 1] = 'F'; grid[k + 2][j + 2] = 'D'; grid[k + 2][j + 3] = 'D';
        }
      }
      
      for(; j < m - 1; j += 2){
        for(int k = 0; k < n - 2; k += 3){
          grid[k][j] = 'E'; grid[k][j + 1] = 'E';
          grid[k + 1][j] = 'E'; grid[k + 1][j + 1] = 'F';
          grid[k + 2][j] = 'F'; grid[k + 2][j + 1] = 'F';
        }
      }
    }

    cout << "YES\n";

    if(t){
      for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
          cout << grid[i][j];
        }
        cout << '\n';
      }
    } else{
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          cout << grid[i][j];
        }
        cout << '\n';
      }
    }
  }
  
  return 0;
}