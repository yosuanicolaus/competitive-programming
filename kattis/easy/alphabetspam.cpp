#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(4);

    for (const auto &ch : s) {
        int asc = (int)ch;
        if (asc == 95)
            c[0]++;
        else if (asc >= 97 && asc <= 122)
            c[1]++;
        else if (asc >= 65 && asc <= 90)
            c[2]++;
        else
            c[3]++;
    }

    for (int i = 0; i < 4; i++) {
        cout << setprecision(15) << (double)c[i] / n << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
