/*
 Code by: KoKoDuDu
 Created: 2026.06.12 23:32:42
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

  vector<int> a(n);
  for (int& c : a) cin >> c;

  if (n == 1) {
    cout << 0 << '\n';
    return;
  }

  vector<vector<int>> f(n + 1, vector<int>(n + 1)), res(n + 1, vector<int>());
  for (int i = 0; i < n; ++i) {
    unordered_set<int> st;
    for (int j = i; j < n; ++j) {
      st.insert(a[j]);

      int sz = j - i + 1;
      if (st.size() == sz) {
        f[i][j] = true;
        res[sz].push_back(i);
        // cout << i << ' ' << j << '\n';
      }
    }
  }

  for (int sz = n; sz >= 1; --sz) {
    vector<int> tmp;

    for (int i = 0; i < res[sz].size(); ++i) {
      int l = res[sz][i];
      int r = l + sz - 1;
      
      cout << sz << ' ' << l << ' ' << r << '\n';
      // int minn = 1;  // min[l][r]

      // auto pos = upper_bound(res[sz].begin(), res[sz].end(), r);
      // if (pos != res[sz].end()) {
      //   cout << l << ' ' << r << ' ' << sz << '\n';
      //   return;
      // }
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
