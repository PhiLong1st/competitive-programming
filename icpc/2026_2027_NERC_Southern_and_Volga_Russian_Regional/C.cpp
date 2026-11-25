/*
 Code by: Algorillas
 Created: 2026.11.25 10:53:16
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
  if (a < b) swap(a, b);
  return b == 0 ? a : gcd(b, a % b);
}

struct DSU {
  int n, numEdge;
  vector<int> par, num;
  
  DSU(int sz) {
    n = sz;
    numEdge = 0;
    par.assign(n + 1, 0);
    num.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) par[i] = i;
  }

  int findPar(int x) {
    if (x == par[x]) return x;
    return par[x] = findPar(par[x]);
  }

  bool join(int x, int y) {
    x = findPar(x), y = findPar(y);

    if (x == y) return false;

    if (num[x] < num[y]) {
      num[y] += num[x];
      par[x] = y;
    } else {
      num[x] += num[y];
      par[y] = x;
    }

    numEdge++;
    return true;
  }
};

void solve(int& n, int& m, string& resN, string& resM) {
  if (m % n == 0) {
    for (int i = 1; i <= n; ++i) resN += "a";

    for (int i = 1; i < m; ++i) resM += "a";
    resM += "b";

    return;
  }

  int g = gcd(n, m);
  int len = n + m - g - 1;

  DSU dsu(n + m);
  for (int k = 0; k < len; ++k) dsu.join(k % n + 1, n + k % m + 1);

  int bad = dsu.findPar(n + len % m + 1);
  for (int i = 0; i < n; ++i) resN += dsu.findPar(i + 1) == bad ? "b" : "a";
  for (int i = 0; i < m; ++i) resM += dsu.findPar(n + i + 1) == bad ? "b" : "a";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  string resN = "", resM = "";

  if (n > m) {
    solve(m, n, resM, resN);
  } else {
    solve(n, m, resN, resM);
  }

  cout << resN << '\n' << resM << '\n';
}