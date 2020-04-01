using namespace std;
#include <vector>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>

#define fi first
#define se second
#define mp make_pair
#define For(i, a, b) for (int i = a; i <= b; i++)

typedef pair<int, int> ii;
const int N = 1e3 + 10;

ii p[N];
vector<pair<double, ii> > e;

class UFDS {
private: vector<int> par, Rank;
public:
    UFDS (int n) {
        par.assign(n + 5, 0);
        for (int i = 0 ; i < n; i++) par[i] = i;
        Rank.assign(n + 5, 0);
    }

    int Root(int u) { return (u == par[u]) ? u : (par[u] = Root(par[u])); }
    bool SameSet(int u, int v) { return Root(u) == Root(v); }
    void Union(int u, int v) {
        int x = Root(u), y = Root(v);
        if (x == y) return;

        if (Rank[x] > Rank[y]) par[y] = x;
        else {
            par[y] = x;
            if (Rank[x] == Rank[y]) Rank[y] ++;
        }
    }
};


int main() {
    int TC;
    scanf("%d", &TC);
    For(tc, 1, TC) {
        int n, r;
        scanf("%d %d", &n, &r);
        For(i, 1, n) scanf("%d %d", &p[i].fi, &p[i].se);
        e.clear();
        For (i, 1, n-1) For(j, i+1, n) {
            double d = (p[i].fi - p[j].fi)*(p[i].fi - p[j].fi)
                     + (p[i].se - p[j].se)*(p[i].se - p[j].se);

            e.push_back(mp(sqrt(d), ii(i, j)));
        }

        double res = 0;
        int cnt = 0;
        bool oneState = 1;

        sort(e.begin(), e.end());

        UFDS UF(n + 5);
        printf("Case #%d: ", tc);

        for (int i = 0; i < n*n; i++) {
            double w = e[i].fi;
            int u = e[i].se.fi, v = e[i].se.se;

            //printf("%f %d %d\n", w, u, v);

            if (oneState == 1 && (w > r))
                oneState = 0,
                printf("%d %.0f ", n - cnt, res),
                res = 0;

            if (!UF.SameSet(u ,v)) {
                res += w;
                UF.Union(u, v);
                cnt ++;
            }

            if (cnt == n-1) {
                if (oneState) printf("1 %.f 0\n", res);
                else printf("%.0f\n", res);
                break;
            }
        }
    }
}
