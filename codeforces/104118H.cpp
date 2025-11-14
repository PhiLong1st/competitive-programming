/*
    Code by: KoKoDuDu
    Created: 2025.11.14 08:04:03
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

struct Item {
  int a, b, id;
};

void solve() {
  int n, x;
  cin >> n >> x;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<Item> arr(n);
  for (int i = 0; i < n; ++i) {
    arr[i].a = a[i];
    arr[i].b = b[i];
    arr[i].id = i;
  }

  auto cmp = [&](const Item& x, const Item& y) -> bool {
    if (x.a != y.a) return x.a < y.a;
    return x.id < y.id;
  };

  sort(arr.begin(), arr.end(), cmp);

  string ans(n, '0');
  int cur = 0;
  int can = 0;

  for (int i = 0; i < n; ++i) {
    auto [u, v, p] = arr[i];
    if (cur + u > x) break;
    cur += u;
    ++can;
    ans[p] = '1';
  }

  int rem = x - cur;
  priority_queue<pii, vector<pii>> pick;
  priority_queue<pii, vector<pii>, greater<pii>> diff, unpick;

  for (int i = 0; i < n; ++i) {
    if (ans[i] == '1') {
      diff.push({b[i] - a[i], i});
      pick.push({a[i], i});
    } else {
      unpick.push({b[i], i});
    }
  }

  auto norm = [&]() -> void {
    while (!diff.empty() && ans[diff.top().se] != '1') diff.pop();

    while (!pick.empty() && ans[pick.top().se] != '1') pick.pop();

    while (!unpick.empty() && ans[unpick.top().se] != '0') unpick.pop();
  };

  while (can) {
    norm();
    int cost1 = kMaxInf, cost2 = kMaxInf;

    if (!diff.empty()) cost1 = diff.top().fi;

    if (!pick.empty() && !unpick.empty())
      cost2 = unpick.top().fi - pick.top().fi;

    int best = min(cost1, cost2);
    if (best > rem) break;

    if (cost1 <= cost2) {
      norm();

      if (diff.empty()) continue;

      pii cur = diff.top();
      diff.pop();

      int id = cur.se;

      ans[id] = '2';
      rem -= cur.fi;
    } else {
      norm();

      if (pick.empty() || unpick.empty()) continue;

      pii picked = pick.top(), unpicked = unpick.top();
      pick.pop(), unpick.pop();

      int id_drop = picked.se;
      int id_take = unpicked.se;

      ans[id_drop] = '0', ans[id_take] = '2';
      rem -= unpicked.fi - picked.fi;

      unpick.push({b[id_drop], id_drop});
    }

    --can;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}