#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
  string s, c;
  cin >> s >> c;
  int len_s = sz(s);
  int len_c = sz(c);
  int len_a = (len_s + len_c) / 2;
  if (len_a < len_s - len_a) len_a++;
  for (int i = 0; i < len_a; i++) cout << s[i];
  cout << " ";
  for (int i = len_a; i < len_s; i++) cout << s[i];
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