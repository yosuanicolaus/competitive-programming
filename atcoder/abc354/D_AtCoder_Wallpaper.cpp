#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> pattern = {{2, 1}, {1, 2}, {0, 1}, {1, 0}};

// 240518
// https://atcoder.jp/contests/abc354/tasks/abc354_d
// I give up. Let's solve it in the future :)
// I just, can't really wrap my brain to the pattern logic

auto solve() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll ans = 0;

    ll gx1 = x1, gx2 = x2, gy1 = y1, gy2 = y2;
    if (x1 % 4 != 0) gx1 += 4 - (x1 % 4);
    if (x2 % 4 != 0) gx2 -= x2 % 4;
    if (y1 % 2 != 0) gy1++;
    if (y2 % 2 != 0) gy2--;

    ll dgx = gx2 - gx1, dgy = gy2 - gy1;
    // unfinished. I want to eat ...

    return 42;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
