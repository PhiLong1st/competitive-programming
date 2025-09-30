/*
    Code by: KoKoDuDu
    Created: 2025.09.30 20:31:20
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

pair<int, int> normalize(pair<int, int> x) {
  int gcd = __gcd(x.first, x.second);
  x.first /= gcd;
  x.second /= gcd;
  return {x.first, x.second};
}

void solve() {
  int n;
  string s;
  cin >> n >> s;

  map<pair<int, int>, int> mp;
  int cnt_d = 0;
  for (int i = 0; i < n; ++i) {
    cnt_d += s[i] == 'D';
    mp[normalize({cnt_d, i + 1})]++;
    cout << mp[normalize({cnt_d, i + 1})] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}