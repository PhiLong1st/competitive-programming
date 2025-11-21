/*
 Code by: KoKoDuDu
 Created: 2025.11.20 22:05:01
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

// 0 tie 1 Ajisai 2 Mai
int calc(vector<int>& a, vector<int>& b) {
  int n = a.size();
  int last = -1;
  int cnt = 0;
  int a1 = 0, a2 = 0;

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      last = i;
      cnt++;
    } else {
      a1 ^= a[i];
      a2 ^= b[i];
    }
  }

  if (last == -1) {
    for (auto& x : a) a1 ^= x;
    for (auto& x : b) a2 ^= x;

    if (a1 == a2) return 0;
    return a1 > a2 ? 1 : 2;
  }

  if (cnt % 2 == 0) {
    if (a1 == a2) return 0;
    return a1 > a2 ? 1 : 2;
  }

  if (a1 < a2 && last % 2 == 0) return 0;
  if (a1 == a2 && last % 2 == 0) return 1;
  return 2;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (auto& x : a) cin >> x;
  for (auto& x : b) cin >> x;

  int res = calc(a, b);
  if (res == 0) {
    cout << "Tie\n";
  } else {
    cout << (res == 1 ? "Ajisai" : "Mai") << '\n';
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
