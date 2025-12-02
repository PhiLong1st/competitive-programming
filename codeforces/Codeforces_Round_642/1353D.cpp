/*
 Code by: KoKoDuDu
 Created: 2025.12.02 23:02:00
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

struct Range {
  int l, r;
};

void solve() {
  int n;
  cin >> n;

  auto cmp = [&](Range a, Range b) -> bool {
    int sz1 = a.r - a.l + 1;
    int sz2 = b.r - b.l + 1;

    if (sz1 == sz2) return a.l > b.l;
    return sz1 < sz2;
  };

  int cnt = 0;
  priority_queue<Range, vector<Range>, decltype(cmp)> pq(cmp);
  pq.push({1, n});

  vector<int> ans(n + 1);

  while (!pq.empty()) {
    auto [l, r] = pq.top();
    pq.pop();

    if (l > r) continue;

    int sz = r - l + 1;
    int pos = sz % 2 ? (l + r) / 2 : (l + r - 1) / 2;
    ans[pos] = ++cnt;

    if (pos - 1 >= l) pq.push({l, pos - 1});
    if (pos + 1 <= r) pq.push({pos + 1, r});

    // cerr << l << ' ' << pos - 1 << ' ';
    // cerr << pos + 1 << ' ' << r << '\n';
  }

  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
  cout << '\n';
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
