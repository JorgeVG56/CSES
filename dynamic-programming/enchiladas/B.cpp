/*
  Pura gente del Coach Moy

  
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int a, l; cin >> a >> l;

  int total = 1; FOR(i, 0, a) total *= 3;

  vvi dp(2, vi(total));
  dp[0][0] = 1;

  FOR(j, 0, l){
    int pow3 = 1;
    FOR(i, 0, a){
      FOR(mask, 0, total){
        int newMask = mask - pow3;
        if((mask / pow3) % 3 == 0) newMask = mask + (pow3 << 1);
        dp[1][mask] = dp[0][newMask];
        
        if(i > 1 && (mask / pow3) % 3 == 0 && (mask / (pow3 / 3)) % 3 == 0 && (mask / (pow3 / 9)) % 3 == 0){
          int newMask = mask + (pow3 / 3) + (pow3 / 9);
          dp[1][mask] = add(dp[0][newMask], dp[1][mask], MOD);
        }
      }

      swap(dp[0], dp[1]);
      pow3 *= 3;
    }
  }

  cout << dp[0][0];

  return 0;
}
