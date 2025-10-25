/*
    Code by: KoKoDuDu
    Created: 2025.10.24 21:46:47
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

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), cnt(n + 1), div(n + 1);
  for (auto& x : a) cin >> x, cnt[x]++;

  sort(a.begin(), a.end());

  for (int x = 1; x <= n; ++x) {
    for (int j = x; j < min(n + 1, 4 * x); j += x) div[x] += cnt[j];
  }

  for (int x = n; x > 1; --x) {
    int pos = upper_bound(a.begin(), a.end(), 4 * x - 1) - a.begin();
    int num_large = pos != n ? n - pos : 0;
    if (n - (num_large + div[x]) <= k) return void(cout << x << '\n');
  }

  cout << 1 << '\n';
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