#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    map<int, int> sticks;

    for (int i = 0; i < n; i++) {
        int stick;
        cin >> stick;
        sticks[stick]++;
    }

    int count = 0;
    for (auto [stick, sc] : sticks) {
        if (sc >= 3) count += sc / 3;
    }
    return count;
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
