#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> ii;
const int N = 1000 + 5;
const int oo = 1e9 + 50;
int tc, n, m, dist[N][N];
vector<ii> adj[N];
int main() {
    scanf("%d",&tc);
    while (tc--) {
        scanf("%d %d", &n, &m);
        FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = oo;
        FOR(i, 1, n) adj[i].clear();
        while (m--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(mp(v, c));
        }
        FOR(vtx, 1, n) {
            priority_queue<ii, vector<ii>, greater<ii> > pq;
            pq.push(mp(0, vtx));
            dist[vtx][vtx] = 0;
            while (!pq.empty()) {
                int u = pq.top().se, d = pq.top().fi;
                //cout << u << " " << d << endl;
                pq.pop();

                if (d > dist[vtx][u]) continue;
                REP(j, adj[u].size()) {
                    int v = adj[u][j].fi, w = adj[u][j].se;
                    //printf("%d %d: cmp %d ~ %d\n", v, w, dist[vtx][v], d + w);
                    if (dist[vtx][v] > d + w) {
                        dist[vtx][v] = d + w;
                        pq.push(mp(d + w, v));
                        //printf("push %d %d\n", v, d+w);
                    }
                }
            }
        }
        FOR(i, 1, n) {
            int res = oo;
            FOR(j, 1, n) if (i != j) res = min(res, dist[i][j] + dist[j][i]);
            if (res == oo) printf("-1\n");
            else printf("%d\n", res);
        }
    }
}
