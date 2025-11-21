/*
 Code by: KoKoDuDu
 Created: 2025.11.19 17:20:38
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
const int kMaxVal = 1e6 + 0307;
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

int sieve[kMaxVal], last[kMaxVal], st[4 * kMaxVal];
int a[kMaxN], pf[kMaxN], inv[kMaxN], ans[kMaxN];
int n, q;

struct Query {
  int l, r, id;
} queries[kMaxN];

void update(int id, int l, int r, int pos, int val) {
  int mid = (l + r) >> 1;
  if (l == r) {
    st[id] = st[id] * val % kMod;
    return;
  }

  if (pos <= mid) {
    update(id * 2, l, mid, pos, val);
  } else {
    update(id * 2 + 1, mid + 1, r, pos, val);
  }
  st[id] = st[id * 2] * st[id * 2 + 1] % kMod;
}

int get(int id, int l, int r, int u, int v) {
  if (l > v || r < u) return 1LL;
  if (u <= l && r <= v) return st[id];
  int mid = (l + r) >> 1;
  int s1 = get(id * 2, l, mid, u, v);
  int s2 = get(id * 2 + 1, mid + 1, r, u, v);
  return s1 * s2 % kMod;
}

void input() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> queries[i].l >> queries[i].r;
    queries[i].id = i;
  }
}

void prepare() {
  fill(st, st + 4 * kMaxN, 1);
  for (int i = 2; i <= 1000000; ++i) sieve[i] = i;
  for (int i = 2; i * i <= 1000000; ++i) {
    if (sieve[i] != i) continue;
    for (int j = i * i; j <= 1000000; j += i) sieve[j] = i;
  }

  pf[0] = 1;
  for (int i = 1; i <= n; ++i) pf[i] = pf[i - 1] * a[i] % kMod;

  inv[0] = 1;
  for (int i = 1; i <= n; ++i)
    inv[i] = inv[i - 1] * fpow(a[i], kMod - 2) % kMod;

  sort(queries + 1, queries + q + 1, [&](Query x, Query y) -> bool {
    if (x.r == y.r) return x.l < y.l;
    return x.r < y.r;
  });
}

void solve() {
  input();
  prepare();

  int pos = 0;
  for (int i = 1; i <= q; ++i) {
    auto& [l, r, id] = queries[i];
    while (pos < r) {
      ++pos;
      int val = a[pos];
      while (val != 1) {
        int p = sieve[val];
        val /= p;

        if (last[p] < pos) {
          int mul = (p - 1) * fpow(p, kMod - 2) % kMod;
          if (last[p] != 0) {
            int inv_mul = fpow(mul, kMod - 2);
            update(1, 1, n, last[p], inv_mul);
          }
          last[p] = pos;
          update(1, 1, n, last[p], mul);
        }
      }
    }

    int mul = pf[r] * inv[l - 1] % kMod;
    int mul_prime = get(1, 1, n, l, r);
    ans[id] = mul * mul_prime % kMod;
  }

  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
