#if LOCAL
#include "template/debug.h"
#else /* author: yosuanicolaus */
#define debug(...)
#endif /* date : 240407 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Update 240407 attempt => TLE >:)
// At least I'm comfortable with bfs now.

vector<pair<int, int>> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1},
};

vector<pair<int, int>> bfs_reachable(vector<vector<char>> map_cell, vector<vector<int>> map_med,
                                     pair<int, int> init_pos, int start_energy, int h, int w) {
    vector<pair<int, int>> reachable; // reachable medicine/finish positions
    queue<pair<pair<int, int>, int>> myqueue;
    vector<vector<bool>> visited(h);
    for (int i = 0; i < h; i++)
        visited[i].resize(w);
    myqueue.push({init_pos, start_energy});

    while (!myqueue.empty()) {
        pair<int, int> pos = myqueue.front().first;
        int energy = myqueue.front().second;
        myqueue.pop();
        if (energy < 0) continue;

        int pos_y = pos.first;
        int pos_x = pos.second;
        visited[pos_y][pos_x] = true;
        if (init_pos != pos && map_med[pos_y][pos_x] > 0 || map_cell[pos_y][pos_x] == 'T')
            reachable.push_back({pos_y, pos_x});

        // go up/down/left/right
        for (const auto &direction : directions) {
            int next_pos_y = pos_y + direction.first;
            int next_pos_x = pos_x + direction.second;
            if (next_pos_y >= 0 && next_pos_y < h && next_pos_x >= 0 && next_pos_x < w &&
                map_cell[next_pos_y][next_pos_x] != '#' && !visited[next_pos_y][next_pos_x])
                myqueue.push({{next_pos_y, next_pos_x}, energy - 1});
        }
    }
    return reachable;
}

bool bfs_reach_end(vector<vector<char>> map_cell, vector<vector<vector<pair<int, int>>>> med_reachable_pos,
                   vector<pair<int, int>> start_reachable_meds) {
    queue<pair<int, int>> q;
    for (const auto &pos : start_reachable_meds) {
        q.push(pos);
    }
    vector<vector<bool>> visited(med_reachable_pos.size());
    for (int i = 0; i < med_reachable_pos.size(); i++)
        visited[i].resize(med_reachable_pos[0].size(), false);

    while (!q.empty()) {
        // vector<pair<int, int>> reachable_pos = q.front();
        int pos_y = q.front().first;
        int pos_x = q.front().second;
        q.pop();
        if (visited[pos_y][pos_x]) continue;
        visited[pos_y][pos_x] = true;
        if (map_cell[pos_y][pos_x] == 'T') return true;

        for (const auto &pos : med_reachable_pos[pos_y][pos_x]) {
            q.push(pos);
        }
    }
    return false;
}

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> map_cell(h);
    vector<vector<int>> map_med(h);
    vector<vector<bool>> visited(h);
    pair<int, int> init_pos;

    for (int i = 0; i < h; i++) {
        map_cell[i].resize(w);
        map_med[i].resize(w);
        visited[i].resize(w);
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
    vector<pair<int, int>> medicine_pos(med);

    for (int i = 0; i < med; i++) {
        int y, x, energy;
        cin >> y >> x >> energy;
        y--;
        x--;
        if (map_cell[y][x] == 'S')
            init_energy = energy;
        else {
            map_med[y][x] = energy;
            medicine_pos[i] = {y, x};
        }
    }
    if (init_energy == 0) {
        cout << "No" << '\n';
        return;
    }

    vector<vector<vector<pair<int, int>>>> med_reachable_pos(h);
    for (int i = 0; i < h; i++)
        med_reachable_pos[i].resize(w);
    vector<pair<int, int>> start_reachable_meds = bfs_reachable(map_cell, map_med, init_pos, init_energy, h, w);

    for (const auto &med_pos : medicine_pos) {
        int med_energy = map_med[med_pos.first][med_pos.second];
        vector<pair<int, int>> reachable = bfs_reachable(map_cell, map_med, med_pos, med_energy, h, w);
        med_reachable_pos[med_pos.first][med_pos.second] = reachable;
    }

    if (bfs_reach_end(map_cell, med_reachable_pos, start_reachable_meds)) {
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
