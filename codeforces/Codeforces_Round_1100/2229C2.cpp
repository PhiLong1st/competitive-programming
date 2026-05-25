/*
 Code by: KoKoDuDu
 Created: 2026.05.25 13:26:40
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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int sum = accumulate(a.begin(), a.end(), 0LL);
  int res = sum;
  int sum_pos = 0, sum_neg = 0;

  int pf = 0, pos = -1;
  for (int i = 1; i <= n; ++i) {
    pf += abs(a[i]);
    sum_pos += a[i] > 0 ? a[i] : 0;
    sum_neg += a[i] < 0 ? a[i] : 0;

    if (a[i] < 0) continue;

    int val = sum - sum_pos - sum_neg - 2 * a[i] + pf;
    if (res < val) {
      res = val;
      pos = i;
    }
  }
  if (pos == -1) return void(cout << 0 << '\n' << '\n');

  vector<int> save;
  for (int i = pos - 1; i >= 1; --i) {
    int t = save.size();
    bool isNeg = (t % 2 && a[i] > 0) || (t % 2 == 0 && a[i] < 0);
    if (isNeg) continue;

    save.push_back(i);
  }

  cout << save.size() + 1 << '\n';
  for (int& x : save) cout << x << ' ';
  cout << pos << '\n';
  // cerr << res << '\n';
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
