  /*
  Code by: KoKoDuDu
  Created: 2026.09.21 22:31:47
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

  vector<int> primes;

  void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> f(n + 1, kMaxInf);
    for (int i = 1; i <= k; ++i) f[i] = 0;

    for (int i = k + 1; i <= n; ++i) {
      int val = i;
      vector<int> vt;

      for (int j = 0; j < primes.size(); ++j) {
        int p = primes[j];
        if (p * p > val) break;
        if (val % p != 0) continue;
        vt.push_back(p);

        while (val > 1 && val % p == 0) val /= p;
      }

      if (val != 1) f[i] = min(f[i], f[i / val] * val + 1);
      for (int& p : vt) f[i] = min(f[i], f[i / p] * p + 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += f[a[i]];
    cout << ans << '\n';
  }

  int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int maxN = 200020;
    vector<bool> isPrime(maxN + 1, true);

    for (int i = 2; i <= maxN; ++i) {
      if (!isPrime[i]) continue;
      for (int j = i * i; j <= maxN; j += i) isPrime[j] = false;
    }

    for (int i = 2; i <= maxN; ++i) {
      if (!isPrime[i]) continue;
      primes.push_back(i);
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
  }
