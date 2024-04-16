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
    string s;
    cin >> n >> s;

    vector<string> groups;
    stringstream ss(s);
    string token;

    while (getline(ss, token, '0')) {
        if (token.size() > 0) groups.push_back(token);
    }

    int count_odd = 0, count_two = 0, count_good_two = 0;
    for (const auto &ones : groups) {
        int n = ones.size();
        if (n % 2 == 1)
            count_odd++;
        else if (n == 2)
            count_two++;
        else if (n > 2)
            count_good_two += n - 2;
    }

    if (count_two == 1) {
        if (count_good_two > 0)
            count_two = 0;
        else if (count_odd >= 2) {
            count_odd -= 2;
            count_two = 0;
        }
    } else
        count_two = 0;

    count_odd %= 2;
    if (count_two == 0 && count_odd == 0) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
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
