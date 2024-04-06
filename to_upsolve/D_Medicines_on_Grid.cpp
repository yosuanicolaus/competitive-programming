#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TLE & WA on some

vector<pair<int, int>> directions = {
    make_pair(-1, 0),
    make_pair(0, -1),
    make_pair(1, 0),
    make_pair(0, 1),
};

bool dp(vector<vector<char>> map_cell, vector<vector<int>> map_med, int energy, pair<int, int> position,
        vector<vector<bool>> map_taken_med) {
    if (energy < 0) return false;
    if (map_cell[position.first][position.second] == 'T') return true;
    if (energy == 0 && map_med[position.first][position.second] == 0) return false;

    for (const auto &direction : directions) {
        int dest_y = position.first + direction.first;
        int dest_x = position.second + direction.second;
        if (dest_y >= 0 && dest_y < map_cell.size() && dest_x >= 0 && dest_x < map_cell[0].size()) {
            bool res = dp(map_cell, map_med, energy - 1, make_pair(dest_y, dest_x), map_taken_med);
            if (map_med[position.first][position.second] > 0 && !map_taken_med[position.first][position.second]) {
                vector<vector<bool>> new_map_taken_med = map_taken_med;
                new_map_taken_med[position.first][position.second] = true;
                int new_energy = map_med[position.first][position.second] - 1;
                res = res or dp(map_cell, map_med, new_energy, make_pair(dest_y, dest_x), new_map_taken_med);
            }
            if (res) return true;
        }
    }

    return false;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> map_cell(h);
    vector<vector<int>> map_med(h);
    vector<vector<bool>> map_taken_med(h);
    pair<int, int> init_pos;

    for (int i = 0; i < h; i++) {
        map_cell[i].resize(w);
        map_med[i].resize(w);
        map_taken_med[i].resize(w);
        for (int j = 0; j < w; j++) {
            char cell;
            cin >> cell;
            map_cell[i][j] = cell;
            if (cell == 'S') init_pos = make_pair(i, j);
        }
    }

    int med;
    cin >> med;
    int init_energy = 0;

    for (int i = 0; i < med; i++) {
        int y, x, energy;
        cin >> y >> x >> energy;
        y--;
        x--;
        if (map_cell[y][x] == 'S')
            init_energy = energy;
        else
            map_med[y][x] = energy;
    }

    if (dp(map_cell, map_med, init_energy, init_pos, map_taken_med)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
