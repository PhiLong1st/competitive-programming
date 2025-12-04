/*
 Code by: KoKoDuDu
 Created: 2025.12.05 01:19:14
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
const int kMaxN = 1e5 + 0307;
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

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};

vector<int> f[kMaxN];

void sieve() {
  for (int i = 1; i * i < kMaxN; ++i) {
    for (int j = i * i; j < kMaxN; j += i) {
      f[j].push_back(i);
      if (i != j / i) f[j].push_back(j / i);
    }
  }
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  unordered_map<int, vector<int>> idx;
  idx.reserve(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    idx[a[i]].push_back(i);
  }

  while (q--) {
    int k, l, r;
    cin >> k >> l >> r;
    --l;
    --r;

    vector<pii> ft;
    for (auto& c : f[k]) {
      if (!idx.count(c)) continue;

      int i = lower_bound(idx[c].begin(), idx[c].end(), l) - idx[c].begin();
      int sz = idx[c].size();
      if (i < sz && idx[c][i] <= r) ft.emplace_back(c, idx[c][i]);
    }

    sort(ft.begin(), ft.end(), [](pii a, pii b) { return a.se < b.se; });

    int ans = 0;
    int pre = l;

    for (auto [c, id] : ft) {
      if (pre < id) ans += (id - pre) * k;
      pre = id + 1;
      while (k % c == 0) k /= c;
      ans += k;
    }

    if (pre <= r) ans += (r - pre + 1) * k;
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  sieve();

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
