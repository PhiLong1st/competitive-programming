/*
 Code by: KoKoDuDu
 Created: 2025.11.27 09:39:36
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

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int maxx = *max_element(a.begin() + 1, a.end());

  vector<int> primes(maxx + 1);
  iota(primes.begin(), primes.end(), 0);

  for (int i = 2; i * i <= maxx; ++i) {
    if (primes[i] != i) continue;
    for (int j = i * i; j <= maxx; j += i) primes[j] = i;
  }

  vector<pii> ans(n + 1);

  for (int i = 1; i <= n; ++i) {
    if ((a[i] == 1) || (primes[a[i]] == a[i])) {
      ans[i] = {-1, -1};
      continue;
    }

    unordered_map<int, int> cnt;
    int x = a[i];
    while (x != 1) {
      int p = primes[x];
      cnt[p]++;
      x /= p;
    }

    if (cnt.size() == 1) {
      ans[i] = {-1, -1};
      continue;
    }

    ans[i] = {-1, -1};

    int mul = 1;
    for (auto& [u, v] : cnt) {
      mul *= pow(u, v);
      int g = gcd(mul + a[i] / mul, a[i]);
      if (g == 1) {
        ans[i] = {mul, a[i] / mul};
        break;
      }
    }
  }

  for (int i = 1; i <= n; ++i) cout << ans[i].fi << ' ';
  cout << '\n';
  for (int i = 1; i <= n; ++i) cout << ans[i].se << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
