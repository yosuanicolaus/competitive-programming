#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    switch (n) {
    case 0:
    case 1:
        return 10;
    case 2:
    case 4:
    case 12:
        return 8;
    case 3:
    case 10:
        return 9;
    case 5:
    case 6:
    case 7:
    case 8:
        return 7;
    case 11:
        return 6;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
