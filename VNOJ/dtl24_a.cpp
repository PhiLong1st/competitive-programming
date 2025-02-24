/*
    Code by: KoKoDuDu
    Created: 02.11.2024 14:30:48
    Link: https://oj.vnoi.info/problem/dtl24_a
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        bool ok = false;
        for (int x = 0; x <= sum; ++x) {
            int dem = 0;
            for (int i = 0; i < n; ++i) {
                if (sum - a[i] >= x) {
                    dem++;
                }
            }
            if (dem == k) {
                ok = true;
                break;
            }
        }
        cout << ((ok) ? "YES\n" : "NO\n");
    }

    return 0;
}
