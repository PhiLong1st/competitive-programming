
/*
    Code by: KoKoDuDu
    Created: 2025.04.28 22:38:13
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int MAX_N = 7e6;
    vector<int> isPrime(MAX_N + 1), sieve;
    isPrime[1] = 1;
    for (int i = 2; i <= MAX_N; ++i) {
        if (!isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                isPrime[j] = 1;
            }
        }
    }

    for (int i = 1; i <= MAX_N; ++i) {
        if (!isPrime[i]) {
            sieve.push_back(i);
        }
    }
    // cout << sieve.size() << '\n';
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), vst(n + 1);

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end(), greater<>());

        int l = 0, r = n, ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int pos = 0, rem = 0;

            for (int i = 1; i <= mid; ++i) {
                if (a[i] > sieve[pos]) {
                    rem += a[i] - sieve[pos++];
                }
                else {
                    break;
                }
            }
            bool isOk = true;
            for (int i = pos + 1; i <= mid; ++i) {
                if (rem >= sieve[pos] - a[i]) {
                    rem -= sieve[pos++] - a[i];
                }
                else {
                    isOk = false;
                    break;
                }
            }

            if (isOk) {
                ans = n - mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}