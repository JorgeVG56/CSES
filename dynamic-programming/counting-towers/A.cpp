/*
  Pura gente del Coach Moy

  Not continuing (2 {~1, ~1} {~1-1})
  Continuing (4 {1, ~1} {~1, 1} {~1, ~1} {1-1})
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
const ll MOD = 1000000007;

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

  int tc; cin >> tc;

  vvi dp(1000005, vi(2, 1));
  FOR(i, 2, 1000005){
    dp[i][0] = add(mul(4, dp[i - 1][0], MOD), dp[i - 1][1], MOD);
    dp[i][1] = add(dp[i - 1][0], mul(2, dp[i - 1][1], MOD), MOD);

    // cout << i << " = " << dp[i][0] << " - " << dp[i][1] << ENDL;
  }

  FOR(c, 0, tc){
    int n; cin >> n;
    
    cout << add(dp[n][0], dp[n][1], MOD) << ENDL;
  }

  return 0;
}
