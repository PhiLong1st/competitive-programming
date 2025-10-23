/*
    Code by: KoKoDuDu
    Created: 2025.10.21 19:57:51
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

struct mint {
  int a;
  mint(int x = 0) : a(x % kMod) {}
  mint operator+(const mint& other) const { return mint((a + other.a) % kMod); }
  mint operator-(const mint& other) const {
    return mint((a - other.a + kMod) % kMod);
  }
  mint operator*(const mint& other) const { return mint((a * other.a) % kMod); }
  mint& operator+=(const mint& other) {
    a = (a + other.a) % kMod;
    return *this;
  }
  mint& operator-=(const mint& other) {
    a = (a - other.a + kMod) % kMod;
    return *this;
  }
  mint& operator*=(const mint& other) {
    a = (a * other.a) % kMod;
    return *this;
  }
  mint operator/(const mint& other) const { return (*this) * fpow(kMod - 2); }
  mint& operator/=(const mint& other) {
    (*this) = (*this) * (*this).fpow(kMod - 2);
    return *this;
  }
  mint operator%(const int& m) const { return mint(a % m); }
  mint& operator%=(const int& m) {
    a = a % m;
    return *this;
  }
  mint operator^(const int& e) const { return fpow(e); }
  mint& operator^=(const int& e) {
    (*this) = (*this).fpow(e);
    return *this;
  }
  mint operator-() const { return mint(kMod - a); }
  mint& operator++() {
    a = (a + 1) % kMod;
    return *this;
  }
  mint& operator--() {
    a = (a - 1 + kMod) % kMod;
    return *this;
  }
  bool operator>(const mint& other) const { return a > other.a; }
  bool operator<(const mint& other) const { return a < other.a; }
  bool operator==(const mint& other) const { return a == other.a; }
  bool operator>=(const mint& other) const { return a >= other.a; }
  bool operator<=(const mint& other) const { return a <= other.a; }
  mint fpow(int exp) const {
    mint result = 1;
    mint base = *this;
    while (exp > 0) {
      if (exp % 2 == 1) result *= base;
      base *= base;
      exp /= 2;
    }
    return result;
  }
  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.a;
    return os;
  }
  friend istream& operator>>(istream& is, mint& m) {
    is >> m.a;
    m.a %= kMod;
    return is;
  }
};

static inline int mul_mod(int a, int b) {
  a = a * b % kMod;
  return a;
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> adj(n + 1, vector<int>());
  vector<int> num_child(n + 1, 1);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (k == 1) return void(cout << 1 << '\n');

  auto dfs = [&](auto&& dfs, int u, int p) -> void {
    for (auto v : adj[u]) {
      if (v == p) continue;

      dfs(dfs, v, u);
      num_child[u] += num_child[v];
    }
  };

  dfs(dfs, 1, -1);

  mint ans = 0;

  auto calc_2 = [&](auto&& calc, int u, int p) -> void {
    vector<mint> nums;
    int num_par = n - num_child[u];
    nums.push_back(num_par);

    for (auto v : adj[u]) {
      if (v == p) continue;
      nums.push_back(num_child[v]);
    }

    mint total = 0;
    for (int i = 0; i < nums.size(); ++i) total += nums[i];

    for (int i = 0; i < nums.size(); ++i) {
      total -= nums[i];
      ans += nums[i] * total;
    }

    ans += n - 1;
    for (auto v : adj[u]) {
      if (v == p) continue;
      calc(calc, v, u);
    }
  };

  if (k == 2) {
    calc_2(calc_2, 1, -1);
    ans = ans * mint(n * (n - 1) / 2).fpow(kMod - 2);
    cout << ans;
    return;
  }

  cout << 1 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  while (t--) solve();
  return 0;
}