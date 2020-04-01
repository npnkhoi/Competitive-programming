using namespace std;
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> ii;
typedef pair<long long, ii> lii;

const int N = 1e5 + 50;
const long long oo = 1e18;

vector<ii> adj[N];
map<ii, long long> dist;
priority_queue<lii, vector<lii>, greater<lii> > pq;

long long res = oo;
int n, m, x, h[N];


void update(long long d, int u, int l) {
    //printf("%lld %d %d\n", d, u, l);
    if (dist.find(ii(u, l)) == dist.end())
        dist[ii(u, l)] = d, pq.push(mp(d, ii(u, l)))
            //,printf(" new %lld %d %d\n", d, u, l)
            ;
    else if (dist[ii(u, l)] > d)
        dist[ii(u, l)] = d, pq.push(mp(d, ii(u, l)))
        //, printf(" old %lld %d %d\n", d, u, l)
        ;
    if (u == n) res = min(res, d + abs(h[n]-l));
}
int main() {
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    scanf("%d %d %d", &n ,&m, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    while (m--) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj[u].push_back(ii(v, c));
        adj[v].push_back(ii(u, c));
        //printf("%d %d %d\n", u, v, c);
    }

    pq.push(mp(0, ii(1, x)));
    dist[ii(1, x)] = 0;

    while (!pq.empty()) {
        lii t = pq.top(); pq.pop();
        long long d = t.fi;
        int u = t.se.fi, l = t.se.se;
        if (dist[ii(u, l)] < d) continue;

        for (int j = 0; j < adj[u].size(); j++) {
            ii v = adj[u][j];
            //printf("%d %d\n", v.fi, v.se);
            if (0 <= l - v.se && l - v.se <= h[v.fi])
                update(d + v.se, v.fi, l - v.se);
            else if (l - v.se > h[v.fi])
                update(d + (l - h[v.fi] - v.se) + v.se, v.fi, h[v.fi]);
            else if (h[u] >= v.se)
                update(d + (v.se - l) + v.se, v.fi, 0);
        }
    }
    if (res == oo) printf("-1");
    else printf("%lld", res);

}
