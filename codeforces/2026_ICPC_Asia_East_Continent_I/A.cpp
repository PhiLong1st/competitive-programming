/*
 Code by: Algorillas
 Created: 2026.09.14 19:40:28
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<pair<char, int>> queries(n);
  for (int i = 0; i < n; i++) cin >> queries[i].first >> queries[i].second;
  unordered_map<int, char> tmp_char;
  vector<char> next(n, 'x');
  for (int i = n - 1; i >= 0; i--) {
    auto& [op, v] = queries[i];
    if (tmp_char.count(v)) {
      next[i] = tmp_char[v];
    }
    tmp_char[v] = op;
  }
  // for (int i = 0; i < n; i++) cout << next[i] << " ";
  // cout << "\n";
  stack<int> st;
  unordered_set<int> keep;
  for (int i = 0; i < n; i++) {
    auto& [op, v] = queries[i];
    if (op == '+') {
      cout << '+';
      if (next[i] == 'T') {
        keep.insert(v);
        st.push(v);
      } else {
        cout << "-";
      }
    } else if (op == 'F') {
      cout << '?';
      while (!st.empty() && !keep.count(st.top())) {
        cout << "-";
        st.pop();
      }
    } else {
      cout << '?';
      if (next[i] != 'T') keep.erase(v);
      while (!st.empty() && !keep.count(st.top())) {
        cout << "-";
        st.pop();
      }
    }
  }
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}