/*
    Code by: KoKoDuDu
    Created: 2025.10.28 09:16:35
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
const int kMaxBit = 60;
const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), cnt(kMaxBit + 1);
  for (auto& x : a) cin >> x, cnt[(int)log2(x)]++;

  int sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum < n) return void(cout << -1 << '\n');

  int ans = 0;
  for (int bit = 0; bit < kMaxBit; ++bit) {
    if ((n & (1LL << bit))) {
      if (cnt[bit] > 0) {
        cnt[bit]--;
      } else {
        while (bit < kMaxBit && cnt[bit] == 0) {
          bit++;
          ans++;
        }
        cnt[bit]--;
        bit--;
      }
    }
    cnt[bit + 1] += cnt[bit] / 2;
  }
  cout << ans << '\n';
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