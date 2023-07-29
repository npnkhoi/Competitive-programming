#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> ii;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, dist[N], m, C, deg[N], cur[N], dp[N];
vector <ii> adj[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("A.inp", "r", stdin);

    cin >> n >> m >> C;
    for (int i = 1; i <= m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        deg[v]++;
        adj[u].push_back({v, c});
    }
    dist[1] = 1;
    queue <int> q;
    while (!q.empty()) q.pop();
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (ii dd : adj[u]) {
            int v = dd.first, w = dd.second;
            dist[v] = dist[u] + dist[v] + w;
            dist[v] = min(dist[v], 1001);
            cur[v]++;
            if (cur[v] == deg[v]) {
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; ++i) if (dist[i] == 0) {
        dist[i] = 1001;
    }

    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = dist[i]; j <= C; ++j) {
            (dp[j] += dp[j - dist[i]]) %= MOD;
        }
    }
    int res = 0;
    for (int i = 1; i <= C; ++i) {
        res = (res + dp[i]) % MOD;
    }
    cout << res << endl;

    return 0;
}
