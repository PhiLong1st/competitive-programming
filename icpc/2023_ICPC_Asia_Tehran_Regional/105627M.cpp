/*
 Code by: KoKoDuDu
 Created: 2025.12.08 12:23:09
*/

#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second

using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int ceil_div(int a, int b) { return a >= 0 ? (a + b - 1) / b : a / b; }

int floor_div(int a, int b) { return a <= 0 ? (a - b + 1) / b : a / b; }

void add_mod(int& a, int b) { a = a + b >= kMod ? a + b - kMod : a + b; }

void minus_mod(int& a, int b) { a = (a - b + kMod) % kMod; }

void mul_mod(int& a, int b) { a = a * b % kMod; }

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

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

void solve() {
  int n;
  cin >> n;

  vector<string> a(n);
  for (string& s : a) cin >> s;

  map<string, int> color_mp;
  int color_cnt = 0;
  for (string& s : a) {
    if (color_mp.count(s)) continue;
    color_mp[s] = color_cnt++;
  }

  vector<int> b(n);
  for (int i = 0; i < n; ++i) b[i] = color_mp[a[i]];

  unordered_map<bitset<50>, int> min_len;
  for (int l = 0; l < n; ++l) {
    bitset<50> color;
    for (int r = l; r < n; ++r) {
      color[b[r]] = 1;
      int len = r - l + 1;
      min_len[color] = min_len.count(color) ? min(min_len[color], len) : len;
    }
  }

  bitset<50> full;
  for (int& x : b) full.set(x);

  vector<pair<bitset<50>, int>> intervals;
  for (auto& p : min_len) intervals.push_back(p);
  sort(intervals.begin(), intervals.end(),
       [&](pair<bitset<50>, int> a, pair<bitset<50>, int> b) -> bool {
         return a.second < b.second;
       });

  int ans = n;
  for (int i = 0; i < intervals.size(); ++i) {
    auto [color_x, len_x] = intervals[i];
    if (len_x >= ans / 2) break;
    if (color_x == full) {
      ans = min(ans, len_x);
      break;
    }
    for (int j = i + 1; j < intervals.size(); ++j) {
      auto [color_y, len_y] = intervals[j];
      if (len_x + len_y >= ans) break;
      if ((color_x | color_y) == full) ans = min(ans, len_x + len_y);
    }
  }
  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}
