#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;

const int kMaxN = 3e5 + 0307;
const int kMaxVal = kMaxN * 2 + 0307;
const int kMaxLg = 20;

int par[kMaxLg][kMaxVal];
int lg2[kMaxVal];
int col[kMaxVal];
int n, q;
string s;

int find(int t, int x) {
  if (par[t][x] == x) return x;
  return par[t][x] = find(t, par[t][x]);
}

void join(int t, int l, int r) {
  int fl = find(t, l), fr = find(t, r);
  if (fl < fr) swap(fl, fr);
  par[t][fl] = par[t][fr];
}

void link(int l, int r, int len) {
  int now = lg2[len];
  int dt = 1LL << now;
  join(now, l, r);
  join(now, l + len - dt, r + len - dt);
}

void prepare() {
  lg2[1] = 0;
  for (int i = 2; i < kMaxVal; ++i) lg2[i] = lg2[i >> 1] + 1;
}

void solve() {
  cin >> n >> q >> s;
  s = " " + s;

  for (int t = 0; t < kMaxLg; ++t)
    for (int j = 1; j <= 2 * n; ++j) par[t][j] = j;

  for (int i = 1; i <= n; ++i) join(0, i, 2 * n - i + 1);

  for (int i = 1; i <= q; ++i) {
    int l, r;
    cin >> l >> r;
    int len = (r - l + 1) / 2;
    if (!len) continue;
    link(l, 2 * n - r + 1, len);
  }

  for (int bit = kMaxLg - 1; bit >= 1; --bit) {
    int dt = (1 << (bit - 1));
    for (int j = 1; j <= 2 * n; ++j) {
      int now = find(bit, j);
      if (now == j) continue;
      join(bit - 1, j, now);
      join(bit - 1, j + dt, now + dt);
    }
  }

  for (int i = 1; i <= 2 * n; ++i) col[i] = -1;

  for (int i = 1; i <= n; ++i) {
    if (s[i] == '?') continue;
    int root = find(0, i);
    int val = s[i] - '0';
    if (col[root] == -1)
      col[root] = val;
    else if (col[root] != val)
      return void(cout << 0 << '\n');
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i)
    if (find(0, i) == i && col[i] == -1) ans = (ans + ans) % kMod;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  prepare();

  int t = 1;
  while (t--) solve();
  return 0;
}
