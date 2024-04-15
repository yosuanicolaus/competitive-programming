#if LOCAL
#include "template/debug.h"
#else /* ©yosuanicolaus */
#define dbg(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int r, c;
    cin >> r >> c;
    vector<string> table(r);
    for (int i = 0; i < r; i++) {
        cin >> table[i];
    }

    bool is_ok = false;
    while (!is_ok) {
        bool found_line = false;
        bool need_merge = false;
        int merge_idx = -1;

        for (auto &line : table) {
            if (line.find("1") == string::npos) { // line == "000.."
                continue;
            } else if (line.find("0") == string::npos) { // line == "111.."
                for (auto &ch : line)
                    ch = '0';
                if (found_line) need_merge = true;
            } else { // line == "11001..."
                found_line = true;
            }
        }

        if (need_merge) {
            for (int y = r - 1; y >= 0; y--) {
                string line = table[y];
                if (line.find("1") == string::npos) {
                    // start merge
                    table.push_back("11111111");
                    vector<int> levels(c);
                    for (int nx = 0; nx < c; nx++) {
                        for (int ny = y + 1; ny < r + 1; ny++) {
                            if (table[ny][nx] == '1') {
                                levels[nx] = ny;
                                break;
                            }
                        }
                    }
                    table.pop_back();
                    vector<int> debris(c);
                    for (int nx = 0; nx < c; nx++) {
                        int debris_count = 0;
                        for (int ny = y - 1; ny >= 0; ny--) {
                            if (table[ny][nx] == '1') {
                                debris_count++;
                                table[ny][nx] = '0';
                            }
                        }
                        debris[nx] = debris_count;
                    }
                    for (int nx = 0; nx < c; nx++) {
                        int ny = levels[nx] - 1;
                        while (debris[nx] > 0) {
                            debris[nx]--;
                            table[ny][nx] = '1';
                            ny--;
                        }
                    }
                }
            }
        } else {
            is_ok = true;
        }
    }

    for (const auto &line : table) {
        cout << line << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
