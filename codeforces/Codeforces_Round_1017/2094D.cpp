
/*
    Code by: KoKoDuDu
    Created: 2025.04.14 00:38:25
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  string x = "", y = "";
  vector<int> save_s, save_t;

  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') {
      int cnt = 0;
      x += 'R';
      while (i < n && s[i] == 'R') {
        i++;
        cnt++;
      }
      save_s.push_back(cnt);
      i--;
    } else {
      int cnt = 0;
      x += 'L';
      while (i < n && s[i] == 'L') {
        i++;
        cnt++;
      }
      save_s.push_back(cnt);
      i--;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (t[i] == 'R') {
      int cnt = 0;
      y += 'R';
      while (i < m && t[i] == 'R') {
        cnt++;
        i++;
      }
      save_t.push_back(cnt);
      i--;
    } else {
      int cnt = 0;
      y += 'L';
      while (i < m && t[i] == 'L') {
        cnt++;
        i++;
      }
      save_t.push_back(cnt);
      i--;
    }
  }

  if (x == y) {
    for (int i = 0; i < save_s.size(); ++i) {
      int u = save_s[i], v = save_t[i];
      if (u * 2 < v || u > v) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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