#if LOCAL
#include "template/debug.h"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// bfs solution

void solve() {
    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> num_steps;
    unordered_set<int> visited;
    num_steps.push({n, 0});

    while (!num_steps.empty()) {
        int num = num_steps.front().first;
        int step = num_steps.front().second;
        num_steps.pop();

        if (num == m) {
            cout << step << '\n';
            return;
        }
        visited.insert(num);

        int next1 = num - 1;
        if (next1 > 0 && visited.find(next1) == visited.end()) {
            num_steps.push({next1, step + 1});
        }
        int next2 = num * 2;
        if (next2 <= m * 2 && visited.find(next2) == visited.end()) {
            num_steps.push({next2, step + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
