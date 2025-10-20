/*
    Code by: KoKoDuDu
    Created: 2025.10.19 08:34:01
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
  int n;
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 2; ++j) {
      cin >> a[i][j];
    }
  }

  // for (int i = 1; i <= 2; ++i) {
  //   for (int j = 1; j <= 2; ++j) {
  //     dbg(i, j, a[i][j]);
  //   }
  // }

  if (a[1][1] < min(a[2][1], a[1][2]) && max(a[1][2], a[2][1]) < a[2][2])
    return void(cout << "YES\n");

  if (a[2][1] < min(a[1][1], a[2][2]) && max(a[1][1], a[2][2]) < a[1][2])
    return void(cout << "YES\n");

  if (a[2][2] < min(a[1][2], a[2][1]) && max(a[1][2], a[2][1]) < a[1][1])
    return void(cout << "YES\n");

  if (a[1][2] < min(a[2][2], a[1][1]) && max(a[2][2], a[1][1]) < a[2][1])
    return void(cout << "YES\n");

  cout << "NO\n";
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