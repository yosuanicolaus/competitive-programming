#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = a; i <= b; i++) {
        if (i % c == 0) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
