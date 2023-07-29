#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int, int> ii;

const int N = 1e5 + 5;
int n, m, dist[N], edge[N];
vector <ii> adj[N];

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("D.inp", "r", stdin);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    queue <int> q;
    while (!q.empty()) q.pop();
    dist[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (ii d : adj[u]) {
            int v = d.first, w = d.second;
            if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                edge[v] = w;
                q.push(v);
             } else if (dist[u] + 1 == dist[v]) {
                edge[v] = min(edge[v], w);
             }
        }
    }

    int res = 0;
    for (int i = 2; i <= n; ++i) {
        res += edge[i] * dist[i];
    }

    cout << res << endl;

    return 0;
}
