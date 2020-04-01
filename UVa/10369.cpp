using namespace std;

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define fi first
#define se second
const int N = 510;

vector<pair<double, pair<int, int> > > e;
pair<int, int> p[N];

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

int main () {
    //freopen("test.inp", "r", stdin);
    int tc, k, n;
    scanf("%d", &tc);
    while (tc--) {
        e.clear();
        scanf("%d %d", &k, &n);
        for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].fi, &p[i].se);
        for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++) {
            double d = (p[i].fi - p[j].fi) * (p[i].fi - p[j].fi)
                        + (p[i].se - p[j].se) * (p[i].se - p[j].se);
            e.push_back(make_pair(sqrt(d), make_pair(i, j)));
        }
        sort(e.begin(), e.end());
        UFDS uf(n+5);
        int cntCC = n;
        int i = -1;
        while (cntCC > k) {
            i ++;
            int u = e[i].se.fi, v = e[i].se.se;
            if (!uf.SameSet(u, v))
                uf.Union(u, v), cntCC --;
        }
        printf("%.2f\n", e[i].fi);
    }
}

