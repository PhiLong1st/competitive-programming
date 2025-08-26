/*
    Code by: KoKoDuDu
    Created: 2025.08.26 11:22:00
*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMod = 1e9 + 7;
const int kInf = 1e18;

void solve() {
  int num_cars, num_station, road_length, start_time;
  cin >> num_cars >> num_station >> road_length >> start_time;

  vector<array<int, 2>> cars(num_cars + 1);
  vector<int> stations(num_station + 1);

  for (int i = 1; i <= num_cars; ++i) {
    cin >> cars[i][0] >> cars[i][1];
  }

  for (int i = 1; i <= num_station; ++i) {
    cin >> stations[i];
  }

  stations.push_back(road_length);
  sort(stations.begin() + 1, stations.end());

  int l = 1, r = 1e9, min_fuel = -1;

  while (l <= r) {
    int mid = (l + r) >> 1;
    int total = 0;
    bool ok = true;
    for (int i = 1; i < stations.size(); ++i) {
      int dist = stations[i] - stations[i - 1];
      if (dist > mid) {
        ok = false;
        break;
      }
      total += 2 * dist - min(dist, mid - dist);
    }
    if (!ok || total > start_time) {
      l = mid + 1;
    } else {
      r = mid - 1;
      min_fuel = mid;
    }
  }

  int ans = kInf;
  if (min_fuel == -1) {
    cout << -1;
    return;
  }

  for (int i = 1; i <= num_cars; ++i) {
    if (cars[i][1] < min_fuel) {
      continue;
    }

    ans = min(ans, cars[i][0]);
  }

  cout << ((ans == kInf) ? -1 : ans);
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