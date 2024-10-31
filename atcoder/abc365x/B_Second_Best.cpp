#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int highest_val = 0;
    int highest_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > highest_val) {
            highest_val = arr[i];
            highest_idx = i;
        }
    }

    int second_val = 0;
    int second_idx = 0;
    for (int i = 0; i < n; i++) {
        if (i == highest_idx) continue;
        if (arr[i] > second_val) {
            second_val = arr[i];
            second_idx = i;
        }
    }

    return second_idx + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
