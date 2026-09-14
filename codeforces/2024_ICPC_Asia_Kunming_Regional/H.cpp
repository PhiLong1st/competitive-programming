#include "bits/stdc++.h"
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double PI = 3.1415926534;
const double EPS = 1e-6;

struct PA {
  int x, y;
  double angle;
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> p(n);
  for (auto& [x, y] : p) cin >> x >> y;

  vector<double> angle;

  auto calc_angle = [&](int x, int y) {
    if (x >= 0 && y >= 0) {
      return atan(1.0 * abs(x) / abs(y)) * 180 / PI;
    }
    if (x >= 0 && y <= 0) {
      return atan(1.0 * abs(y) / abs(x)) * 180 / PI + 90;
    }
    if (x <= 0 && y <= 0) {
      return atan(1.0 * abs(x) / abs(y)) * 180 / PI + 180;
    }
    return atan(1.0 * abs(y) / abs(x)) * 180 / PI + 270;
  };

  for (auto [x, y] : p) {
    angle.push_back(calc_angle(x, y));
    dbg(x, y, angle.back());
  }
  sort(all(angle));
  // for (auto [x, y, a] : angle) dbg(a);
  for (int i = 0; i < n; ++i) {
    angle.push_back(angle[i] + 360);
  }
  double ans = 0;
  for (int i = 0; i < 2 * n - k; ++i) {
    int nxt = i + k;
    ans = max(ans, angle[nxt] - angle[i]);
    dbg(angle[i], angle[nxt], i, nxt);
  }
  cout << fixed << setprecision(12) << ans / 180 * PI << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
