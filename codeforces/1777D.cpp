/*
    Code by: KoKoDuDu
    Created: 2025.10.20 14:23:26
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

int fpow(int n, int x, int MOD) {
  int res = 1;
  while (x > 0) {
    if (x & 1) {
      res = (res * n) % MOD;
    }
    n = (n * n) % MOD;
    x >>= 1;
  }
  return res;
}

int DFS(int v, vector<int> edges[], int p, int dep, int ped[]) {
  int mdep = dep;
  for (auto it : edges[v])
    if (it != p) mdep = max(DFS(it, edges, v, dep + 1, ped), mdep);
  ped[v] = mdep - dep + 1;
  return mdep;
}

void solve() {
  int n;
  cin >> n;
  vector<int> edges[n];
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  int ped[n];
  DFS(0, edges, 0, 0, ped);

  int p = fpow(2, n - 1, kMod), ans = 0;
  for (int i = 0; i < n; i++) {
    ans += p * ped[i] % kMod;
    ans %= kMod;
  }
  cout << ans << "\n";
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