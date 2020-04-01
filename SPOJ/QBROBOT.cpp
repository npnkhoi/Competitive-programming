using namespace std;
#include <bits/stdc++.h>
typedef pair<int, int> ii;
#define REP(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
#define fi first
#define se second
const int N = 505;
const int oo = 1e9 + 15;
int n, m, stop[N], maxi[N], w[N][N];
vector<ii> adj[N];
vector<int> par[N];
void backTrack(int v, int d, int _max) {
    if (_max > maxi[v]) return;
    maxi[v] = _max;
    if (stop[v]) d = 0;
    REP(j, par[v].size()) {
        int u = par[v][j];
        backTrack(u, d + w[v][u], max(_max, d + w[v][u]));
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &stop[i]);
    scanf("%d", &m);
    while (m--) {
        int u, v, c, t;
        //cout << "1\n";
        scanf("%d %d %d %d", &u, &v, &c, &t);
        //cout << "2\n";
        w[v][u] = w[u][v] = t;
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));
    }
    priority_queue<ii> pq; pq.push(mp(0, 1));
    vector<int> dist(N, oo); dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().se, d = pq.top().fi; pq.pop();
        if (d > dist[u]) continue;
        REP(j, adj[u].size()) {
            int v = adj[u][j].fi, c = adj[u][j].se;
            if (d + c < dist[v]) {
                dist[v] = d+c;
                pq.push(mp(dist[v], v));
                par[v].clear();
                par[v].push_back(u);
            } else if (d+c == dist[v]) par[v].push_back(u);
        }
    }
    REP(i, n+1) maxi[i] = oo; maxi[n] = 0;
    /*cout << endl;
    for (int i = 1; i <= n; i++) {
        REP(j, par[i].size()) cout << par[i][j] << " ";
        cout << endl;
    }*/
    backTrack(n, 0, 0);
    printf("%d", maxi[1]);
}
