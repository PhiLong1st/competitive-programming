#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

const int N = 1e5 + 7;
const int MOD = 235813;
vector<int> inv(N), fact(N), inv_fact(N);

void prepare() {
  inv[1] = 1;
  for (int i = 2; i < N; ++i) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;

  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = fact[i - 1] * i % MOD;
    inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD;
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

int check(int S, int k, int A) {
  // (S + kA) % MOD = 0
  int l = -100000;
  int r = -l;

  // kA % MOD = -S
  int a0 = (-S * fpow(k, MOD - 2) % MOD + MOD) % MOD;
  l = (l - a0) / MOD;
  r = (r - a0 + MOD) / MOD - 1;

  if (l > r) return false;

  if (l == r) {
    int c = a0 + l * MOD;
    return c != A;
  }

  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) {
    cin >> c;
    c %= MOD;
  }

  reverse(all(a));

  vector<int> Ch(n);
  int S = 0;

  for (int i = 0; i < n; ++i) {
    Ch[i] = C(n - 1, i);
    S += (i % 2 == 0 ? 1 : -1) * (Ch[i] * a[i]) % MOD;
    S = (S + MOD) % MOD;
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    int eS = S + (i % 2 == 0 ? -1 : 1) * (Ch[i] * a[i]) % MOD;
    eS = (eS + MOD) % MOD;

    int t = check(eS, Ch[i], (i % 2 == 0 ? 1 : -1) * a[i]);
    res += t;
  }

  cout << res << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  if (fopen("in.txt", "r")) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  prepare();
  int t = 1;
  while (t--) solve();
}