/*
    Code by: KoKoDuDu
    Created: 2025.11.17 17:32:40
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();
const int kNegInf = -(1LL << 60);

void maximize(int& x, int y) { x = max(x, y); }

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  string s;
  cin >> s;

  if (n == 1) return void(cout << 1 << '\n');

  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; ++i) d[i] = (s[i] != s[i + 1]);

  vector<int> dp(m + 1, kNegInf);
  dp[0] = 0;

  int len_d = n - 1;
  for (int r = 0; r < k; ++r) {
    vector<int> chain, idx;
    for (int i = r; i < len_d; i += k) chain.push_back(d[i]), idx.push_back(i);

    if (chain.empty()) continue;

    int id_l = k - 1, id_r = n - k - 1;
    bool pre = (id_l >= 0) && (id_l < len_d) && (idx.front() == id_l);
    bool post = (id_r >= 0) && (id_r < len_d) && (idx.back() == id_r);

    vector<array<int, 2>> cur(m + 1);
    for (int i = 0; i <= m; ++i) cur[i][0] = cur[i][1] = kNegInf;

    int first = chain[0];
    for (int used = 0; used <= m; ++used) {
      if (dp[used] != kNegInf) maximize(cur[used][first], dp[used]);
      if (pre && used + 1 <= m) maximize(cur[used + 1][first ^ 1], dp[used]);
    }

    for (int pos = 1; pos < chain.size(); ++pos) {
      vector<array<int, 2>> nxt(m + 1);
      for (int i = 0; i <= m; ++i) nxt[i][0] = nxt[i][1] = kNegInf;

      int val = chain[pos];
      for (int used = 0; used <= m; ++used) {
        for (int c = 0; c <= 1; ++c) {
          int cost = cur[used][c];
          if (cost == kNegInf) continue;

          int new_used = used, new_c = val, add = c;
          maximize(nxt[new_used][new_c], cost + add);

          if (used + 1 > m) continue;
          new_used = used + 1, new_c = val ^ 1, add = c ^ 1;
          maximize(nxt[new_used][new_c], cost + add);
        }
      }
      cur.swap(nxt);
    }

    vector<int> temp_dp(m + 1, kNegInf);
    for (int used = 0; used <= m; ++used) {
      for (int c = 0; c <= 1; ++c) {
        int cost = cur[used][c];
        if (cost != kNegInf) maximize(temp_dp[used], cost + c);
        if (post && used + 1 <= m) maximize(temp_dp[used + 1], cost + (c ^ 1));
      }
    }
    dp.swap(temp_dp);
  }

  int best = 0;
  for (int used = 0; used <= m; ++used) maximize(best, dp[used]);
  cout << best + 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t = 1;
  while (t--) solve();
  return 0;
}
