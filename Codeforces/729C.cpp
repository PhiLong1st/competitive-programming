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
  int num_cars, num_stops, road_length, start_time;
  cin >> num_cars >> num_stops >> road_length >> start_time;

  vector<array<int, 2>> cars(num_cars + 1);
  vector<int> stops(num_stops + 1);

  for (int i = 1; i <= num_cars; ++i) {
    cin >> cars[i][0] >> cars[i][1];
  }

  for (int i = 1; i <= num_stops; ++i) {
    cin >> stops[i];
  }

  stops.push_back(road_length);
  sort(stops.begin() + 1, stops.end());

  auto is_feasible_fuel = [&](int fuel) {
    int total_time = 0;

    for (int i = 1; i < stops.size(); ++i) {
      int dist = stops[i] - stops[i - 1];
      if (dist > fuel) {
        return false;
      }
      total_time += 2 * dist - min(dist, fuel - dist);
    }
    return total_time <= start_time;
  };

  int l = 1, r = 1e9, minimum_fuel = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (is_feasible_fuel(mid)) {
      r = mid - 1;
      minimum_fuel = mid;
    } else {
      l = mid + 1;
    }
  }

  int minimum_cost = kInf;
  if (minimum_fuel == -1) {
    cout << -1;
    return;
  }

  for (int i = 1; i <= num_cars; ++i) {
    if (cars[i][1] < minimum_fuel) {
      continue;
    }

    minimum_cost = min(minimum_cost, cars[i][0]);
  }

  cout << ((minimum_cost == kInf) ? -1 : minimum_cost);
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