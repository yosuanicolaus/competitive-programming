#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int matrix[20][20];
    for (int y = 0; y < 20; y++)
        for (int x = 0; x < 20; x++)
            cin >> matrix[y][x];

    int best = 0;

    // horizontal
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x <= 16; x++) {
            int product = matrix[y][x] * matrix[y][x + 1] * matrix[y][x + 2] * matrix[y][x + 2];
            best = max(best, product);
        }
    }
    // vertical
    for (int y = 0; y <= 16; y++) {
        for (int x = 0; x < 20; x++) {
            int product = matrix[y][x] * matrix[y + 1][x] * matrix[y + 2][x] * matrix[y + 3][x];
            best = max(best, product);
        }
    }
    // diagonal '\'
    for (int y = 0; y <= 16; y++) {
        for (int x = 0; x <= 16; x++) {
            int product = matrix[y][x] * matrix[y + 1][x + 1] * matrix[y + 2][x + 2] * matrix[y + 3][x + 3];
            best = max(best, product);
        }
    }
    // diagonal '/'
    for (int y = 3; y < 20; y++) {
        for (int x = 0; x <= 16; x++) {
            int product = matrix[y][x] * matrix[y - 1][x + 1] * matrix[y - 2][x + 2] * matrix[y - 3][x + 3];
            best = max(best, product);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
