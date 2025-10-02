/*
    Code by: KoKoDuDu
    Created: 2025.10.03 00:43:40
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void permute(vector<int>& arr, vector<int>& P) {
  vector<int> temp(arr.size());

  for (int i = 1; i < arr.size(); i++) {
    temp[i] = arr[P[i]];
  }

  for (int i = 1; i < arr.size(); i++) arr[i] = temp[i];
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> arr(n + 1), p;
  iota(arr.begin(), arr.end(), 0);

  p.push_back(0);
  for (int i = 1; i <= n; i += 2) {
    p.push_back(i);
  }

  for (int i = 2; i <= n; i += 2) {
    p.push_back(i);
  }

  while (k) {
    if (k & 1) {
      permute(arr, p);
    }

    permute(p, p);
    k >>= 1;
  }

  for (int i = 1; i <= n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}