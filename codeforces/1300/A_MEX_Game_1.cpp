#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int sums[200001];

auto solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sums[num]++;
    }

    bool found_first = false;
    for (int i = 0; i < 200001; i++) {
        if (sums[i] == 0)
            return i;
        else if (sums[i] == 1) {
            if (!found_first)
                found_first = true;
            else
                return i;
        }
    }
    return 200000;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
        memset(sums, 0, sizeof(sums));
    }
    return 0;
}
