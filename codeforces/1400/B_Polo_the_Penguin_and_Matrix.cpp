#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }

    int fmod = a[0] % d;
    for (int i = 0; i < n * m; i++) {
        if (a[i] % d != fmod) return -1;
        a[i] -= fmod;
        a[i] /= d;
    }

    sort(a.begin(), a.end());
    int goal = a[n * m / 2];
    int move = 0;
    for (int i = 0; i < n * m; i++) {
        move += abs(goal - a[i]);
    }
    return move;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
