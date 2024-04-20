#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// const int N = 1001, C = 100'001;
const int N = 5, C = 13;
int n, max_price;
int weights[N];
int values[N];
int dp[N][C];
vector<int> selected;

auto solve() {
    cin >> n >> max_price;
    for (int i = 1; i <= n; i++)
        cin >> weights[i];
    for (int i = 1; i <= n; i++)
        cin >> values[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= max_price; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i]) {
                int new_val = values[i] + dp[i - 1][j - weights[i]];
                if (new_val > dp[i][j]) {
                    dp[i][j] = new_val;
                }
            }
        }
    }

    return dp[n][max_price];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
