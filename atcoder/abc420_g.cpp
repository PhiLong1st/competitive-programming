/*
    Code by: KoKoDuDu
    Created: 2025.10.02 11:17:14
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int x;
  cin >> x;
  int c = 4 * x - 1;

  set<int> ans;

  auto add = [&](int d) { ans.insert((d - c / d - 2) / 4); };

  int d = -1;
  while (d * d <= abs(c)) {
    d += 2;

    if (c % d != 0) {
      continue;
    }

    add(d);
    add(-d);
    add(c / d);
    add(-c / d);
  }

  cout << ans.size() << '\n';
  for (auto &t : ans) {
    cout << t << ' ';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}