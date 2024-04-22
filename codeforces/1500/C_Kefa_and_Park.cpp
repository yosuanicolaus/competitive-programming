#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200'001;
bool cats[N];
bool visited[N];
vector<int> adj[N];
int n, m;

int count_ways(int v, int cat) {
    if (visited[v]) return 0;
    if (cats[v]) cat--;
    if (cat == -1) return 0;
    if (adj[v].size() == 1 && visited[adj[v][0]]) return 1;
    if (!cats[v]) cat = m;

    visited[v] = true;
    int ways = 0;
    for (const auto &nv : adj[v]) {
        ways += count_ways(nv, cat);
    }
    return ways;
}

auto solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int cat;
        cin >> cat;
        if (cat == 1) cats[i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    return count_ways(1, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
