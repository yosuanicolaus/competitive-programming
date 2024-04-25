#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int matrix[20][20];

auto solve() {
    int n;
    cin >> n;

    queue<tuple<int, int, int>> q;
    q.push({n, n, n});

    while (!q.empty()) {
        tuple<int, int, int> qv = q.front();
        q.pop();
        int v = get<0>(qv);
        int i = get<1>(qv);
        int j = get<2>(qv);
        if (v == -1 || matrix[i][j] != -1) continue;
        matrix[i][j] = v;

        if (v > 0) {
            if (i > 0) q.push({v - 1, i - 1, j});
            if (j > 0) q.push({v - 1, i, j - 1});
            if (i < 20) q.push({v - 1, i + 1, j});
            if (j < 20) q.push({v - 1, i, j + 1});
        }
    }

    for (int i = 0; i <= n * 2; i++) {
        bool found_val = false;
        for (int j = 0; j <= n * 2; j++) {
            if (matrix[i][j] == -1) {
                if (found_val) break;
                cout << "  ";
            } else {
                found_val = true;
                cout << matrix[i][j];
                if (matrix[i][j + 1] != -1) cout << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(matrix, -1, sizeof(matrix));
    solve();
    return 0;
}
