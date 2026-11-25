// /*
//  Code by: Algorillas
//  Created: 2026.09.27 19:58:48
// */

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define all(x) (x).begin(), (x).end()
// #define sz(x) ((int)(x).size())

// #ifdef ONLINE_JUDGE
// #define dbg(...)
// #else
// // #include "debug.h"
// #endif

// const int INF = 0x3f3f3f3f3f;
// const int MOD = 1e9 + 7;
// const int MAX_TURN = 200;
// const double EPS = 1e-6;
// void solve() {
//   double w, x1, x2, y, u, v;
//   cin >> w >> x1 >> x2 >> y >> u >> v;
//   double direct_time = w / v;
//   cout << fixed << setprecision(6);

//   // go ahead
//   {
//     double t = y / v;
//     double p = x1 + u * t;
//     double q = x2 + u * t;
//     if (q <= EPS || p >= -EPS) {
//       cout << direct_time << "\n";
//       return;
//     }
//   }

//   double res = 1e4;
//   // left
//   double l = 0, r = y / v;
//   for (int turn = 0; turn < MAX_TURN; turn++) {
//     double t = (l + r) / 2;
//     double s = t * v;
//     double x = x1 + t * u;
//     double sl = hypot(fabs(x), y);
//     if (s >= sl + EPS) {
//       res = min(res, t);
//       r = t;
//     }
//     // else if (fabs(u) > v + EPS) {
//     //   r = t;
//     // }
//     else {
//       l = t;
//     }
//   }

//   // right
//   l = 0, r = y / v;
//   for (int turn = 0; turn < MAX_TURN; turn++) {
//     double t = (l + r) / 2;
//     double s = t * v;
//     double x = x2 + t * u;
//     double sr = hypot(fabs(x), y);
//     if (s >= sr + EPS) {
//       res = min(res, t);
//       r = t;
//     }
//     // else if (fabs(u) > v + EPS) {
//     //   r = t;
//     // }
//     else {
//       l = t;
//     }
//   }
//   cout << res + (w - y) / v << "\n";
// }

// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(NULL);
//   cout.tie(NULL);
//   int t;
//   cin >> t;
//   while (t--) solve();
//   return 0;
// }

/*
 Code by: Algorillas
 Created: 2026.09.27 19:58:48
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#ifdef ONLINE_JUDGE
#define dbg(...)
#else
// #include "debug.h"
#endif

const int INF = 0x3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double MAX_TIME = 1e9;
const int MAX_TURN = 300;
const double EPS = 1e-9;
void solve() {
  double w, x1, x2, y, u, v;
  cin >> w >> x1 >> x2 >> y >> u >> v;
  double direct_time = w / v;
  cout << fixed << setprecision(6);

  // go ahead
  {
    double t = y / v;
    double p = x1 + u * t;
    double q = x2 + u * t;
    if (q <= EPS || p >= -EPS) {
      cout << direct_time << "\n";
      return;
    }
  }

  double res = MAX_TIME;
  // left
  double l = 0, r = MAX_TIME;
  for (int turn = 0; turn < MAX_TURN; turn++) {
    double t = (l + r) / 2;
    double s = t * v;
    double x = x1 + t * u;
    double sl = hypot(fabs(x), y);
    if (s >= sl + EPS) {
      res = min(res, t);
      r = t;
    } else if (fabs(u) > v + EPS) {
      r = t;
    } else {
      l = t;
    }
  }

  // right
  l = 0, r = MAX_TIME;
  for (int turn = 0; turn < MAX_TURN; turn++) {
    double t = (l + r) / 2;
    double s = t * v;
    double x = x2 + t * u;
    double sr = hypot(fabs(x), y);
    if (s >= sr + EPS) {
      res = min(res, t);
      r = t;
    } else if (fabs(u) > v + EPS) {
      r = t;
    } else {
      l = t;
    }
  }
  cout << res + (w - y) / v << "\n";
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