/*
    Code by: KoKoDuDu
    Created: 2025.10.27 09:12:37
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

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

struct Combinatorics {
  int n;
  vector<int> fact, inv, fact_inv;

  Combinatorics(int n) : n(n), fact(n + 1), inv(n + 1), fact_inv(n + 1) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      inv[i] = kMod - (kMod / i) * inv[kMod % i] % kMod;
    }

    fact[0] = fact_inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % kMod;
      fact_inv[i] = fact_inv[i - 1] * inv[i] % kMod;
    }
  }

  int get_nCk(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * fact_inv[k] % kMod * fact_inv[n - k] % kMod;
  }

  int get_inv_fact(int i) { return fact_inv[i]; }

  int get_fact(int i) { return fact[i]; }

  int get_inv(int i) { return inv[i]; }
};

vector<int> num;
int dp[20][5][5];

int f(int pos, int stt, int cnt) {
  if (pos == (int)num.size()) return cnt <= 3;
  if (dp[pos][stt][cnt] != -1) return dp[pos][stt][cnt];

  int ans = 0;
  int lmt = stt ? 9 : num[pos];
  for (int dg = 0; dg <= lmt; ++dg) {
    int nxt_stt = stt ? stt : (dg < lmt);
    int nxt_cnt = cnt + (dg != 0);

    if (nxt_cnt > 3) continue;
    ans += f(pos + 1, nxt_stt, nxt_cnt);
  }

  return dp[pos][stt][cnt] = ans;
}

int calc(int b) {
  num.clear();
  while (b > 0) {
    num.push_back(b % 10);
    b /= 10;
  }

  reverse(num.begin(), num.end());
  memset(dp, -1, sizeof(dp));
  return f(0, 0, 0);
}

void solve() {
  int l, r;
  cin >> l >> r;
  cout << calc(r) - calc(l - 1) << '\n';
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