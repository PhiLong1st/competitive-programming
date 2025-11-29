/*
 Code by: KoKoDuDu
 Created: 2025.11.29 16:26:36
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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  vector<int> valid(n);
  iota(valid.begin(), valid.end(), 0);

  vector<int> gaps(n);
  for (int i = 0; i < n; ++i) gaps[i] = valid[i] - a[i];

  vector<int> neg, pos;
  for (int i = 0; i < n; ++i) {
    if (gaps[i] < 0) neg.push_back(abs(gaps[i]));
    if (gaps[i] > 0) pos.push_back(gaps[i]);
  }

  int n_sz = neg.size();
  int p_sz = pos.size();
  int cnt_0 = n - n_sz - p_sz;

  int ans = 0;
  if (abs(n_sz - p_sz) <= cnt_0) {
    for (int& x : gaps) ans += abs(x);
    cout << ans;
    return;
  }

  sort(neg.begin(), neg.end());
  sort(pos.begin(), pos.end());

  if (n_sz > p_sz + cnt_0) swap(neg, pos);

  for (int i = 0; i < cnt_0; ++i) neg.push_back(0);
  int d = (abs(n_sz - p_sz) - cnt_0 + 1) / 2;
  int val = pos[d - 1];
  for (int i = 0; i < pos.size(); ++i) pos[i] = abs(pos[i] - val);
  for (int i = 0; i < neg.size(); ++i) neg[i] = abs(neg[i] + val);

  ans = 0;
  for (int& x : neg) ans += x;
  for (int& x : pos) ans += x;
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
