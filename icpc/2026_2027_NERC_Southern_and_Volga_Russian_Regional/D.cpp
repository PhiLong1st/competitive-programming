/*
 Code by: Algorillas
 Created: 2026.11.25 11:28:57
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

  vector<int> a(n + 1, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int l = 0, r = 1e9, ans = -1;
  while (l <= r) {
    int mid = (l + r) / 2;

    bool isOk = true;
    int cntS0 = 0, cntS1 = 0;
    int cntD = 0;

    for (int i = 0; i < n; ++i) {
      cntS0 = cntS1, cntS1 = 0;
      
      int hasE = mid;
      int needS = max(0ll, a[i] - cntS0);
      
      int useE = min(needS, hasE);
      hasE -= useE;

      int needD = needS - useE;

      if (needD > cntD) {
        isOk = false;
        break;
      }

      cntD -= needD;

      cntS1 = min(hasE, a[i + 1]);

      if ((hasE - cntS1) % 2 && cntS1 > 0) --cntS1;

      hasE -= cntS1;
      cntD += hasE / 2;
    }

    if (isOk) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  if (fopen("in.txt", "r")) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }

  int t = 1;
  while (t--) solve();
}