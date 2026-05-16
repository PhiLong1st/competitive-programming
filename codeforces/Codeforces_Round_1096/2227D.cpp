/*
 Code by: KoKoDuDu
 Created: 2026.04.30 22:07:32
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

int calc(set<int>& st) {
  int cnt = 0;

  for (auto c : st) {
    if (cnt != c) break;
    ++cnt;
  }

  return cnt;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(2 * n);
  for (int& c : a) cin >> c;

  int res = 1;

  // way1
  int pos1 = 2 * n, pos2 = -1;
  for (int i = 0; i < 2 * n; ++i) {
    if (a[i] != 0) continue;

    pos1 = min(pos1, i);
    pos2 = max(pos2, i);
  }

  set<int> way1, way2, way3;

  int l = pos1, r = pos2, isPalin = 1;
  while (l <= r) {
    if (a[l] != a[r]) {
      isPalin = 0;
      break;
    }

    way1.insert(a[l]);
    way1.insert(a[r]);

    l++, r--;
  }

  if (isPalin) {
    l = pos1, r = pos2;
    while (0 <= l && r < 2 * n && a[l] == a[r]) {
      way1.insert(a[l]);
      way1.insert(a[r]);
      l--, r++;
    }
    res = max(res, calc(way1));
  }

  // way2
  l = pos1, r = pos1;
  while (0 <= l && r < 2 * n && a[l] == a[r]) {
    way2.insert(a[l]);
    way2.insert(a[r]);
    l--, r++;
  }

  res = max(res, calc(way2));

  // way3
  l = pos2, r = pos2;
  while (0 <= l && r < 2 * n && a[l] == a[r]) {
    way3.insert(a[l]);
    way3.insert(a[r]);
    l--, r++;
  }

  res = max(res, calc(way3));
  
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
