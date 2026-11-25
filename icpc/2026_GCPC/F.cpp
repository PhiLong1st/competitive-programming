/*
 Code by: Algorillas
 Created: 2026.11.09 20:38:39
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;

  map<string, int> mp, cnt;
  bool isOk = true;

  for (int i = 0; i < n; ++i) {
    string x, y;
    cin >> x >> y;

    if (x == "pickup") {
      mp[y]++;
      cnt[y]++;
      if (cnt[y] > 1) {
        isOk = false;
      }
    } else {
      if (mp[y] == 0) {
        isOk = false;
      } else {
        mp[y]--;
      }
    }
  }

  for (auto& [_, y] : mp) {
    if (y != 0) isOk = false;
  }

  cout << (isOk ? "yes" : "no");
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}