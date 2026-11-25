/*
 Code by: Algorillas
 Created: 2026.11.24 15:57:34
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n, l, r;
  cin >> n >> l >> r;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  vector<int> save;
  for (int i = l; i <= r; ++i) save.push_back(a[i]);

  sort(save.begin(), save.end());

  int idL = l, idR = r;
  while (idL <= r && a[idL] == save[idL - l]) ++idL;
  while (idR >= l && a[idR] == save[idR - l]) --idR;

  cout << (idL > idR ? 0 : idR - idL + 1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}