#include "bits/stdc++.h"
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  string name;
  cin >> n >> name;
  vector<int> a(n + 1);
  int wrong = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    wrong += (a[i] != i);
  }
  if (name == "Alice") {
    if (wrong <= 2)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  } else {
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
      int new_wrong = wrong;
      if (a[i] == i) new_wrong++;
      if (a[i + 1] == i + 1) new_wrong++;
      if (a[i + 1] == i) new_wrong--;
      if (a[i] == i + 1) new_wrong--;

      if (new_wrong > 2) {
        cout << "Bob\n";
        return;
      }
    }
    cout << "Alice\n";
  }
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
