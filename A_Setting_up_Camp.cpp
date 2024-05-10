#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int a, b, c;
    cin >> a >> b >> c;
    ll tent = a;
    tent += b / 3;
    if (b % 3 > 0) {
        int remain = 3 - (b % 3);
        if (remain > c) return -1LL;
        c -= remain;
        tent++;
    }
    tent += c / 3;
    if (c % 3 > 0) tent++;
    return tent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
    return 0;
}
