/*
 Code by: KoKoDuDu
 Created: 2025.12.01 15:17:14
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
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int& x : a) cin >> x;
  sort(a.begin(), a.end());

  int taro = 1;
  int minn = a[0];

  vector<vector<int>> dp(2, vector<int>(k + 1));

  for (int pile = 0; pile <= k; ++pile) {
    for (int cur = 0; cur < 2; ++cur) {
      if (pile < minn) {
        dp[cur][pile] = (cur != taro);
        continue;
      }

      bool is_win = (cur == taro) ? false : true;
      int next = !cur;

      for (int& p : a) {
        if (p > pile) break;
        if (cur == taro) {
          is_win |= dp[next][pile - p];
        } else {
          is_win &= dp[next][pile - p];
        }
      }
      dp[cur][pile] = is_win;
    }
  }
  cout << (dp[taro][k] ? "First" : "Second");
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
