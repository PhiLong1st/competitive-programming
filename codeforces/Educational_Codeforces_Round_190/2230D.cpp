/*
 Code by: KoKoDuDu
 Created: 2026.05.28 11:28:11
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

  vector<int> a(n), b(n);
  vector<vector<int>> saveA(n + 1, vector<int>()), saveB(n + 1, vector<int>());
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    saveA[a[i]].push_back(i);
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    saveB[b[i]].push_back(i);
  }

  int res = 0;

  int pos = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1 || b[i] == 1) {
      if (pos != -1) res += (i - pos) * (i - pos + 1) / 2;
      pos = -1;
    } else {
      pos = pos == -1 ? i : pos;
    }
  }

  if (pos != -1) res += (n - pos) * (n - pos + 1) / 2;

  vector<int> cnt(n + 2);
  int total = 0;
  int bonus = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (a[i] == 1) {
        total += bonus + 1;
        cnt[a[i]] += bonus + 1;
      } else {
        cnt[a[i]] += cnt[a[i] - 1];
        cnt[a[i] - 1] = 0;
      }
    } else {
      if (a[i] != 1) {
        total -= cnt[a[i] - 1];
        cnt[a[i] - 1] = 0;
      }

      if (b[i] != 1) {
        total -= cnt[b[i] - 1];
        cnt[b[i] - 1] = 0;
      }
    }

    res += total;
    bonus = (a[i] != 1 && b[i] != 1) ? bonus + 1 : 0;
  }

  cout << res << '\n';
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
