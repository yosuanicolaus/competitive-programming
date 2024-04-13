#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// backtracking solution
// max n input 16

int board[16][16];
int board_size = 2;
pair<int, int> ranges[] = {{0, 0}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

void backtracking(int total_knight, int &count) {
    if (total_knight == 2) {
        count++;
    } else {
        for (int y = 0; y < board_size; y++) {
            for (int x = 0; x < board_size; x++) {
                if (board[y][x]) continue;
                vector<pair<int, int>> filled;
                for (const auto &[py, px] : ranges) {
                    int ny = y + py, nx = x + px;
                    if (ny >= 0 && ny < board_size && nx >= 0 && nx < board_size && board[ny][nx] != 1) {
                        filled.push_back({ny, nx});
                        board[ny][nx] = 1;
                    }
                }
                backtracking(total_knight + 1, count);
                for (const auto &[ny, nx] : filled) {
                    board[ny][nx] = 0;
                }
            }
        }
    }
}

auto solve() {
    int n;
    cin >> n;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        board_size = i;
        backtracking(0, count);
        cout << count / 2 << '\n';
        count = 0;
    }
    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(board, 0, sizeof(board));
    cout << solve() << '\n';
    return 0;
}
