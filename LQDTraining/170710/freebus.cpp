using namespace std;
#include <stdio.h>
#include <queue>
#include <vector>

typedef pair<int, int> ii;
typedef pair<long long, ii> llii;
#define mp make_pair
#define fi first
#define se second

const int N = 1e5 + 10;
const int K = 7;
const long long oo = 1e17 + 17;

vector<ii> adj[N];
priority_queue<llii, vector<llii>, greater<llii> > pq;
long long f[N][K];

int main() {
    freopen("freebus.inp", "r", stdin);
    freopen("freebus.out", "w", stdout);
    int n, m, k, s, t;
    scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(ii(v, c));
        adj[v].push_back(ii(u, c));
    }

    for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) f[i][j] = oo;
    f[s][0] = 0;

    pq.push(mp(0, ii(s, 0)));

    while (!pq.empty()) {
        llii fr = pq.top(); pq.pop();
        long long d = fr.fi;
        int u = fr.se.fi, x = fr.se.se;
        if (d > f[u][x]) continue;
        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].fi, w = adj[u][j].se;
            if (f[v][x] > f[u][x] + 1LL * w)
                f[v][x] = f[u][x] + 1LL * w, pq.push(mp(f[v][x], ii(v, x)));
            if (x < k && f[v][x+1] > f[u][x])
                f[v][x+1] = f[u][x], pq.push(mp(f[v][x+1], ii(v, x+1)));
        }
    }

    long long res = f[t][0];
    for (int  i = 1; i <= k; i++) res = min(res, f[t][i]);
    printf("%lld\n", res);
}
