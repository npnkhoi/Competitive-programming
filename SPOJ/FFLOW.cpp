using namespace std;
#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>
#include <string.h>

const int N = 5e3 + 2;
const long long oo = 1e18 + 7;
int n, m, s, t;
vector<int> adj[N];
int p[N];
long long res[N][N], f;

void augment(int u, long long minEdge) {
    if (u == s) {
        f = minEdge;
        return;
    }
    else if (p[u] != -1) {
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] += f;
    }
}

int main () {
    //freopen("MaxFlow.inp", "r", stdin);
    //freopen("MaxFlow.out", "w", stdout);
    scanf("%d %d", &n, &m);

    s = 1; t = n;
    //printf("kay\n");
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        if (u == v) continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
        res[u][v] += 1LL * c;
        res[v][u] += 1LL * c;
    }

    long long mf = 0;

    while (1) {

        bitset<N> vis; vis[s] = 1;
        queue<int> q; q.push(s);
        memset(p, -1, sizeof p);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (res[u][v] > 0 && !vis[v])
                    q.push(v), vis[v] = 1, p[v] = u;
            }
        }

        f = 0;
        augment(t, oo);
        if (f == 0) break;
        mf += f;
    }

    printf("%lld", mf);
}
