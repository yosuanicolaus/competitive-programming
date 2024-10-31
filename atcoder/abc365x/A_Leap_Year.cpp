#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int y;
    cin >> y;

    if (y % 400 == 0) return 366;
    if (y % 100 == 0) return 365;
    if (y % 4 == 0) return 366;
    return 365;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
