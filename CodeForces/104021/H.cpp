#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 25000, INF = 1e9;
vector<vector<pii>> graph;
int dist[MAX + 1];
bool visited[MAX + 1];

void SPFA(int src) {
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    visited[src] = true;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        visited[u] = false;
        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("Test.txt", "r", stdin);
    int n, x, y, s;
    cin >> n >> x >> y >> s;
    graph.assign(n + 1, vector<pii>());
    memset(visited, false, sizeof(visited));

    for(int i = 0; i <= n; i++)
        dist[i] = INF;

    for(int i = 0; i < x; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    for(int i = 0; i < y; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    SPFA(s);
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF)
            cout << "NO PATH\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
