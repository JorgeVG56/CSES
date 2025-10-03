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
  vvll p(n, vll(3)); FOR(i, 0, n) cin >> p[i][0] >> p[i][1] >> p[i][2];

  sort(ALL(p));

  map<ll, ll> mp;
  ROF(i, n, 0){
    auto it = mp.upper_bound(p[i][1]);

    if(it == mp.end()){
      mp[p[i][0]] = max(mp[p[i][0]], p[i][2]);
    } else{
      mp[p[i][0]] = max(mp[p[i][0]], it->second + p[i][2]);
    }

    if(i < n - 1) mp[p[i][0]] = max(mp[p[i][0]], mp[p[i + 1][0]]);
  }

  cout << mp.begin() -> second;

  return 0;
}
