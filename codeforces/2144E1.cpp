/*
    Code by: KoKoDuDu
    Created: 2025.10.10 16:52:19
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 998244353;
const int kMaxN = 3e5 + 0307;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

int pw2[kMaxN + 1];

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

static inline void add(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul(int a, int b) {
  a = a * b % kMod;
  return a;
}

vector<vector<int>> make_dp(vector<int>& arr, vector<int>& vt, bool is_right) {
  int sz = vt.size();
  int n = arr.size();

  vector<vector<int>> dp(sz, vector<int>(n));

  for (int p = 0; p < sz; ++p) {
    if (p != 0) {
      int sum = 0;
      for (int i = 0; i < n; ++i) {
        if (vt[p - 1] == arr[i]) add(sum, dp[p - 1][i]);
        if (vt[p - 1] > arr[i]) sum = mul(sum, 2);
        if (arr[i] != vt[p]) continue;

        add(dp[p][i], sum);
      }
    }

    int bonus = 0;
    for (int i = 0; i < n; ++i) {
      dp[0][i] = 1;

      if (vt[p] > arr[i]) bonus = mul(bonus, 2);
      if (arr[i] != vt[p]) continue;
      if (is_right && p == sz - 1) continue;

      add(dp[p][i], bonus);
      add(bonus, dp[p][i]);
    }
  }

  return dp;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), l, r;
  for (auto& c : a) cin >> c;

  for (int i = 0; i < n; ++i) {
    if (!l.empty() && l.back() >= a[i]) continue;
    l.push_back(a[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    if (!r.empty() && r.back() >= a[i]) continue;
    r.push_back(a[i]);
  }

  vector<vector<int>> dpL = make_dp(a, l, false);

  vector<int> b = a;
  reverse(b.begin(), b.end());
  vector<vector<int>> dpR = make_dp(b, r, true);

  int ans = 0, sL = l.size() - 1, sR = r.size() - 1;
  for (int i = 0; i < n; ++i) {
    if (a[i] != l[sL]) continue;
    add(ans, mul(dpL[sL][i], dpR[sR][n - 1 - i]));
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  pw2[0] = 1;
  for (int i = 1; i <= kMaxN; ++i) pw2[i] = (pw2[i - 1] * 2LL) % kMod;

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}