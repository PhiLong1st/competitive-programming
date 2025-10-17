/*
    Code by: KoKoDuDu
    Created: 2025.10.17 22:32:48
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

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

void solve() {
  int a, b;
  cin >> a >> b;

  auto difMask = [&](int a, int b, int bit) {
    int bitA = (a >> bit) & 1;
    int bitB = (b >> bit) & 1;
    return bitA != bitB;
  };

  int res = 0;

  int lastBit = 32 - __builtin_clz(max(a, b));

  vector<int> ans;

  for (int i = 0; i < lastBit; ++i) {
    if (difMask(a, b, i)) {
      if ((b >> i) & 1) {
        ans.push_back(!(a >> i & 1) << i);
      } else {
        ans.push_back(((a >> i & 1)) << i);
      }
    }
  }

  for (auto c : ans) {
    if (a < c) {
      cout << "-1\n";
      return;
    }
    a ^= c;
  }

  cout << ans.size() << '\n';
  for (auto& c : ans) cout << c << ' ';
  cout << '\n';
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