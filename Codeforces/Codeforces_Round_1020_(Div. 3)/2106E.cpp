
/*
    Code by: KoKoDuDu
    Created: 2025.04.24 23:10:15
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
int lPos = 0, rPos = 0, usedL = 0, usedR = 0;
vector<int> a, pos;

void cal(int l, int r, int x) {
    if (l > r) return;

    int mid = (l + r) / 2;

    if (a[mid] == x) {
        return;
    }

    if (a[mid] < x && mid < pos[x]) {
        usedL++;
        cal(mid + 1, r, x);
    }
    else if (a[mid] > x && mid > pos[x]) {
        usedR++;
        cal(l, mid - 1, x);
    }
    else if (a[mid] > x && mid < pos[x]) {
        lPos++;
        cal(mid + 1, r, x);
    }
    else {
        rPos++;
        cal(l, mid - 1, x);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    a.resize(n + 1);
    pos.resize(n + 1);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        lPos = rPos = usedL = usedR = 0;

        if (l > pos[x] || r < pos[x]) {
            cout << -1 << ' ';
            continue;
        }

        cal(l, r, x);

        if ((lPos + usedL) >= x) {
            cout << -1 << ' ';
            continue;
        }

        if ((rPos + usedR) >= (n - x + 1)) {
            cout << -1 << ' ';
            continue;
        }
        cout << 2 * max(lPos, rPos) << ' ';
    }

    cout << "\n";
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