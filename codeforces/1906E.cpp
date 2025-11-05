/*
    Code by: KoKoDuDu
    Created: 2025.11.05 23:28:57
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define cd complex<double>
#define fi first
#define se second
using namespace std;

const double PI = acos(-1);
const int kMaxN = 2e5 + 0307;
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
  vector<int> a(2 * n + 1);
  set<int> s;

  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }

  vector<vector<int>> range;
  vector<int> cur;

  vector<int> node;
  for (int i = 2 * n; i >= 1; i--) {
    cur.push_back(a[i]);
    if (a[i] == *s.rbegin()) {
      reverse(cur.begin(), cur.end());
      node.push_back(cur.size());
      range.push_back(cur);
      cur.clear();
    }
    s.erase(a[i]);
  }

  reverse(node.begin(), node.end());
  reverse(range.begin(), range.end());

  int need_sum = n;
  vector<vector<int>> dp(node.size(), vector<int>(2 * need_sum + 1, 0));
  vector<vector<int>> trace(node.size(), vector<int>(2 * need_sum + 1, -1));
  
  dp[0][0] = dp[0][node[0]] = 1;
  trace[0][node[0]] = 0;

  for (int i = 1; i < node.size(); i++) {
    int value = node[i];
    for (int sum = need_sum; sum >= 0; sum--) {
      dp[i][sum] = dp[i - 1][sum];
      trace[i][sum] = trace[i - 1][sum];

      if (sum >= value && dp[i - 1][sum - value]) {
        dp[i][sum] = 1;
        trace[i][sum] = i;
      }
    }
  }

  if (!dp[node.size() - 1][need_sum]) {
    cout << -1;
    return;
  }

  vector<int> res;
  int cur_sum = need_sum;
  int j = node.size() - 1;

  while (cur_sum > 0 && j >= 0) {
    if (trace[j][cur_sum] == j) {
      res.push_back(j);
      cur_sum -= node[j];
      j--;
    } else {
      j = trace[j][cur_sum];
    }
  }

  reverse(res.begin(), res.end());
  unordered_set<int> us;
  for (int cc : res) us.insert(cc);

  vector<int> other;
  for (int i = 0; i < node.size(); i++) {
    if (us.count(i)) continue;
    other.push_back(i);
  }

  for (int id_node : res)
    for (int u : range[id_node]) cout << u << " ";
  cout << "\n";

  for (int id_node : other)
    for (int u : range[id_node]) cout << u << " ";
  cout << "\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}