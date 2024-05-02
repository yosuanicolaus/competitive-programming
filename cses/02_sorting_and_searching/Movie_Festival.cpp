#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

auto solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> end_starts;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        end_starts.push_back({end, start});
    }
    sort(end_starts.begin(), end_starts.end());

    int cnt = 0;
    int time = 0;
    for (const auto &[end, start] : end_starts) {
        if (start >= time) {
            cnt++;
            time = end;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
