#include <cstdio>
#include <utility>
#include <vector>
#include <queue>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N = 1e4 + 5;
const int oo = 1e9 + 7;
typedef pair<int, int> ii;
int n, m, k;
vector<ii> adj1[N], adj2[N], adj3[N];
int dist1[N], dist2[N], dist3[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;

void dijkstra(vector<ii> adj[], int dist[], int s) {
    for (int i = 1; i <= n; i++) dist[i] = oo;
    dist[s] = 0;
    heap.push(mp(0, s));

    while (!heap.empty()) {
        int d = heap.top().fi;
        int u = heap.top().se;
        heap.pop();
        if (d > dist[u]) continue;
        for (int j = 0; j < adj[u].size(); j++) {
            ii v = adj[u][j];
            if (d + v.se < dist[v.fi]) {
                dist[v.fi] = d + v.se;
                heap.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int u, v, a, b;
        scanf("%d%d%d%d", &u, &v, &a, &b);
        adj1[u].push_back(mp(v, b));
        adj2[v].push_back(mp(u, a));
        adj3[v].push_back(mp(u, b));
    }
    dijkstra(adj1, dist1, 1);
    dijkstra(adj2, dist2, k);
    dijkstra(adj3, dist3, n);

    int res = oo;
    for (int x = 1; x <= n; x++) if (dist1[x] + dist2[x] <= 59)
    res = min(res, dist1[x] + dist3[x]);
    printf("%d", res);
}
