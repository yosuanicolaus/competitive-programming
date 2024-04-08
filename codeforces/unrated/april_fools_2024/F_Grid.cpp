#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    std::vector<std::vector<char>> grid(21, std::vector<char>(21));

    for (int i = 0; i < 21; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < 21; j++) {
            grid[i][j] = s[j];
        }
    }

    int best_ans = 0;
    for (int y = 0; y < 18; y++) {
        for (int x = 0; x < 18; x++) {
            int ans = 0;
            for (int i = y; i < y + 4; i++) {
                for (int j = x; j < x + 4; j++) {
                    if (grid[i][j] == '1')
                        ans++;
                }
            }
            best_ans = std::max(best_ans, ans);
        }
    }

    std::cout << best_ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
