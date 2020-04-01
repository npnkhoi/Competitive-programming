using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#define fi first
#define se second
pair<long long, pair<int, int> > e[1010];
long long ans[110][110];

class UFDS {
private: vector<int> par, Rank;
public:
    UFDS (int n) {
        par.assign(n, 0);
        for (int i = 0; i < n; i++) par[i] = i;
        Rank.assign(n, 0);
    }

    int Root(int u) {return (u == par[u]) ? u : (par[u] = Root(par[u])); }
    bool SameSet(int u, int v) {return Root(u) == Root(v); }
    void Union(int u, int v) {
        int x = Root(u), y = Root(v);
        if (x == y) return;
        if (Rank[x] > Rank[y]) par[y] = x;
        else {
            par[x] = y;
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
};

int main () {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int tc = 0;
    int n, m, q;
    while (scanf("%d %d %d", &n, &m, &q)) {
        if (!m && !n && !q) break;
        if (tc) printf("\n");
        for (int i = 0; i < m; i++)
            scanf("%d %d %lld", &e[i].se.fi, &e[i].se.se, &e[i].fi);
        sort(e, e + m);

        UFDS uf(n + 5);
        memset(ans, -1, sizeof ans);

        for (int i = 0 ; i < m; i++) {
            int u = e[i].se.fi, v = e[i].se.se;
            long long c = e[i].fi;

            int x = uf.Root(u), y = uf.Root(v);
            if (x != y) {
                for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                if (uf.Root(i) == x && uf.Root(j) == y) ans[i][j] = ans[j][i] = c;
                uf.Union(x, y);
            }
        }
        printf("Case #%d\n", ++tc);
        while (q--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (ans[u][v] == -1) printf("no path\n");
            else printf("%lld\n", ans[u][v]);
        }
    }
}
