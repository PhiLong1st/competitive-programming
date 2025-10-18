/*
    Code by: KoKoDuDu
    Created: 2025.10.17 19:05:53
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 998244353;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

vector<int> build_vt(vector<int>& a) {
  for (auto& c : a) cerr << c << ' ';
  return a;
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& c : a) cin >> c;

  vector<vector<int>> storage(31, vector<int>());
  for (int i = 0; i < n; ++i) {
    int c = a[i];

    for (int bit = 0; bit < 31; ++bit) {
      if (!(c & (1LL << bit))) continue;
      storage[bit].push_back(i);
    }
  }

  auto calc_sum_l_to_r = [&](int l, int r) -> int {
    return ((r * (r + 1) / 2) % kMod - ((l - 1) * l / 2) % kMod + kMod) % kMod;
  };

  int ans = 0;
  for (int bit = 0; bit < 31; ++bit) {
    if (storage[bit].empty()) continue;

    int sum = 0, cnt = 0;
    for (int i = 0; i < (int)storage[bit].size(); i += 2) {
      int nxt = i == storage[bit].size() - 1 ? n - 1 : storage[bit][i + 1] - 1;
      int prev = i == 0 ? 0 : storage[bit][i - 1] + 1;

      add_mod(sum, calc_sum_l_to_r(prev, storage[bit][i]));
      add_mod(cnt, storage[bit][i] - prev + 1);

      int sl = nxt - storage[bit][i] + 1;
      int temp = calc_sum_l_to_r(storage[bit][i], nxt) + sl;

      int s = (mul_mod(cnt, temp) - mul_mod(sum, sl) + kMod) % kMod;
      add_mod(ans, mul_mod(s, (1LL << bit) % kMod));
    }

    sum = 0, cnt = 0;
    for (int i = 1; i < (int)storage[bit].size(); i += 2) {
      int nxt = i == storage[bit].size() - 1 ? n - 1 : storage[bit][i + 1] - 1;
      int prev = i == 0 ? 0 : storage[bit][i - 1] + 1;

      add_mod(sum, calc_sum_l_to_r(prev, storage[bit][i]));
      add_mod(cnt, storage[bit][i] - prev + 1);

      int sl = nxt - storage[bit][i] + 1;
      int temp = calc_sum_l_to_r(storage[bit][i], nxt) + sl;

      int s = (mul_mod(cnt, temp) - mul_mod(sum, sl) + kMod) % kMod;
      add_mod(ans, mul_mod(s, (1LL << bit) % kMod));
    }
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