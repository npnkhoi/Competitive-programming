using namespace std;
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cmath>

#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> ii;
const int N = 2010;
const int oo = 1e9 + 7;

priority_queue <ii, vector<ii>, greater<ii> > pq;
vector<ii> adj[N];
int d[N], par[N];
pair<string, pair<string, string> > a[N];

int main () {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        //printf("%d\n", n);
        //for (int i = 0; i <= 5e7; i++)

        for (int i = 0; i <= n+1 ; i++) adj[i].clear();
        while (!pq.empty()) pq.pop();

        string s, f;
        cin >> s >> f;
        //cout <<  s << " " << f << "\n";

        for (int i = 1; i <= n; i++)
            cin >> a[i].se.fi >> a[i].se.se >> a[i].fi;
            //cout << a[i].se.fi << a[i].se.se << a[i].fi;
        if (s == f) {
            printf("impossivel\n");
            continue;
        }
        //---------------------------------------------------
        for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (a[i].fi[0] != a[j].fi[0] &&
                (  a[i].se.fi == a[j].se.fi
                || a[i].se.fi == a[j].se.se
                || a[i].se.se == a[j].se.fi
                || a[i].se.se == a[j].se.se))
            adj[i].push_back(mp(j, (int) a[j].fi.size())),
            adj[j].push_back(mp(i, (int) a[i].fi.size()));
        }

        for (int i = 1; i <= n; i++)
            if (a[i].se.fi == s || a[i].se.se == s)
                adj[0].push_back(mp(i, (int) a[i].fi.size()));

        for (int i = 1; i <= n; i++)
            if (a[i].se.fi == f || a[i].se.se == f)
                adj[i].push_back(mp(n+1, 0));

        /*for (int i = 0; i <= n+1; i++) {
            for (int j = 0; j < adj[i].size(); j++) printf("(%d, %d)", adj[i][j].fi, adj[i][j].se);
            printf("\n");
        }*/
        //---------------------------------------------------
        for (int i = 1; i <= n+1; i++) d[i] = oo;
        d[0] = 0; pq.push(mp(0, 0));
        while (!pq.empty()) {
            ii t = pq.top(); pq.pop();
            int dist = t.fi, u = t.se;
            if (dist > d[u]) continue;
            for (int j = 0; j < adj[u].size(); j++) {
                ii v = adj[u][j];
                if (d[v.fi] > d[u] + v.se) {
                    par[v.fi] = u;
                    d[v.fi] = d[u] + v.se;
                    pq.push(mp(d[v.fi], v.fi));
                }
            }
        }
        if (d[n+1] == oo) printf("impossivel\n");
        else printf("%d\n", d[n+1]);
        //for (int i = 0; i <= n+1; i++) cout << par[i] << " ";
    }
}
