/*
    Code by: KoKoDuDu
    Created: 2025.09.27 19:00:46
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1);
  map<int, int> cnt;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] != -1 && cnt[a[i]] != 0) {
      cout << "No";
      return;
    }
    cnt[a[i]] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (a[i] == -1) {
      for (int j = 1; j <= n; ++j) {
        if (cnt[j] == 0) {
          cnt[j] = 1;
          a[i] = j;
          break;
        }
      }
    }
  }

  cout << "Yes\n";
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << ' ';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}