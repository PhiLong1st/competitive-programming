/*
    Code by: KoKoDuDu
    Created: 2025.11.17 18:09:53
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
#define el '\n'

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

int add_mod(int a, int b) { return a + b >= kMod ? a + b - kMod : a + b; }

int minus_mod(int a, int b) { return (a - b + kMod) % kMod; }

int mul_mod(int a, int b) { return a * b % kMod; }

void maximize(int& x, int y) { x = max(x, y); }

void minimize(int& x, int y) { x = min(x, y); }

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, l, x, y;
  cin >> n >> m >> l >> x >> y;

  vector<int> st;
  vector<pii> bus(n + 1);
  for (int i = 1; i <= n; ++i) {
    int s, t;
    cin >> s >> t;
    st.push_back(s);
    bus[i] = {s, t};
  }

  sort(st.begin(), st.end());
  st.erase(unique(st.begin(), st.end()), st.end());

  unordered_map<int, int> time;
  for (auto& [s, t] : bus) {
    int id = lower_bound(st.begin(), st.end(), s) - st.begin();
    int cost = (t - s) * y + (l - t) * x;
    if (time.count(id)) {
      minimize(time[id], cost);
    } else {
      time[id] = cost;
    }
  }

  vector<vector<int>> spt((int)st.size(), vector<int>(20, kMaxInf));
  for (int i = 0; i < st.size(); ++i) spt[i][0] = time[i];
  for (int bit = 1; bit < 20; ++bit) {
    for (int i = 0; i + (1 << bit) <= st.size(); ++i)
      spt[i][bit] = min(spt[i][bit - 1], spt[i + (1 << (bit - 1))][bit - 1]);
  }

  auto get = [&](int l, int r) -> int {
    if (l > r) return kMaxInf;
    int lg = log2(r - l + 1);
    return min(spt[l][lg], spt[r - (1 << lg) + 1][lg]);
  };

  cout << fixed << setprecision(12);
  while (m--) {
    int p;
    cin >> p;
    int pos = upper_bound(st.begin(), st.end(), p) - st.begin() - 1;
    ldb cost = get(0, pos) / (ldb)(x * y);
    cout << min(cost, (ldb)(l - p) / (ldb)y) << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}