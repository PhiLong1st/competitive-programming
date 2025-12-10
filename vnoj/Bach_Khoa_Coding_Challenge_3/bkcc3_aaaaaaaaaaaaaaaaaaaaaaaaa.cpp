/*
 Code by: kokodudu
 Created: 2025.12.10 21:58:40
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
const int kMaxVal = 1e6;
const int kMod = 1e9 + 7;
const int kMaxBit = 60;
const int kMaxInf = 1e18;
const int kMinInf = -1e18;

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % kMod;
    a = a * a % kMod;
    b >>= 1;
  }
  return res;
}

int spf[kMaxVal + 37];

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x : a) cin >> x;

  map<int, int> mp;
  int num = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x != 1) {
      int p = spf[x];

      if (!mp.count(p)) {
        num += (i + 1) * (n - i);
        mp[p] = i;
      }

      if (mp[p] != i) {
        num += (i - mp[p]) * (n - i);
        mp[p] = i;
      }

      x /= p;
    }
  }

  int dem = n * (n + 1) / 2;
  cout << fpow(2, (num - dem)) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 2; i <= kMaxVal; ++i) spf[i] = i;
  for (int i = 2; i * i <= kMaxVal; ++i) {
    if (spf[i] != i) continue;
    for (int j = i * i; j <= kMaxVal; j += i) spf[j] = i;
  }

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}