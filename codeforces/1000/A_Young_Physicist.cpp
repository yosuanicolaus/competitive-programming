#include <bits/stdc++.h>
using ll = long long;

void solve() {
    int n;
    std::cin >> n;

    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; i++) {
        int nx, ny, nz;
        std::cin >> nx >> ny >> nz;
        x += nx;
        y += ny;
        z += nz;
    }

    if (x == 0 && y == 0 && z == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
