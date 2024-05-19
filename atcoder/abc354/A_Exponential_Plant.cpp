#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int H;
    cin >> H;
    int h = 0;
    int a = 0;
    while (h <= H) {
        int p = 1;
        int xa = a;
        while (xa--) {
            p *= 2;
        }
        h += p;
        a++;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
