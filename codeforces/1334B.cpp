/*
    Code by: KoKoDuDu
    Created: 2025.11.04 14:12:57
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

  vector<int> a(n);
  for (auto& x : a) cin >> x;

  sort(a.begin(), a.end());

  int sum = 0, cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] < k) break;
    sum += a[i], cnt++, a.pop_back();
  }

  if (cnt == 0) return void(cout << 0 << '\n');
  for (int i = a.size() - 1; i >= 0; --i) {
    if (sum + a[i] >= (cnt + 1) * k) {
      sum += a[i];
      cnt++;
    } else {
      break;
    }
  }

  cout << cnt << '\n';
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