/*
 Code by: KoKoDuDu
 Created: 2025.11.26 20:11:14
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
const int kMod = 998244353;
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

  vector<array<int, 4>> a(n);
  for (auto& [l, r, p, q] : a) cin >> l >> r >> p >> q;

  int total_unexist = 1;

  for (auto& [l, r, p, q] : a) {
    p %= kMod;
    q %= kMod;

    int inv_q = fpow(q, kMod - 2);
    int exist_prob = p * inv_q % kMod;
    int unexist_prob = ((q - p + kMod) % kMod) * inv_q % kMod;

    p = exist_prob;
    q = unexist_prob;

    total_unexist = total_unexist * q % kMod;
  }

  vector<vector<int>> save(m + 1, vector<int>());

  for (int i = 0; i < n; ++i) {
    auto& [l, r, p, q] = a[i];
    save[r].push_back(i);
  }

  vector<int> dp(m + 1);
  dp[0] = 1;

  for (int pos = 1; pos <= m; ++pos) {
    for (auto& idx : save[pos]) {
      auto& [l, r, exist, unexist] = a[idx];
      int t = exist * fpow(unexist, kMod - 2) % kMod;
      dp[pos] += dp[l - 1] * t % kMod;
      dp[pos] %= kMod;
    }
  }

  cout << dp[m] * total_unexist % kMod;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
