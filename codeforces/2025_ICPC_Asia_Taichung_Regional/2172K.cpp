/*
    Code by: KoKoDuDu
    Created: 2025.11.17 19:15:04
*/
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'

using namespace std;

const double PI = acos(-1);
const int kMod = 1e9 + 7;

const int kMaxVal = 1010000;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m, q;
vector<string> s;
int cnt[kMaxVal + 5];

bool in_bounds(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

void calc(int x, int y, int p, int q_dir) {
  int cur = 0, lst = 1, sum = 0;
  while (in_bounds(x, y)) {
    char c = s[x][y];
    if (isdigit(c)) {
      cur = cur * 10 + (c - '0');
    } else if (c == '+') {
      if (cur == 0) return;
      sum += cur * lst;
      lst = 1;
      cur = 0;
    } else {
      if (cur == 0) return;
      lst *= cur;
      cur = 0;
    }
    if (cur * lst + sum > kMaxVal) return;
    if (cur != 0) ++cnt[cur * lst + sum];
    x += p;
    y += q_dir;
  }
}

void solve() {
  cin >> n >> m >> q;

  s.assign(n + 1, "");
  for (int i = 1; i <= n; ++i) {
    string row;
    cin >> row;
    s[i] = " " + row;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!isdigit(s[i][j])) continue;
      for (int k = 0; k < 8; ++k) calc(i, j, dx[k], dy[k]);
      cnt[s[i][j] - '0'] -= 7;
    }
  }

  while (q--) {
    int x;
    cin >> x;
    if (0 <= x && x <= kMaxVal)
      cout << cnt[x] << el;
    else
      cout << 0 << el;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  while (t--) solve();
  return 0;
}
