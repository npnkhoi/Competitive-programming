using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>

#define fi first
#define se second

const int M = 1e4 + 10;
const int oo = 1e9;
int n, m;
pair<int, pair<int , int> > e[M];

class UFDS {
private: vector<int> p, Rank;
public:
    UFDS(int N) {
        Rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int Root(int u) {
        return (p[u] == u) ? u : (p[u] = Root(p[u]));
    }
    bool SameSet(int u, int v) {
        return (Root(u) == Root(v));
    }
    void Union(int u, int v) {
        int x = Root(u), y = Root(v);
        if (Rank[x] > Rank[y]) p[y] = x;
        else {
            p[x] = y;
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
};
int mst(int x) {
    //printf("%d: \n", x);
    int s = 0, cntCC = n, cnt = 0;
    UFDS uf(n + 4);
    for (int i = 0; i < m; i++){
        int u = e[i].se.se, v = e[i].se.fi;
        if (!uf.SameSet(u, v)) {
            if (cnt++ == x) continue;
            uf.Union(u, v), cntCC --, s += e[i].fi;
        }
    }
    return (cntCC == 1) ? s : oo;
}
int main() {
    //freopen("test.inp", "r", stdin);
    int tc; scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
            scanf("%d %d %d", &e[i].se.fi, &e[i].se.se, &e[i].fi);
        sort(e, e + m);
        printf("%d ", mst(n+1));
        int res = oo;
        for (int i = 0; i < n-1; i++) res = min(res, mst(i));
        printf("%d\n", res);
    }
}
