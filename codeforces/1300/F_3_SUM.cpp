#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> digit_counts;

    for (int i = 0; i < n; i++) {
        string digits;
        cin >> digits;
        int last_digit = digits[digits.size() - 1] - '0';
        if (digit_counts[last_digit] < 3) digit_counts[last_digit]++;
    }

    vector<int> a;
    for (auto &it : digit_counts) {
        while (it.second--)
            a.push_back(it.first);
    }

    n = a.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum3 = a[i] + a[j] + a[k];
                if (sum3 == 3 || sum3 == 13 || sum3 == 23) {
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
