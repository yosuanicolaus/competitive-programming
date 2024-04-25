#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char board[101][101];

auto solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            if (line[j] == '-') {
                board[i][j] = '-';
            } else if (i % 2 == 0) {
                board[i][j] = (j % 2 == 0) ? 'B' : 'W';
            } else {
                board[i][j] = (j % 2 == 0) ? 'W' : 'B';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
