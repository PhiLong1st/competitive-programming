/*
    Code by: KoKoDuDu
    Created: 2025.10.06 02:47:46
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

struct Segment_Tree {
  vector<int> st;
  int n;
  Segment_Tree() {}
  Segment_Tree(int n) {
    this->n = n;
    st.assign(4 * n + 37, 0);
  }
  void update(int id, int l, int r, int pos, int val) {
    int mid = (l + r) >> 1;
    if (l == r) {
      st[id] = max(st[id], val);
      return;
    }
    if (pos <= mid) {
      update(id * 2, l, mid, pos, val);
    } else {
      update(id * 2 + 1, mid + 1, r, pos, val);
    }
    st[id] = max(st[id * 2], st[id * 2 + 1]);
  }

  int get_max(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
      return 0;
    }
    if (u <= l && r <= v) {
      return st[id];
    }

    int mid = (l + r) >> 1;
    int s1 = get_max(id * 2, l, mid, u, v);
    int s2 = get_max(id * 2 + 1, mid + 1, r, u, v);
    return max(s1, s2);
  }
};

void solve() {
  int n;
  cin >> n;

  vector<int> a(n + 1), l(n + 1), dp(n + 1);
  vector<vector<int>> save(n + 1, vector<int>());
  stack<int> st;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];

    while (!st.empty() && a[st.top()] <= a[i]) st.pop();

    if (!st.empty()) {
      save[st.top()].push_back(i);
    }

    st.push(i);
  }

  Segment_Tree tree(n);

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[a[i]] = max(dp[a[i]], tree.get_max(1, 1, n, 1, a[i]) + 1);

    for (auto v : save[i]) {
      dp[a[v]] = max(dp[a[v]], tree.get_max(1, 1, n, 1, a[v]) + 2);
    }

    ans = max(ans, dp[a[i]]);
    tree.update(1, 1, n, a[i], dp[a[i]]);
  }

  cout << ans << '\n';
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