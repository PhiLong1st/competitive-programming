/*
 Code by: KoKoDuDu
 Created: 2025.11.27 09:25:45
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

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

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
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }

  int max_dist = n + m - 2;
  vector<set<pii>> save(max_dist + 1, set<pii>());

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int dist = i + j - 2;
      save[dist].insert({i, j});
    }
  }

  int ans = 0;
  for (int d = 0; d < (max_dist + 1) / 2; ++d) {
    if (save[d].empty() || save[max_dist - d].empty()) continue;

    int cnt_1 = 0;
    for (auto& [r, c] : save[d]) cnt_1 += a[r][c];
    for (auto& [r, c] : save[max_dist - d]) cnt_1 += a[r][c];

    int cnt_0 = (int)save[d].size() + (int)save[max_dist - d].size() - cnt_1;
    ans += min(cnt_1, cnt_0);
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
