using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N  = 1e5 + 5;
const int oo = 1e9 + 7;
int n, m, k;
vector<ii> adj1[N], adjk[N], adjn[N];
int dist1[N], distk[N], distn[N];
priority_queue<ii> pq;
void dj(int s, vector<ii> adj[], int dist[]) {
    pq.push(mp(0, s));
    FOR(i, 1, n) dist[i] = oo;
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().se;
        int d = pq.top().fi;
        pq.pop();
        if (d > dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (dist[v.fi] > d + v.se) {
                dist[v.fi] = d + v.se;
                pq.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}
int main() {
    freopen("SCHOOL.inp", "r", stdin);
    freopen("SCHOOL.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    while (m--) {
        int u, v, x, y;
        scanf("%d%d%d%d", &u, &v, &x, &y);
        adj1[u].push_back(mp(v, y));
        adjk[v].push_back(mp(u, x));
        adjn[v].push_back(mp(u, y));
    }
    dj(1, adj1, dist1);
    dj(k, adjk, distk);
    dj(n, adjn, distn);
    int res = oo;
    FOR(i, 1, n) if (dist1[i] + distk[i] < 60)
        res = min(res, dist1[i] + distn[i]);
    printf("%d\n", res);
    return 0;
}
/** Happy Coding ^^ */

