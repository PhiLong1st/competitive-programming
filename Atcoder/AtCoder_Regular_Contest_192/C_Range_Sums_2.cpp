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

    // vector<int> P(n + 1, 0), A(n + 1, 0);
    // for (int i = 1; i <= n; ++i) {
    //     cin >> P[i];
    // }
    // for (int i = 1; i <= n; ++i) {
    //     cin >> A[i];
    // }

    vector<int> sum_p1(n + 1, 0), sum_p2(n + 1, 0);
    vector<int> left, right, middle, order;
    vector<int> save_order(n + 1, 0);

    auto ask = [&](int s, int t) -> int {
        cout << "? " << s << " " << t << "\n";
        cout.flush();
        int val = 0;
        // s = P[s];
        // t = P[t];
        // if (s > t) swap(s, t);
        // for (int i = s; i <= t; ++i) {
        //     val += A[i];
        // }
        cin >> val;
        return val;
        };

    int x = 1, y = 2;
    int a = ask(1, 2);

    for (int i = 3; i <= n; ++i) {
        int b = ask(x, i);
        int c = ask(y, i);

        sum_p1[i] = b;
        sum_p2[i] = c;

        if (c > max(a, b)) {
            left.push_back(i);
        }
        else if (b > max(a, c)) {
            right.push_back(i);
        }
        else {
            middle.push_back(i);
        }
    }

    sort(left.begin(), left.end(), [&](int a, int b) {
        return sum_p1[a] > sum_p1[b];
        });
    sort(right.begin(), right.end(), [&](int a, int b) {
        return sum_p2[a] < sum_p2[b];
        });
    sort(middle.begin(), middle.end(), [&](int a, int b) {
        return sum_p1[a] < sum_p1[b];
        });

    order.insert(order.end(), left.begin(), left.end());
    order.insert(order.end(), x);
    order.insert(order.end(), middle.begin(), middle.end());
    order.insert(order.end(), y);
    order.insert(order.end(), right.begin(), right.end());

    for (int i = 0; i < n; ++i) {
        save_order[order[i]] = i + 1;
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
        cout << save_order[i] << " ";
    }

    int val_p1 = 0;
    int val_p2 = 0;

    if (save_order[1] != save_order[2] - 1) {
        int next_p1 = -1, next_p2 = -1;
        for (int i = 1; i <= n; ++i) {
            if (save_order[i] == save_order[1] + 1) {
                next_p1 = i;
            }
            if (save_order[i] == save_order[2] - 1) {
                next_p2 = i;
            }
        }
        val_p1 = a - sum_p2[next_p1];
        val_p2 = a - sum_p1[next_p2];
        // cerr << next_p1 << " " << next_p2 << "\n";
        // cerr << a << ' ' << sum_p1[next_p2] << " " << sum_p2[next_p1] << "\n";
    }
    else {
        if (save_order[1] == 1) {
            int pos_n = -1;
            for (int i = 1; i <= n; ++i) {
                if (save_order[i] == n) {
                    pos_n = i;
                }
            }
            val_p1 = sum_p1[pos_n] - sum_p2[pos_n];
            val_p2 = a - val_p1;
        }
        else {
            int pos_1 = -1;
            for (int i = 1; i <= n; ++i) {
                if (save_order[i] == 1) {
                    pos_1 = i;
                }
            }
            val_p2 = sum_p2[pos_1] - sum_p1[pos_1];
            val_p1 = a - val_p2;
        }
    }

    sum_p1[x] = val_p1;
    sum_p2[y] = val_p2;
    sum_p2[x] = a;

    left.push_back(x);
    for (int i = 0; i < left.size() - 1; ++i) {
        cout << sum_p1[left[i]] - sum_p1[left[i + 1]] << " ";
    }
    cout << val_p1 << " ";
    middle.insert(middle.begin(), x);
    for (int i = 1; i < middle.size(); ++i) {
        cout << sum_p1[middle[i]] - sum_p1[middle[i - 1]] << " ";
    }
    cout << val_p2 << " ";
    right.insert(right.begin(), y);
    for (int i = 1; i < right.size(); ++i) {
        cout << sum_p2[right[i]] - sum_p2[right[i - 1]] << " ";
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