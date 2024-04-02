#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> coprimes[1001];

void solve() {
    int n;
    cin >> n;
    vector<int> idxs[1001];

    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        idxs[num].push_back(i);
    }

    int ans = -1;
    for (int num1 = 1; num1 <= 1000; num1++) {
        if (idxs[num1].empty()) continue;
        for (int &num2 : coprimes[num1]) {
            if (idxs[num2].empty()) continue;
            ans = max(ans, idxs[num1].back() + idxs[num2].back());
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (__gcd(i, j) == 1) {
                coprimes[i].push_back(j);
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
