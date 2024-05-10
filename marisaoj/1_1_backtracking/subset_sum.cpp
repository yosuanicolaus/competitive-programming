#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<ll> arr;

bool backtrack(int idx, ll sum) {
    if (sum > k) return false;
    if (sum == k) return true;
    if (idx == n) return false;

    if (backtrack(idx + 1, sum)) return true;
    if (backtrack(idx + 1, sum + arr[idx])) return true;
    return false;
}

auto solve() {
    cin >> n >> k;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (backtrack(0, 0LL))
        return "YES";
    else
        return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
