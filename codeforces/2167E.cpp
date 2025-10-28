/*
    Code by: KoKoDuDu
    Created: 2025.10.28 22:49:28
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
const int kMaxInf = 1e12;
const int kMinInf = -1e12;

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

pii mp(int a, int b) { return make_pair(a, b); }

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    int n, k, x;
    cin >> n >> k >> x;

    unordered_map<int, int> check;
    priority_queue<pii> pq;

    vector<int> a(n);
    for (auto& c : a) cin >> c;

    sort(a.begin(), a.end());

    for (int i = 1; i < a.size(); ++i) {
      int mid = (a[i] + a[i - 1]) / 2;
      if (check.count(mid)) continue;

      pq.push(mp(min(abs(a[i] - mid), abs(a[i - 1] - mid)), mid));
      check[mid] = true;
    }

    vector<int> important_pts = {0, x};
    for (auto& pt : important_pts) {
      if (!check.count(pt)) {
        pq.push(mp(min(abs(a.back() - pt), abs(a.front() - pt)), pt));
        check[pt] = true;
      }
    }
    
    a.insert(a.begin(), -kMaxInf);
    a.push_back(kMaxInf);

    vector<int> pts;
    while (pts.size() < k) {
      auto [d, v] = pq.top();
      pq.pop();

      pts.push_back(v);
      int next_v = v + 1;
      int prev_v = v - 1;

      for (int difV = -1; difV <= 1; difV += 2) {
        int check_v = v + difV;
        if (!check.count(check_v) && check_v >= 0 && check_v <= x) {
          check[check_v] = true;
          int nxt = lower_bound(a.begin(), a.end(), check_v) - a.begin();
          int prv = lower_bound(a.begin(), a.end(), check_v) - a.begin() - 1;

          pq.push({min(abs(a[nxt] - check_v), abs(a[prv] - check_v)), check_v});
        }
      }
    }

    for (auto& p : pts) cout << p << ' ';
    cout << '\n';
  }
  return 0;
}