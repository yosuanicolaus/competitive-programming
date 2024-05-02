#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<int> idxs(n + 1), nums(n);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        idxs[num] = i;
        nums[i] = num;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1 || idxs[nums[i] - 1] < i) continue;
        ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
