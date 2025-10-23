/*
    Code by: KoKoDuDu
    Created: 2025.10.23 11:21:15
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> save(m + 1, vector<int>());
  vector<int> a(n + 1), primes, is_prime(m + 1, true);
  unordered_map<int, int> freq, cnt, prime_cnt;

  vector<int> spf(m + 1);
  iota(spf.begin(), spf.end(), 0);
  for (int i = 2; i * i <= m; ++i) {
    if (spf[i] != i) continue;
    for (int j = i * i; j <= m; j += i) {
      if (spf[j] != j) continue;
      spf[j] = i;
    }
  }

  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    freq[x]++;
    a[i] = x;

    if (x > m) continue;
    save[x].push_back(i);
  }

  for (int d = 1; d <= m; ++d) {
    if (!freq[d]) continue;
    for (int k = d; k <= m; k += d) cnt[k] += freq[d];
  }

  int mxm = 1, max_cnt = 0;
  for (int x = 1; x <= m; ++x) {
    if (cnt[x] <= max_cnt) continue;

    max_cnt = cnt[x];
    mxm = x;
  }

  vector<int> ans;
  for (int d = 1; d * d <= mxm; ++d) {
    if (mxm % d != 0) continue;
    for (auto& c : save[d]) ans.push_back(c);

    if (d * d == mxm) continue;
    for (auto& c : save[mxm / d]) ans.push_back(c);
  }

  auto factor = [&](int d) {
    while (d > 1) {
      int p = spf[d], e = 0;
      while (d % p == 0) d /= p, ++e;
      prime_cnt[p] = max(prime_cnt[p], e);
    }
  };

  for (int d = 1; d * d <= mxm; ++d) {
    if (mxm % d != 0) continue;
    if (freq[d]) factor(d);

    int e = mxm / d;
    if (e != d && freq[e]) factor(e);
  }

  int lcm = 1;
  for (auto& [p, c] : prime_cnt) lcm *= pow(p, c);

  cout << lcm << ' ' << max_cnt << '\n';
  sort(ans.begin(), ans.end());
  for (auto& c : ans) cout << c << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}