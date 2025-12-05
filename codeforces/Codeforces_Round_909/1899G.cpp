/*
 Code by: KoKoDuDu
 Created: 2025.12.05 09:30:08
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

//=================================
int n, q;
int cnt, pos_save;
int l[kMaxN], r[kMaxN];
int save[kMaxN], p[kMaxN];
int fw[kMaxN];
int ans[kMaxN];

void update(int u, int v) {
  int idx = u;
  while (idx <= n) {
    fw[idx] += v;
    idx += (idx & (-idx));
  }
}

int get_sum(int p) {
  if (p <= 0) return 0;
  int idx = p, res = 0;
  while (idx > 0) {
    res += fw[idx];
    idx -= (idx & (-idx));
  }
  return res;
}

int get_sum_range(int x, int y) { return get_sum(y) - get_sum(x - 1); }

void dfs(int x, int p, vector<vector<int>>& adj) {
  l[x] = ++cnt;
  save[++pos_save] = x;
  for (int& v : adj[x]) {
    if (v == p) continue;
    dfs(v, x, adj);
  }
  r[x] = cnt;
}

void reset() {
  cnt = 0;
  pos_save = 0;
  memset(fw, 0, sizeof(fw));
}

int S = sqrt(kMaxN);
struct Query {
  int l, r, x, id;
  Query() {}
  Query(int l, int r, int x, int id) : l(l), r(r), x(x), id(id) {}

  bool operator<(const Query& other) const {
    if (l / S != other.l / S) return (l / S) < (other.l / S);
    return r < other.r;
  }
} qr[kMaxN];

void solve() {
  reset();

  cin >> n >> q;
  vector<vector<int>> adj(n + 1, vector<int>());

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) cin >> p[i];
  dfs(1, 0, adj);

  for (int i = 0; i < q; ++i) {
    cin >> qr[i].l >> qr[i].r >> qr[i].x;
    qr[i].id = i;
  }

  sort(qr, qr + q);

  int pos_l = 1, pos_r = 0;
  for (int i = 0; i < q; ++i) {
    auto& [start, end, val, id] = qr[i];
    while (pos_r < end) update(l[p[++pos_r]], 1);
    while (pos_r > end) update(l[p[pos_r--]], -1);
    while (pos_l < start) update(l[p[pos_l++]], -1);
    while (pos_l > start) update(l[p[--pos_l]], 1);
    ans[id] = get_sum_range(l[val], r[val]) != 0;
  }

  for (int i = 0; i < q; ++i) cout << (ans[i] ? "YES" : "NO") << '\n';
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
