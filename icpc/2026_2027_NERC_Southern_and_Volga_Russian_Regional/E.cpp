/*
 Code by: Algorillas
 Created: 2026.11.25 11:29:04
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> g, m;

int simulate(int d) {
  vector<int> cur(1 << n);
  iota(cur.begin(), cur.end(), 0);

  int total = 0;
  while (cur.size() > 1) {
    vector<int> nxt;
    for (int i = 0; i < cur.size(); i += 2) {
      int x = cur[i], y = cur[i + 1];
      total += m[x] + m[y];

      int strong = (g[x] > g[y]) ? x : y;
      int weak = x + y - strong;

      int t = g[weak] + d > g[strong] ? weak : strong;
      nxt.push_back(t);
    }

    cur = nxt;
  }

  return total;
}

void solve() {
  cin >> n;

  g.assign(1 << n, 0), m.assign(1 << n, 0);
  for (int& c : g) cin >> c;
  for (int& c : m) cin >> c;

  vector<int> save;

  save.push_back(0);

  for (int i = 0; i < (1 << n); ++i)
    for (int j = i + 1; j < (1 << n); ++j) save.push_back(abs(g[i] - g[j]) + 1);

  sort(save.begin(), save.end());
  save.erase(unique(save.begin(), save.end()), save.end());

  int best = -1, bestD = -1;
  for (int d : save) {
    int total = simulate(d);
    if (total > best) best = total, bestD = d;
  }

  cout << best << " " << bestD;
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
  while (t--) solve();
}