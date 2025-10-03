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

  int n, x; cin >> n >> x;

  vi a(n); FOR(i, 0, n) cin >> a[i];

  vvi dp(1 << n, vi(2)); dp[0] = {1, 0};
  FOR(i, 1, 1 << n){
    dp[i] = {n, 0};

    FOR(j, 0, n){
      if((i >> j) & 1){
        int aux = i ^ (1 << j);
        int rides = dp[aux][0];
        int weight = dp[aux][1];

        if(weight + a[j] <= x){
          dp[i] = min(dp[i], {rides, weight + a[j]});
        } else{
          dp[i] = min(dp[i], {rides + 1, a[j]});
        }
      }
    }
  }

  cout << dp[(1 << n) - 1][0];

  return 0;
}
