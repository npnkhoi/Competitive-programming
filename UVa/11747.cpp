using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>
#define fi first
#define se second

typedef pair<int, int> ii;

int n, m;

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

int main() {
    while (scanf("%d %d", &n, &m)) {
        if (!m && !n) break;
        pair<int , ii> e[m + 5];
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
        sort(e, e + m);

        UFDS UF(n + 5);
        bool forest = 1;
        for (int i = 0; i < m; i++) {
            int c = e[i].fi, u = e[i].se.fi, v = e[i].se.se;
            if (UF.SameSet(u, v)) {
                if (forest) forest = 0, printf("%d", c);
                else printf(" %d", c);
            }
            else UF.Union(u, v);
        }
        if (forest) printf("forest\n");
        else printf("\n");
    }

}
