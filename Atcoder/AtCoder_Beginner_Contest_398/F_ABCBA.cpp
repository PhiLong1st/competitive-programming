/*
    Code by: KoKoDuDu
    Created: 2025.03.22 19:49:47
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 37;

vector<int> POW;

void buildPOW(int n) {
    POW.resize(n + 1);
    POW[0] = 1;
    for (int i = 1; i <= n; ++i) {
        POW[i] = (POW[i - 1] * BASE) % MOD;
    }
}

void solve() {
    string s, t;
    cin >> s;
    t = s;

    int n = s.size();
    buildPOW(n);

    vector<int> hashT(n), hashS(n);

    reverse(s.begin(), s.end());

    hashT[0] = t[0] - 'A' + 1;
    hashS[0] = s[0] - 'A' + 1;

    for (int i = 1; i < n; ++i) {
        hashT[i] = (hashT[i - 1] * BASE + (t[i] - 'A' + 1)) % MOD;
        hashS[i] = (hashS[i - 1] * BASE + (s[i] - 'A' + 1)) % MOD;
    }

    auto getHashT = [&](int l, int r) -> int {
        if (l == 0) return hashT[r];
        return (hashT[r] - hashT[l - 1] * POW[r - l + 1] % MOD + MOD) % MOD;
        };

    auto getHashS = [&](int l, int r) -> int {
        if (l == 0) return hashS[r];
        return (hashS[r] - hashS[l - 1] * POW[r - l + 1] % MOD + MOD) % MOD;
        };

    int ans = -1;
    for (int i = n - 1; i >= 0; --i) {
        bool isPalindrome = getHashT(n - 1 - i, n - 1) == getHashS(0, i);
        if (isPalindrome) {
            cout << t;
            for (int j = n - i - 2; j >= 0; --j) {
                cout << t[j];
            }
            return;
        }
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
