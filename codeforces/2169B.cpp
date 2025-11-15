/*
    Code by: KoKoDuDu
    Created: 2025.11.14 22:12:06
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
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  string s;
  cin >> s;

  int n = s.size();
  if (n == 1) return void(cout << 1 << '\n');

  for (int i = 1; i < n; ++i) {
    if (s[i - 1] == '*' && s[i] == '*') return void(cout << -1 << '\n');
    if (s[i - 1] == '>' && s[i] == '<') return void(cout << -1 << '\n');
    if (s[i - 1] == '*' && s[i] == '<') return void(cout << -1 << '\n');
    if (s[i - 1] == '>' && s[i] == '*') return void(cout << -1 << '\n');
  }

  int pf = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '>') break;
    pf++;
  }

  int sf = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '<') break;
    sf++;
  }

  cout << max(pf, sf) << '\n';
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