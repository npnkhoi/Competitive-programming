using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e5 + 5;
const ll oo = 1e15 + 5;
int n, m;
vector<ii> adj[N], par[N];
ii nex[N];
void dfsBack(int u) {
    //printf("back %d\n", u);
    if (u == 1) return;
    FOR(j, 0, par[u].size() - 1) {
        ii v = par[u][j];
        if (v.se < nex[v.fi].se) {
            nex[v.fi].fi = u;
            nex[v.fi].se = v.se;
            dfsBack(v.fi);
        }
    }
}
void dfs(int u) {
    if (u != n) {
        printf("%d ", nex[u].se);
        dfs(nex[u].fi);
    }
}
void
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &m);
    FOR(i, 1, m) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));
    }
    priority_queue<li> pq;
    vector<ll> dist(N, oo);
    pq.push(mp(0, 1)); dist[1] = 0;

    while (!pq.empty()) {
        ll d = pq.top().fi;
        int u = pq.top().se;
        pq.pop();
        if (d > dist[u]) continue;

        FOR(j, 0, adj[u].size() - 1) {
            ii v = adj[u][j];
            if (dist[v.fi] > dist[u] + 1) {
                par[v.fi].clear();
                par[v.fi].push_back(mp(u, v.se));
                dist[v.fi] = dist[u] + 1;
                pq.push(mp(dist[v.fi], v.fi));
            }
            else if (dist[v.fi] == dist[u] + 1)
                child[u] = min(child[u], v.se);
        }
    }
    printf("%lld\n", dist[n]);
    FOR(i, 1, n) nex[i].se = n+1;
    //dfsBack(n);
    //dfs(1);
    ans(1);
    return 0;
}
/** Happy Coding ^^ */
