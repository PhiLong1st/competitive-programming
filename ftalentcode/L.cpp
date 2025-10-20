/*
    Code by: KoKoDuDu
    Created: 2025.10.19 08:45:15
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

void solve() {
  int n, q;
  cin >> n >> q;

  vector<string> a(n);
  unordered_map<string, int> mp;
  for (auto& s : a) cin >> s;

  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    mp[a[i]] = i + 1;
  }

  while (q--) {
    string x;
    cin >> x;
    cout << ((mp.count(x)) ? mp[x] : -1) << '\n';
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