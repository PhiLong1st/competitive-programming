/*
    Code by: KoKoDuDu
    Created: 2025.10.19 10:23:35
*/

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxInf = numeric_limits<int>::max();
const int kMinInf = numeric_limits<int>::min();

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

static inline int cdiv(int a, int b) {
  return a >= 0 ? (a + b - 1) / b : a / b;
}

static inline int fdiv(int a, int b) {
  return a <= 0 ? (a - b + 1) / b : a / b;
}

static inline void add_mod(int& a, int b) {
  a = a + b;
  if (a >= kMod) a -= kMod;
}

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

int n;
char s, t;

unordered_map<int, int> mp, check_par;
vector<vector<int>> adj(1000, vector<int>());

int res = 0;

void dfs(int x, int par, int cost, int end) {
  if (x == end) {
    res = cost;
    return;
  }
  for (auto v : adj[x]) {
    if (x == par) continue;

    dfs(v, x, cost + 1, end);
  }
}

void solve() {
  cin >> n;
  cin.ignore();

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);

    int cnt_indent = 0;
    char node;
    for (auto& c : s) {
      cnt_indent += c == ' ';
      if (c != ' ') node = c;
    }

    mp[cnt_indent] = node - 'A';
    if (cnt_indent == 0) continue;

    int par = mp[cnt_indent - 1];
    adj[par].push_back(node - 'A');
    check_par[node - 'A'] = par;
    // dbg(node - 'A', par);
  }

  cin >> s >> t;
  if (s == t) return void(cout << s << " is same as " << t);
  if (check_par[s - 'A'] == check_par[t - 'A'])
    return void(cout << s << " is sibling of " << t);

  vector<int> dist(1000);

  dfs(s - 'A', -1, 0, t - 'A');
  if (res != 0) {
    if (res == 1) return void(cout << s << " is parent of " << t);
    if (res == 2) return void(cout << s << " is grand of " << t);
    return void(cout << s << " is " << res << " level ancestor of " << t);
  }

  dfs(t - 'A', -1, 0, s - 'A');
  if (res != 0) {
    if (res == 1) return void(cout << s << " is child of " << t);
    if (res == 2) return void(cout << s << " is grandchild of " << t);
    return void(cout << s << " is " << res << " level descendant of " << t);
  }

  // dfs2(s - 'A', -1, 0);
  // if (cost2 != 0) {
  //   if (cost2 == 1) return void(cout << s << " is sibling of " << t);
  //   if (cost2 == 2) return void(cout << s << " is grandchild of " << t);
  //   return void(cout << s << " is" << cost2 << "level descendant  of " << t);
  // }

  cout << s << " has no relationship with " << t;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}