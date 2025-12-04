
/*
    Code by: KoKoDuDu
    Created: 2025.04.13 22:43:19
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), cnt(30);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    for (int bit = 0; bit < 30; ++bit) {
      cnt[bit] += ((1 << bit) & a[i]) != 0;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = 0;
    for (int bit = 0; bit < 30; ++bit) {
      if (((1 << bit) & a[i])) {
        tmp += (1 << bit) * (n - cnt[bit]);
      } else {
        tmp += (1 << bit) * cnt[bit];
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}