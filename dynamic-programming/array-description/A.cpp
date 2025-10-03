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

  int n, m; cin >> n >> m;

  vi a(n); FOR(i, 0, n) cin >> a[i];

  vvi dp(n, vi(m + 5));

  if(a[n - 1] == 0){
    FOR(i, 1, m + 1){
      dp[n - 1][i + 1] = 1;
    }
  } else{
    dp[n - 1][a[n - 1] + 1] = 1;
  }

  ROF(i, n - 1, 0){
    if(a[i] == 0){
      FOR(j, 1, m + 1){
        dp[i][j + 1] = add(add(dp[i + 1][j], dp[i + 1][j + 1], MOD), dp[i + 1][j + 2], MOD);
      }
    } else{
      int j = a[i];
      dp[i][j + 1] = add(add(dp[i + 1][j], dp[i + 1][j + 1], MOD), dp[i + 1][j + 2], MOD);
    }
  }

  int ans = 0;
  FOR(i, 1, m + 1){
    ans = add(ans, dp[0][i + 1], MOD);
  }

  cout << ans;

  return 0;
}
