/*
 Code by: KoKoDuDu
 Created: 2025.11.28 12:31:08
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
  int n;
  cin >> n;

  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  vector<bool> er(n + 1), ec(n + 1);

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < n / 4; j++) {
      int x = 0;
      if (s[j] >= '0' && s[j] <= '9') {
        x = s[j] - '0';
      } else {
        x = s[j] - 'A' + 10;
      }
      for (int k = 3; k >= 0; k--) {
        if (x % 2 == 1) {
          a[i][4 * j + k] = true;
        }
        x /= 2;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    ec[i] = true;
    for (int j = 0; j < n; j++) {
      if (a[i][j] != a[i - 1][j]) ec[i] = false;
    }
  }

  for (int j = 1; j < n; j++) {
    er[j] = true;
    for (int i = 0; i < n; i++) {
      if (a[i][j] != a[i][j - 1]) er[j] = false;
    }
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    if (n % i) continue;
    bool ok = true;
    for (int j = 0; j < n; j++) {
      if (j % i != 0 && (!ec[j] || !er[j])) ok = false;
    }
    if (ok) ans = i;
  }
  cout << ans << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
