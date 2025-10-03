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

  int n; cin >> n;

  vll dp (1000005, INF); dp[0] = 0;

  FOR(a, 0, 10){
    FOR(b, 0, 10){
      FOR(c, 0, 10){
        FOR(d, 0, 10){
          FOR(e, 0, 10){
            FOR(f, 0, 10){
              int number = a * 100000 + b * 10000 + c * 1000 + d * 100 + e * 10 + f;
              if(number == 0) continue;
              
              dp[number] = 1 + min({dp[number - a], dp[number - b], dp[number - c], dp[number - d], dp[number - e], dp[number - f]});
            }
          }
        }
      }
    }
  }

  dp[1000000] = 1 + dp[999999];

  cout << dp[n];

  return 0;
}
