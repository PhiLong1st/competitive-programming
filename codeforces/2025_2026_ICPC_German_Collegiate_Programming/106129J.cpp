/*
 Code by: Algorillas
 Created: 2026.09.05 19:39:08
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

// 0 0 -> 2 0
// 0 1 -> 1 2
// 1 0 -> 2 1
// 1 1 -> 2 2

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;

void solve() {
  string message, type;
  cin >> type;
  int n;
  cin >> n >> message;
  if (type == "Encode") {
    if (n == 1) {
      cout << message << '\n';
      return;
    }

    message[0] = message[0] - '0' + 1 + '0';
    message[1] = message[1] - '0' + 1 + '0';
    cout << message;
  } else {
    for (int i = 0; i < sz(message); ++i) {
      if (message[i] == '2') {
        message = message.substr(i, sz(message) - i) + message.substr(0, i);
        break;
      }
    }
    cout << message;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  // int t;
  // cin >> t;
  // while (t--)
  solve();
  return 0;
}