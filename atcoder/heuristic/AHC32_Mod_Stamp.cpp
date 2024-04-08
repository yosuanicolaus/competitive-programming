/*
240407 Sunday
AtCoder Heuristic Contest 032 result
https://atcoder.jp/contests/ahc032/standings?watching=yosuanicolaus
original file name: A_Mod_Stamp.cpp

Local test case
Average best score / maximum score: ~69.5%
Standing score: 8,670,431,334,706 (out of max 12,128,668,876,800) ~71.487%

Final strategy
Random with a bit of optimization
Within the 2s time limit, brute force as much simulations and save the best result
Small optimization:
- only simulate the 3x3 stamp, add to moves if simulation is successful
- add an error threshold, break with enough simulation failure
*/

#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Grid = array<array<ll, 9>, 9>;
using Stamp = array<array<ll, 3>, 3>;
using Stamps = array<Stamp, 20>;
using Move = array<int, 3>;
using Moves = vector<Move>;

// 12089754470400 - max from all test cases (150)
// 6108352088531  - by default, no operation, all test cases (50%)
// 80598363136    - max from 1 test case
// 42088674043    - default from our test case (~52%)

constexpr ll SCOREMOD = 998244353;

auto time_start = chrono::high_resolution_clock::now();

auto get_time() {
    auto time_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(time_end - time_start);
    return duration.count();
}

Grid copy_grid(Grid grid) {
    Grid new_grid;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            new_grid[i][j] = grid[i][j];
    return new_grid;
}

ll calculate_score(const Grid &grid) {
    ll score = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            score += grid[i][j] % SCOREMOD;
        }
    }
    return score;
}

void stamp_grid(Grid &grid, const Stamps &stamps, const Move &move) {
    int stamp_id = move[0];
    int y = move[1];
    int x = move[2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[y + i][x + j] += stamps[stamp_id][i][j];
        }
    }
}

ll simulate_score(const Grid &grid, const Stamps &stamps, const Moves &moves) {
    /* Make sure the constrains are met! */
    Grid new_grid = copy_grid(grid);
    for (const Move &move : moves) {
        stamp_grid(new_grid, stamps, move);
    }
    return calculate_score(new_grid);
}

ll simulate_3x3_sum(const Grid &grid, const Stamps &stamps, Move &move) {
    // returns +/- LL -> (+) means value added, (-) means value decreased
    ll prev = 0;
    ll after = 0;
    int stamp_id = move[0];
    int y = move[1];
    int x = move[2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            prev += grid[y + i][x + j];
            after += (grid[y + i][x + j] + stamps[stamp_id][i][j]) % SCOREMOD;
        }
    }
    return after - prev;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    Grid grid;
    Stamps stamps;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll a;
            cin >> a;
            grid[i][j] = a;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int p = 0; p < 3; p++) {
            for (int q = 0; q < 3; q++) {
                ll s;
                cin >> s;
                stamps[i][p][q] = s;
            }
        }
    }

    /* Algorithm starts here */

    ll best_score = calculate_score(grid);
    Moves best_moves = {};

    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> rand_moves_count(1, 81), rand_m(0, 19), rand_yx(0, 6);

    while (get_time() < 1990) {
        Grid new_grid = copy_grid(grid);
        Moves moves;
        int moves_count = 0;
        int error_count = 0;
        int error_threshold = 2000;

        while (moves_count <= 81 && error_count <= error_threshold) {
            // create random move
            Move rand_move = {rand_m(rng), rand_yx(rng), rand_yx(rng)};
            if (simulate_3x3_sum(new_grid, stamps, rand_move) > 0) {
                stamp_grid(new_grid, stamps, rand_move);
                error_count = 0;
                moves_count++;
                moves.push_back(rand_move);
            } else {
                error_count++;
            }
        }
        ll new_score = simulate_score(grid, stamps, moves);
        if (new_score > best_score) {
            best_score = new_score;
            best_moves = moves;
        }
    }

    debug(best_score, best_score / 80598363136.0);

    cout << best_moves.size() << '\n';
    for (const auto &move : best_moves) {
        cout << move[0] << ' ' << move[1] << ' ' << move[2] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
