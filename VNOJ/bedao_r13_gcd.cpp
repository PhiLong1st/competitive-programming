/*
    Code by: KoKoDuDu
    Link: https://oj.vnoi.info/problem/bedao_r13_gcd
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

vector<int> sieve_eratosthenes(int n) {
    vector<int> isPrime(n + 1, 1);
    vector<int> sieve;
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            sieve.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return sieve;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> primes = sieve_eratosthenes(50);
    int ans = LLONG_MAX;

    int m = primes.size();
    for (int i = 1; i < (1 << m); ++i) {
        int tmp = 1;

        for (int j = 0; j < m; ++j) {
            if (i & (1 << j)) {
                tmp *= primes[j];
            }
        }

        bool isOk = true;
        for (int x : a) {
            if (__gcd(x, tmp) == 1) {
                isOk = false;
                break;
            }
        }

        if (isOk) {
            ans = min(ans, tmp);
        }
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
