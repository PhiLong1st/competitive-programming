#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  int n;
  cin >> n;

  vector<array<string, 2>> s(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; j++) {
      cin >> s[i][j];
      s[i][j] += j + '0';
    }
  }

  unordered_map<string, int> mp;
  for (int i = 0; i < n; ++i) {
    mp[s[i][0]]++;
    mp[s[i][1]]++;
    // cerr << s[i][0] << ' ' << s[i][1] << '\n';
  }

  for (int i = 0; i < n - 1; ++i) {
    bool isOk = s[i][0] == s[i + 1][0] || s[i][0] == s[i + 1][1] ||
                s[i][1] == s[i + 1][0] || s[i][1] == s[i + 1][1];
    if (isOk) {
      mp[s[i][0]]--;
      mp[s[i][1]]--;
      continue;
    }

    if (mp[s[i][0]] > 1 || mp[s[i][1]] > 1) return void(cout << "No\n");

    mp[s[i][0]]--;
    mp[s[i][1]]--;
  }

  cout << "Yes\n";
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
  cin >> t;
  while (t--) {
    solve();
  }
}