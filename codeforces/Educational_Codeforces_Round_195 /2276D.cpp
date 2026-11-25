/*
 Code by: KoKoDuDu
 Created: 2026.10.14 23:08:01
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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

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

struct DSU {
  vector<int> par, child, sz;
  int numComp;

  DSU(int n) : par(n + 1), child(n + 1, 0), sz(n + 1, 1), numComp(n) {
    iota(par.begin(), par.end(), 0ll);
  }

  int findPar(int x) {
    if (x == par[x]) return x;
    return par[x] = findPar(par[x]);
  }

  int join(int x, int y) {
    x = findPar(x);
    y = findPar(y);

    if (x == y) return -1;

    --numComp;

    if (sz[x] < sz[y]) {
      sz[y] += sz[x];
      par[x] = y;
    } else {
      sz[x] += sz[y];
      par[y] = x;
    }

    if (child[x] == child[y]) child[y]++;

    return y;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  DSU dsu(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    dsu.join(u, v);
  }

  for (int i = 1; i <= n; ++i)
    if (adj[i].size() == 0) return void(cout << "Brain Melt\n");

  if (dsu.numComp >= 3) return void(cout << "Many\n");

  if (dsu.numComp < 3) {
    if (n <= 3) {
      return void(cout << ((m >= 3) ? "Many\n" : "2\n"));
    } else {
      int d = 0;
      for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 1) continue;
        if (adj[i].size() != n - 1) return void(cout << "Many\n");
        d++;
      }

      cout << (d == 1 ? "2\n" : "Many\n");
    }

  } else {
    cout << "Many\n";
  }
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
