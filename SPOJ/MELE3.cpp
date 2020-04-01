#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> ii;

const int N = 1005;
const int oo = 1e9+7;
int n, m, dist[N];
vector<int> adj[N];
priority_queue< ii, vector<ii>, greater<ii> > heap;
int cost(int u, int v, int t) {
    int d = abs(u-v);
    int x = (t+d-1) / d;

    if (u < v && x%2 == 1) x ++;
    else if (u > v && x%2 == 0) x++;
    return (x+1)*d;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) dist[i] = oo;
    dist[1] = 0;
    heap.push(mp(0, 1));
    while (!heap.empty()) {
        int u = heap.top().se;
        int d = heap.top().fi;
        heap.pop();

        if (d > dist[u]) continue;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            int tmp = cost(u, v, d);
            if (dist[v] > tmp) {
                dist[v] = tmp;
                heap.push(mp(tmp, v));
            }
        }
    }
    printf("%d", 5*dist[n]);
}
