/*
 Code by: KoKoDuDu
 Created: 2025.12.05 13:42:31
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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

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

  vector<int> b1, b2;
  for (int i = 0; i < n; ++i) b1.push_back(i);

  b2.push_back(1);
  for (int i = 1; i < n; ++i) cout << i << ' ' << i + 1 << '\n';

  int q;
  cin >> q;
  while (q--) {
    int d;
    cin >> d;
    ++d;

    if (b1.size() == d) {
      cout << "-1 -1 -1\n";
    } else if (b1.size() < d) {
      d = d - b1.size();
      vector<int> qq(b2.end() - d, b2.end());

      int pos = b2.size() - d;
      cout << b2[pos] + 1 << ' ' << b2[pos - 1] + 1 << ' ' << b1.back() + 1
           << '\n';

      for (int i = 0; i < d; ++i) b2.pop_back();
      for (auto i : qq) b1.push_back(i);
    } else {
      d = b1.size() - d;
      vector<int> qq(b1.end() - d, b1.end());
      int pos = b1.size() - d;
      cout << b1[pos] + 1 << ' ' << b1[pos - 1] + 1 << ' ' << b2.back() + 1
           << '\n';

      for (int i = 0; i < d; ++i) b1.pop_back();
      for (auto i : qq) b2.push_back(i);
    }
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
