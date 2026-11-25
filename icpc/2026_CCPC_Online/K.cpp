#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e15;
const int MOD = 998244353;

int fpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

void solve() {
  int n, m, s;
  cin >> n >> m >> s;

  vector<int> signal(n + 1);
  vector<int> sz(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    signal[i] = c - '0';
  }

  vector<vector<pair<int, int>>> adj(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    if (u == s) continue;
    sz[u]++;
    adj[v].push_back({u, w});
  }

  vector<int> dist(n + 1, INF), cnt(n + 1, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  dist[s] = 0;
  cnt[s] = 1;
  pq.push({dist[s], s});

  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();

    if (du != dist[u]) continue;
    for (auto [v, w] : adj[u]) {
      if (dist[v] > dist[u] + w) {
        cnt[v] = cnt[u];
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      } else if (dist[v] == dist[u] + w) {
        cnt[v] += cnt[u];
        cnt[v] %= MOD;
      }
    }
  }

  vector<int> res(n + 1), deg(n + 1, 0);

  for (int u = 1; u <= n; u++) {
    for (auto [v, w] : adj[u]) {
      deg[v]++;
    }
  }
  res[s] = 0;

  queue<int> q;
  for (int u = 1; u <= n; u++) {
    if (deg[u] == 0) q.push(u);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto [v, w] : adj[u]) {
      if (signal[v] == 0) {
        if (sz[v] == 0) continue;
        int cost = fpow(sz[v], MOD - 2);
        int newVal = cost * ((w + res[u]) % MOD) % MOD;

        res[v] = (res[v] + newVal) % MOD;

      } else if (dist[u] + w == dist[v]) {
        if (cnt[v] == 0) continue;
        int cost = cnt[u] * fpow(cnt[v], MOD - 2) % MOD;

        int newVal = cost * ((w + res[u]) % MOD) % MOD;

        res[v] = (res[v] + newVal) % MOD;
      }
      if (--deg[v] == 0) q.push(v);
    }
  }

  for (int u = 1; u <= n; u++) cout << res[u] << ' ';
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t-- > 0) solve();
}
