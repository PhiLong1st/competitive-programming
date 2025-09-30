/*
    Code by: KoKoDuDu
    Created: 2025.09.30 11:42:52
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;
const int maxN = 2e5 + 1;

int N, perm[maxN];
bool vis[maxN], is_prime[maxN];
vector<int> primes;
map<int, int> ans;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

static inline int lcm_mod(int x, int y) {
  int g = gcd(x, y);
  __int128 t = (__int128)((x / g) % kMod) * (y % kMod);
  return (int)(t % kMod);
}

void init_primes() {
  for (int i = 2; i < maxN; i++) {
    is_prime[i] = true;
  }

  for (int i = 2; i < maxN; i++) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j < maxN; j += i) is_prime[j] = false;
    }
  }
}

void prime_factor(int x) {
  for (int i = 0; i < (int)primes.size() && primes[i] <= x; i++) {
    int p = primes[i];
    int num_divisions = 0;
    while (x % p == 0) {
      x /= p;
      num_divisions++;
    }

    if (num_divisions > 0) ans[p] = max(ans[p], num_divisions);
  }
}

void solve() {
  int n;
  cin >> n;
  init_primes();
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<char> vis(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;

    int cnt = 0;
    int u = i;
    do {
      if (vis[u]) {
        break;
      }
      vis[u] = 1;
      u = a[u];
      ++cnt;
    } while (true);

    prime_factor(cnt);
  }

  int prod = 1;
  for (auto [prime, power] : ans) {
    for (int i = 0; i < power; i++) {
      prod = (prod * prime) % kMod;
    }
  }
  cout << prod;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) {
    solve();
  }

  return 0;
}