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

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return;
    }

    int even = 2, odd = 1;
    while (even <= n) {
        cout << even << " ";
        even += 2;
    }
    while (odd <= n) {
        cout << odd << " ";
        odd += 2;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
