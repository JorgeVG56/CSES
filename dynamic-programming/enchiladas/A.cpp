/*
Pura gente del Coach Moy

Seleccion           ->  (Sigma)
Proyeccion          ->  (Pi)
Union               ->  (U)
Diferencia          ->  (-)
Producto cartesiano ->  (x)
Renombramiento      ->  (p)

Sintaxis:
(Sigma) campo(s)(nombre_tabla)

0 -> End
1 -> Empty (start of a enchilada)  
2 -> Empty (middle of a enchilada)
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define INF 1e18
#define ENDL '\n'

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const ll MOD = 1000000;

inline int add(int x, int y, int m) {
  return x + y < m ? x + y : x + y - m;
}
inline int sub(int x, int y, int m) {
  return x >= y ? x - y : x - y + m;
}
inline int mul(int x, int y, int m) {
  return int((ll)x * y % m);
}

int modPow(int x, int n, int m){
  if(n == 0)
  return 1;
  
  int u = modPow(x, n / 2, m) % m;
  u = mul(u, u, m);
  
  if(n & 1)
  u = mul(u, x, m);
  
  return u;
}


vi pow3 = {1, 3, 9, 27, 81, 243, 729, 2187};

void calculate(int y, int m, int mask, int nextMask, vi & nxt){
  if(y >= m){
    nxt.pb(nextMask);
    return;
  }

  int state = mask / pow3[y];
  if(state % 3 == 2){
    calculate(y + 1, m, mask, nextMask, nxt);
  } else if(state % 3 == 1){
    calculate(y + 1, m, mask, nextMask + (pow3[y] << 1), nxt);
  } else{
    calculate(y + 1, m, mask, nextMask + pow3[y], nxt);
    if(y + 2 < m && (state / 3) % 3 == 0 && (state / 9) % 3 == 0) calculate(y + 3, m, mask, nextMask, nxt);
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int a, l; cin >> a >> l;
  
  int total = pow3[a];
  
  vvi nxt(total); FOR(i, 0, total) calculate(0, a, i, 0, nxt[i]);

  vvi dp(2, vi(total));
  vi vis(total);
  dp[0][0] = 1;
  
  vector<queue<int>> q(2); q[0].push(0);
  
  FOR(i, 0, l){
    while(!q[0].empty()){
      auto mask = q[0].front(); q[0].pop();
      for(auto & next_mask : nxt[mask]){
        dp[1][next_mask] = add(dp[0][mask], dp[1][next_mask], MOD);
        if(vis[next_mask]) continue;
        q[1].push(next_mask);
        vis[next_mask] = 1;
      }

      dp[0][mask] = 0;
    }

    while(!q[1].empty()){
      vis[q[1].front()] = 0;
      if(dp[1][q[1].front()]) q[0].push(q[1].front()); 
      q[1].pop();
    }
    
    swap(dp[0], dp[1]);
  }
  
  cout << dp[0][0];
  
  return 0;
}