/*
    Code by: KoKoDuDu
    Created: 2025.10.17 22:50:31
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

void solve() {
  int n;
  cin >> n;

  auto ask = [&](int t, int l, int r) {
    cout << t << ' ' << l << ' ' << r << "\n";
    cout.flush();

    int res;
    cin >> res;
    return res;
  };

  int l = 1, r = n, first = 0, last = 0;
  while (l <= r) {
    int m = (l + r) / 2;
    int x1 = ask(1, m, n);
    int x2 = ask(2, m, n);
    if (x1 == x2) {
      r = m - 1;
    } else {
      last = m;
      l = m + 1;
    }
  }

  int total = ask(2, 1, n) - ask(1, 1, n);

  cout << "! " << last - total + 1 << ' ' << last << '\n';
  cout.flush();
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