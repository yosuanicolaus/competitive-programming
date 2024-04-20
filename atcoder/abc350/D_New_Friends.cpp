#if LOCAL
#include <debug.h>
#endif //*©yosuanicolaus
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
TODO upsolve

  I'd say this is good enough.
  My first graph problem :D
  To upsolve in the future
  https://atcoder.jp/contests/abc350/tasks/abc350_d

        WA  × 23
        AC  × 11
        TLE × 2
*/

const int N = 200001;
vector<int> adj[N];

auto solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    unordered_set<int> seen;
    vector<int> clusters;

    for (int i = 1; i < N; i++) {
        if (adj[i].empty()) continue;
        if (seen.count(i)) continue;
        clusters.push_back(i);
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (seen.count(node)) continue;
            seen.insert(node);
            for (auto next_node : adj[node]) {
                q.push(next_node);
            }
        }
    }

    // for each cluster, count total edge & node
    int total_ans = 0;
    for (auto c : clusters) {
        seen.clear();
        int total_edge = 0;
        int total_node = 0;
        queue<int> q;
        q.push(c);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (seen.count(node)) continue;
            total_node++;
            seen.insert(node);
            for (auto next_node : adj[node]) {
                if (seen.count(next_node) == 0) total_edge++;
                q.push(next_node);
            }
        }

        int max_edge = total_node * (total_node - 1) / 2;
        int clust_ans = max_edge - total_edge;
        total_ans += clust_ans;
    }

    return total_ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
    return 0;
}
