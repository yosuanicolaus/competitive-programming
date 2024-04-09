#if LOCAL
#include "template/debug.h"
#else /*©[yosuanicolaus]©*/
#define d(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    /* ~ good luck! ~ */
    return 42;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
