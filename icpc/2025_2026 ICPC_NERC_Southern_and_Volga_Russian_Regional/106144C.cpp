/*
 Code by: KoKoDuDu
 Created: 2025.12.06 22:08:03
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
  int n;
  cin >> n;

  string s;
  cin >> s;
  s = " " + s;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) a[i] = (s[i] == '(' ? 1 : -1);

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, kMinInf));

  int mono = 1;
  auto f = [&](auto&& f, int cur_turn, int l, int r) -> int {
    if (l == r) return a[l];
    if (dp[l][r] != kMinInf) return dp[l][r];

    int next_turn = !cur_turn;
    if (cur_turn == mono) {
      int s1 = f(f, next_turn, l + 1, r) + a[l];
      int s2 = f(f, next_turn, l, r - 1) + a[r];
      return dp[l][r] = min({0ll, a[l], a[r], s1, s2});
    } else {
      int s1 = f(f, next_turn, l + 1, r);
      int s2 = f(f, next_turn, l, r - 1);
      return dp[l][r] = max(s1, s2);
    }
  };

  if (s[1] == '(' && 1 + f(f, !mono, 2, n) <= 0) {
    cout << "Monocarp\n";
  } else if (s[n] == '(' && 1 + f(f, !mono, 1, n - 1) <= 0) {
    cout << "Monocarp\n";
  } else {
    cout << "Polycarp\n";
  }
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