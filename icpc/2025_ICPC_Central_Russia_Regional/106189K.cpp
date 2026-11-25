/*
 Code by: KoKoDuDu
 Created: 2025.12.07 21:27:02
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
const int kMaxVal = 5e4;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int normalize(int x, int md) {
  if (x >= 2 * md) x %= md;
  if (x < -md) x %= md;
  if (x >= md) x -= md;
  if (x < 0) x += md;
  return x;
}

template <int MD>
struct Mint {
  using M = Mint;
  int v;

  Mint(int _v = 0) : v(normalize(_v, MD)) { ; }

  explicit operator bool() const { return v != 0; }

  M& operator+=(const M& r) {
    v += r.v;
    if (v >= MD) v -= MD;
    return *this;
  }

  M& operator-=(const M& r) {
    v -= r.v;
    if (v < 0) v += MD;
    return *this;
  }

  M& operator*=(const M& r) {
    v = (1ll * v * r.v) % MD;
    return *this;
  }

  M& operator/=(const M& r) { return *this *= r.inv(); }

  friend M operator+(M a, const M& b) { return a += b; }

  friend M operator-(M a, const M& b) { return a -= b; }

  friend M operator*(M a, const M& b) { return a *= b; }

  friend M operator/(M a, const M& b) { return a /= b; }

  bool operator==(const M& r) const { return v == r.v; }

  bool operator!=(const M& r) const { return v != r.v; }

  M power(int b) const {
    M r = 1;
    for (M a = *this; b; b >>= 1, a *= a)
      if (b & 1) r *= a;
    return r;
  }

  M inv() const { return power(MD - 2); }

  friend istream& operator>>(istream& is, M& r) {
    int x;
    is >> x;
    r = M(x);
    return is;
  }

  friend ostream& operator<<(ostream& os, const M& r) { return os << r.v; }
};
using mint = Mint<(int)1e9 + 7>;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

void solve() {
  int n;
  cin >> n;

  vector<int> is_prime(kMaxVal + 37, true);
  is_prime[0] = is_prime[1] = false;

  vector<int> primes;
  for (int i = 2; i <= kMaxVal; ++i) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for (int j = i * i; j <= kMaxVal; j += i) is_prime[j] = false;
  }

  auto f = [&](int w, int p) -> int {
    int res = 0;
    while (w) {
      res += w / p;
      w /= p;
    }
    return res;
  };

  auto check = [&](int a, int b, int c, int x) -> bool {
    for (int& p : primes) {
      int cnt = f(a, p) - f(b, p) - f(c, p);
      if (cnt < 0) return false;
      while (x % p == 0) {
        x /= p;
        --cnt;
      }
      if (cnt != 0) return false;
    }
    return true;
  };

  array<int, 3> ans = {-1, -1, -1};
  unordered_map<int, vector<int>> mp;
  mint tmp = 1;

  for (int b = 2; b <= kMaxVal; ++b) {
    tmp *= b;
    mp[(tmp * n).v].push_back(b);
    mint cur = 1;
    for (int a = b + 1; a <= min(b + 50, kMaxVal); ++a) {
      cur *= a;
      if (mp.find(cur.v) == mp.end()) continue;
      for (auto& c : mp[cur.v]) {
        if (!check(a, b, c, n)) continue;
        auto w = array<int, 3>{a, b, c};
        ans = (ans[0] == -1) ? w : min(ans, w);
      }
    }
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}