/*
    Code by: KoKoDuDu
    Created: 2025.09.25 21:39:50
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  map<int, int> cnt;
  for (auto& c : a) {
    cin >> c;
    cnt[c]++;
  }

  sort(a.begin(), a.end());

  int change = 0;
  for (int i = 0; i < k; ++i) {
    change += cnt[i] == 0;
  }

  cout << max(change, cnt[k]) << '\n';
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