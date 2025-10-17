/*
    Code by: KoKoDuDu
    Created: 2025.10.17 11:39:37
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

static inline int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& c : a) cin >> c;

  int d = 0;
  for (int i = 1; i < n; ++i) d = gcd(d, a[i] - a[0]);

  vector<int> pre(n);
  pre[0] = a[0];
  for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + a[i];

  for (int i = 0; i < n - 1; ++i) {
    cout << gcd(pre[i], d) << ' ';
  }

  int sum = accumulate(a.begin(), a.end(), 0LL);
  cout << sum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

/*
import sys
import math

def solve(tokens):
    it = iter(tokens)
    t = int(next(it))
    out_lines = []
    for _ in range(t):
        n = int(next(it))
        a = [int(next(it)) for _ in range(n)]

        # d = gcd of all differences a[i] - a[0]
        d = 0
        base = a[0]
        for i in range(1, n):
            d = math.gcd(d, a[i] - base)

        # prefix gcds and total sum
        res = []
        pref = 0
        for i in range(n - 1):
            pref += a[i]
            res.append(math.gcd(pref, d))

        total = sum(a)
        res.append(total)
        out_lines.append(" ".join(str(x) for x in res))
    return "\n".join(out_lines)

if __name__ == "__main__":
    data = sys.stdin.buffer.read().split()
    print(solve(data))
*/