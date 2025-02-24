
/*
    Code by: KoKoDuDu
    Created: 29.10.2024 19:26:23
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> num_div(1000010);
    for (int i = 1; i <= 1000000; ++i) {
        for (int j = i; j <= 1000000;j += i) {
            num_div[j]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        cout << num_div[x] << '\n';
    }
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