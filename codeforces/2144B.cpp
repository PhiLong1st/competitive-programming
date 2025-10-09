/*
    Code by: KoKoDuDu
    Created: 2025.10.09 18:29:40
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

void solve() {
  int n;
  cin >> n;

  vector<int> a(n), check(n + 1);
  stack<int> st;
  for (auto& c : a) {
    cin >> c;
    check[c] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (check[i] == 1) continue;

    st.push(i);
  }

  for (auto& c : a) {
    if (c != 0) continue;

    c = st.top();
    st.pop();
  }

  int l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i - 1] != i) {
      l = i;
      break;
    }
  }

  if (l == 0) return void(cout << 0 << '\n');

  for (int i = n; i >= 1; --i) {
    if (a[i - 1] != i) {
      r = i;
      break;
    }
  }

  cout << r - l + 1 << '\n';
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