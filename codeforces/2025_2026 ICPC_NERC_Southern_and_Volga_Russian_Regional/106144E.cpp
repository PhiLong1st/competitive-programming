/*
 Code by: KoKoDuDu
 Created: 2025.12.06 19:16:27
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// #include "debug.h"
// #endif

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> a(n + 1, vector<char>(m + 1));
  vector<vector<int>> pf(n + 1, vector<int>(m + 1));
  vector<vector<bool>> seen(n + 1, vector<bool>(m + 1));

  int dx[] = {0, 0, 1};
  int dy[] = {-1, 1, 0};

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  }

  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) pf[i][j] = pf[i - 1][j] + (a[i][j] == 'x');
  }

  queue<pii> que;
  que.push({1, 1});
  seen[1][1] = true;

  auto is_ok = [&](int r, int c) -> bool {
    bool in_bounds = (1 <= r && r + k - 1 <= n && 1 <= c && c <= m);
    if (!in_bounds) return false;

    if (seen[r][c]) return false;

    int cnt_obs = pf[r + k - 1][c] - pf[r - 1][c];
    return (cnt_obs == 0);
  };

  int ans = 0;
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    ans = max(ans, x + k - 1);

    for (int i = 0; i < 3; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (!is_ok(nx, ny)) continue;

      que.push({nx, ny});
      seen[nx][ny] = true;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
