#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// TLX basic - 07/B
// https://tlx.toki.id/courses/competitive/chapters/07/problems/B/
// prev submission: 71% (5 AC, 2 WA) ~ why???

// dp [item] [capacity]
const int K = 5, C = 37; // just for better debugging
// const int K = 101, C = 2001;
int dp[K][C];
int weights[K];
int values[K];
int capacity, stone;
vector<int> selected;

auto solve() {
    cin >> capacity >> stone;

    for (int i = 1; i <= stone; i++)
        cin >> weights[i] >> values[i];

    for (int i = 1; i <= stone; i++) {
        for (int j = 1; j <= capacity; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
        }
    }

    int i = stone, j = capacity;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selected.push_back(i);
            j -= weights[i];
        }
        i--;
    }

    reverse(selected.begin(), selected.end());
    for (const auto &item : selected)
        cout << item << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
