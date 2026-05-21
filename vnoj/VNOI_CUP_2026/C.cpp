/*
 Code by: KoKoDuDu
 Created: 2026.05.16 22:09:45
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
  int n, k, s;
  cin >> n >> k >> s;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (n <= 500) {
    vector<vector<int>> f(n + 1, vector<int>(k + 1));

    int pre = 0;
    for (int i = 1; i <= n; ++i) {
      pre += a[i];
      f[i][1] = pre <= s;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 2; j <= min(k, i); ++j) {
        int sum = a[i];
        for (int u = i - 1; u >= 0; --u) {
          if (sum <= s) {
            f[i][j] = max(f[i][j], f[u][j - 1] + 1);
          } else {
            f[i][j] = max(f[i][j], f[u][j - 1]);
          }
          sum += a[u];
        }
      }
    }

    cout << f[n][k] << '\n';
    return;
  }
  cout << 0 << '\n';
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
