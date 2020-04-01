using namespace std;
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ii> lii;
typedef pair<ll, int> li;

const int N = 1e5 + 50;
const long long oo = 1e18;

vector<ii> adj[N];
li d[N];
priority_queue<lii, vector<lii>, greater<lii> > pq;
int n, m, x, h[N];

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
    }

    pq.push({0, {x, 1}}); /// dist, height, node
    for (int i = 2; i <= n; i++) d[i].fi = oo;
    d[1] = {0, x}; /// d[node] = dist, height
    ll res = oo;

    while (!pq.empty()) {
        lii t = pq.top(); pq.pop();
        ll dist = t.fi;
        int hei = t.se.fi, u = t.se.se;

        //printf("%lld %d %d\n", dist, hei, u);

        if (dist - hei > d[u].fi - d[u].se) continue;

        for (int j = 0; j < adj[u].size(); j++) {
            int v = adj[u][j].fi;
            int c = adj[u][j].se;

            ll delta = c, newH = hei - c;
            if (newH < 0) {
                if (c <= h[u]) {
                    delta += c - hei;
                    newH = 0;
                } else continue;
            }
            else if (newH > h[v]) {
                delta += newH - h[v];
                newH = h[v];
            }

            if (v == n)
                res = min(res, dist + delta + h[n] - newH);

            if (d[v].fi - d[v].se <= (dist + delta) - newH) continue;
            d[v] = {dist + delta, newH};
            pq.push({dist + delta, {newH, v}});

        }

    }
    //printf("%lld\n", res);
    if (d[n].fi == oo) printf("-1");
    else printf("%lld", d[n].fi + (h[n] - d[n].se));

}
