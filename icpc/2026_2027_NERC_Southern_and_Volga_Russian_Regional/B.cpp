#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26, 0);
  for (char c : s) cnt[c - 'a']++;
  if (*max_element(cnt.begin(), cnt.end()) == n) {
    int len = (n + k - 1) / k;
    for (int i = 1; i <= len; i++) {
      cout << s[0];
    }
  } else {
    sort(s.begin(), s.end());
    cout << s;
  }
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
  // cin >> t;
  while (t--) {
    solve();
  }
}