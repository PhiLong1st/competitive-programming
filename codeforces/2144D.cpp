/*
    Code by: KoKoDuDu
    Created: 2025.10.09 20:47:16
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxN = 2e5 + 0307;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

int c, maxx, total;
int pf[kMaxN];
unordered_map<int, int> cnt_tag;

void solve() {
  int n, y;
  cin >> n >> y;

  maxx = 0;
  total = 0;
  cnt_tag.clear();

  for (int i = 0; i < n; ++i) {
    cin >> c;
    cnt_tag[c]++;
    maxx = max(maxx, c + 1);
    total += c;
  }

  if (maxx == 2) return void(cout << total << '\n');

  for (int i = 0; i <= maxx; ++i) pf[i] = (i == 0 ? 0 : pf[i - 1]) + cnt_tag[i];

  int ans = kMinInf;
  for (int x = 2; x <= maxx; ++x) {
    int income = 0;
    for (int price = 1; price <= maxx; ++price) {
      int l = (price - 1) * x, r = min(maxx - 1, price * x);

      if (l >= maxx) break;

      int cnt = pf[r] - pf[l];
      income += cnt * price;
      income -= y * max(0LL, cnt - cnt_tag[price]);
    }

    ans = max(ans, income);
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