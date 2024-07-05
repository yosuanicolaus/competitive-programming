#if LOCAL
#include <debug.h>
#endif // ©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<string> nums(n);
    string ans(10, '0');
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int carry = 0;
    for (int i = 49; i >= 0; i--) {
        int x = carry;
        for (int j = 0; j < n; j++) {
            int num = nums[j][i] - '0';
            x += num;
        }
        if (i <= 8) ans[i + 1] = (char)(x % 10) + '0';
        carry = x / 10;
    }
    ans[0] = (char)carry + '0';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
