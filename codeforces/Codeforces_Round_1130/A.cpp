/*
 Code by: KoKoDuDu
 Created: 2026.10.26 21:36:44
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

  vector<int> a(n + 1), idx(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i], idx[a[i]] = i;

  set<int> st;
  for (int i = 1; i <= k; ++i) st.insert(a[i]);

  int mex = 0;
  for (auto& c : st) {
    if (mex == c)
      ++mex;
    else
      break;
  }

  if (mex == k) return void(cout << -1 << '\n');

  int maxx = -kMaxInf;
  for (int i = 1; i < k; ++i) maxx = max(maxx, a[i]);

  int minn = kMaxInf;
  for (int i = n; i > k; --i) minn = min(minn, a[i]);

  cout << idx[maxx] << ' ' << idx[minn] << '\n';
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

// 0 2 1 3 4
// 1 1 3 4 5

// 0 1 2 4 3
// 1 2 3 3 5

// 2 0 1 4 3
// 0 1 3 3 3
