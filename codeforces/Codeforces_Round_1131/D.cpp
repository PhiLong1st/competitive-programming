/*
 Code by: KoKoDuDu
 Created: 2026.10.31 22:11:30
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

  vector<int> a(n), save;
  for (int& c : a) cin >> c;

  sort(a.begin(), a.end());

  int minn = a[0];
  for (int& c : a) c -= minn;

  unordered_map<int, int> cnt;
  for (int& c : a) {
    cnt[c]++;
    if (cnt[c] > 1) continue;
    save.push_back(c);
  }

  n = save.size();
  a = save;

  vector<int> pfCnt(n);
  pfCnt[0] = cnt[a[0]];
  for (int i = 1; i < n; ++i) pfCnt[i] = pfCnt[i - 1] + cnt[a[i]];

  pii res = {0, 0};
  int cur = cnt[a[0]];

  for (int i = 1; i < n; ++i) {
    int gap = a[i] - a[i - 1];

    int w1 = gap * cur;
    int w2 = gap * (pfCnt.back() - pfCnt[i - 1]);
    if (w1 <= w2) {
      res.first += w1;
      res.second += gap;
      cur += cnt[a[i]];
    } else {
      res.first += w2;
      res.second += gap;
      cur += cnt[a[i]];
    }

    // cerr << res.first << ' ' << res.second << '\n';
  }

  cout << res.first << ' ' << res.second << '\n';
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
