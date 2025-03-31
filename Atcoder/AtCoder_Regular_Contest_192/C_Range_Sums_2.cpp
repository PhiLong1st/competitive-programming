/*
    Code by: KoKoDuDu
    Created: 2025.03.23 17:10:57
*/
#include <bits/stdc++.h>
#define int long long
#define pll pair<int, int>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> save(n + 1), trace(n + 1);
    vector<int> P(n + 1), A(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }

    auto ask = [&](int s, int t) -> int {
        cerr << "? " << s << " " << t << " ";
        // cout.flush();
        int val = 0;
        // cin >> val;

        s = P[s];
        t = P[t];

        if (s > t) {
            swap(s, t);
        }

        for (int i = s; i <= t; ++i) {
            val += A[i];
        }
        cerr << val << '\n';
        return val;
        };

    int x = 1, y = 2;
    int a = ask(1, 2);
    for (int i = 3; i <= n; ++i) {
        int b = ask(y, i);
        int c = ask(x, i);

        cout << i << " - ";
        if (c > max(a, b)) {
            save[y] = a + b - c;
            a = c;
            y = i;
            cout << "c ";
        }

        if (a > max(c, b)) {
            save[i] = b + c - a;
            cout << "a ";

        }

        if (b > max(a, c)) {
            save[x] = c + a - b;
            x = i;
            a = b;
            cout << "b ";

        }

        cout << x << ' ' << y << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        cout << save[i] << ' ';
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