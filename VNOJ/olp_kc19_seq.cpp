/*
    Code by: KoKoDuDu
    Created: 23.09.2024 11:40:57
    Link: https://oj.vnoi.info/problem/olp_kc19_seq
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
const int MOD = 1e9 + 7;

struct SparseTable {

    const int LGMAX = 20;
    vector<vector<int>> spt;
    vector<int> arr;

    SparseTable(vector<int> arr) {
        this->arr = arr;
        spt.assign(LGMAX, vector<int>(arr.size()));
        build();
    }

    void build() {
        for (int i = 0; i < arr.size(); i++) {
            spt[0][i] = arr[i];
        }
        for (int bit = 1; bit < LGMAX; bit++)
        {
            for (int i = 0; i + (1 << (bit - 1)) < arr.size(); i++)
            {
                spt[bit][i] = __gcd(spt[bit - 1][i], spt[bit - 1][i + (1 << (bit - 1))]);
            }
        }
    }
    int get_gcd(int l, int r) {
        if (l > r) {
            return INT_MAX;
        }
        int lg = 31 - __builtin_clz(r - l + 1);
        return __gcd(spt[lg][l], spt[lg][r - (1 << lg) + 1]);
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] = abs(b[i] - a[i]);
    }
    SparseTable tb(b);
    while (k--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << tb.get_gcd(l, r) << "\n";;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTest = 1;
    while (numTest--) {
        solve();
    }
    return 0;
}