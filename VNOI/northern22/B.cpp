#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 5, N = 15, INF = 1e9;

int m, n, s, a[N], b[N], dist[M];
queue<int> q;

int main() {
    freopen("B.inp", "r", stdin);
    cin >> m >> n >> s;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i] >> b[i];
        a[i] %= m;
        b[i] %= m;
    }
    for (int i = 0; i < m; ++ i) dist[i] = INF;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < n; ++ i) {
            int v = (1LL * u * a[i] + b[i]) % m;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << (dist[0] == INF ? -1 : dist[0]);
}
