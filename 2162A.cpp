/*
    Code by: KoKoDuDu
    Created: 2025.10.17 22:17:28
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& c : a) cin >> c;
  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans = max(ans, (pref[j + 1] - pref[i]) / (j - i + 1));
    }
  }
  cout << ans << '\n';
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