#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int a, b;
    cin >> a >> b;
    int x = max(a, b) - min(a, b);
    if (x == 1 || x == 9)
        return "Yes";
    else
        return "No";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
