/*
    Code by: KoKoDuDu
    Created: 2025.10.02 00:36:15
*/

#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;
const int kMaxN = 2e7;

int f[kMaxN + 307];
int pf_count[kMaxN + 307];
int c, d, x;

void build() {
  for (int i = 2; i <= kMaxN; ++i) {
    f[i] = i;
  }

  for (int i = 2; i * i <= kMaxN; ++i) {
    if (f[i] != i) {
      continue;
    }

    for (int j = i * i; j <= kMaxN; j += i) {
      f[j] = (f[j] == j) ? i : f[j];
    }
  }

  pf_count[1] = 0;
  for (int i = 2; i <= kMaxN; i++) {
    int p = f[i];
    int x = i / p;
    pf_count[i] = pf_count[x] + (p != f[x]);
  }
}

int calc(int g) {
  int k = (x / g + d) / c;
  return pf_count[k];
};

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  build();

  int t = 1;
  cin >> t;

  while (t--) {
    cin >> c >> d >> x;

    int ans = 0;
    for (int i = 1; i * i <= x; ++i) {
      if (x % i == 0) {
        if ((x / i + d) % c == 0) {
          ans += 1LL << calc(i);
        }

        if (i * i != x && (i + d) % c == 0) {
          ans += 1LL << calc(x / i);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}