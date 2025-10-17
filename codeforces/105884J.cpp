/*
    Code by: KoKoDuDu
    Created: 2025.10.17 17:11:40
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int kMod = 998244353;
const int kMaxN = 300000;

static inline void add_mod(int& a, int b) {
  a += b;
  if (a >= kMod) a -= kMod;
}
static inline int mul_mod(int a, int b) {
  return (a % kMod) * (b % kMod) % kMod;
}

int least_prime[kMaxN + 37];
bool vst[kMaxN + 37];
int a[kMaxN], cnt[kMaxN];
int n, k;

struct Combinatorics {
  int N;
  vector<int> fact, inv, finv;

  Combinatorics(int N) : N(N), fact(N + 1), inv(N + 1), finv(N + 1) {
    inv[1] = 1;
    for (int i = 2; i <= N; ++i)
      inv[i] = kMod - (kMod / i) * inv[kMod % i] % kMod;

    fact[0] = finv[0] = 1;
    for (int i = 1; i <= N; ++i) {
      fact[i] = fact[i - 1] * i % kMod;
      finv[i] = finv[i - 1] * inv[i] % kMod;
    }
  }

  int C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact[n] * 1LL * finv[k] % kMod * finv[n - k] % kMod;
  }
};

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 2; i <= kMaxN; ++i) least_prime[i] = i;
  for (int i = 2; i * i <= kMaxN; ++i) {
    if (least_prime[i] != i) continue;
    for (int j = i * i; j <= kMaxN; j += i) least_prime[j] = i;
  }

  Combinatorics comb(kMaxN);
  vector<int> primes;

  int t = 1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
      int temp = a[i];

      unordered_set<int> st;
      while (temp != 1) {
        int p = least_prime[temp];
        st.insert(p);
        temp /= p;
      }

      for (auto& p : st) {
        cnt[p]++;
        if (!vst[p]) {
          primes.push_back(p);
          vst[p] = true;
        }
      }
    }

    int total = comb.C(n, k);
    int ans = 0;

    for (int p : primes) {
      int cp = cnt[p];
      if (cp == 0) continue;
      int term = total - comb.C(n - cp, k);
      if (term < 0) term += kMod;
      add_mod(ans, mul_mod(p, term));
    }

    cout << ans << '\n';

    for (int p : primes) {
      cnt[p] = 0;
      vst[p] = false;
    }
    primes.clear();
  }
  return 0;
}