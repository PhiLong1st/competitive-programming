/*
    Code by: KoKoDuDu
    Created: 2025.10.03 21:37:02
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  set<int> st;
  for (auto &c : a) {
    cin >> c;
    st.insert(c);
  }

  cout << 2 * st.size() - 1 << '\n';
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