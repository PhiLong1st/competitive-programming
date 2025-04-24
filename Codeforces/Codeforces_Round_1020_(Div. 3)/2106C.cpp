
/*
    Code by: KoKoDuDu
    Created: 2025.04.24 21:42:50
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    int val = -1;

    for (int i = 1; i <= n; ++i) {
        if (b[i] != -1) {
            if (val == -1) {
                val = a[i] + b[i];
            }
            else if (val != a[i] + b[i]) {
                cout << 0 << "\n";
                return;
            }
        }
    }

    if (val == -1) {
        int maxx = -1;
        int minn = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            if (a[i] > k) {
                cout << 0 << "\n";
                return;
            }
            maxx = max(maxx, a[i]);
            minn = min(minn, a[i]);
        }
        cout << (minn + k) - maxx + 1 << "\n";
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (b[i] == -1) {
                b[i] = val - a[i];
                if (b[i] > k || b[i] < 0) {
                    cout << 0 << "\n";
                    return;
                }
            }
        }
        cout << 1 << "\n";
    }
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