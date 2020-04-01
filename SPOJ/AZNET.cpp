using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> edge;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int M = 1e5 + 10;
const int N = 1e4 + 4;
const ll oo = 1e15;
int n, m, na, nb, cnt, mark, maxA, maxB;
edge e[2][M];
int root[N], Rank[N], sign[M];
ll a[N], b[N], res;
int getRoot(int u) { return (root[u] == u) ? u : root[u] = getRoot(root[u]); }
bool same(int u, int v) { return getRoot(u) == getRoot(v); }
void join(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        if (Rank[u] == Rank[v]) Rank[v] ++;
    }
}
void init() {
    FOR(i, 1, n) root[i] = i;
    memset(Rank, 0, sizeof Rank);
}
int main() {
    //freopen("test.in", "r", stdin);
    //freopen("", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(z, 1, tc) {
        scanf("%d %d", &n, &m);
        FOR(i, 1, n-1) scanf("%lld", &a[i]);
        FOR(i, 1, n-1) scanf("%lld", &b[i]);
        int u, v, type, na = 0, nb = 0;
        FOR(i, 1, m) {
            scanf("%d %d %d", &u, &v, &type);
            if (type == 1) e[0][++na] = mp(i, mp(u, v));
            else e[1][++nb] = mp(i, mp(u, v));
        }
        // --------------------------------------
        maxA = maxB = 0;
        init();
        FOR(i, 1, na)
        if (!same(e[0][i].se.fi, e[0][i].se.se)) {
            join(e[0][i].se.fi, e[0][i].se.se);
            maxA ++;
        }
        init();
        FOR(i, 1, nb)
        if (!same(e[1][i].se.fi, e[1][i].se.se)) {
            join(e[1][i].se.fi, e[1][i].se.se);
            maxB ++;
        }

        memset(sign, 0, sizeof sign);
        FOR(i, 1, na)
        if (!same(e[0][i].se.fi, e[0][i].se.se)) {
            join(e[0][i].se.fi, e[0][i].se.se);
            sign[i] = 1;
        }
        init();
        FOR(i, 1, na) if (sign[i]) {
            join(e[0][i].se.fi, e[0][i].se.se);
            printf("%d ", e[0][i].fi);
        }
        //----------------------------------------

        res = oo;
        FOR(i, n - 1 - maxB, maxA)
        if (res > a[i] + b[n-1-i]) {
            res = a[i] + b[n-1-i];
            mark = i;
        }
        cnt = 0; mark -= n-1-maxB;
        //printf("%d %d %d\n", maxA, maxB, mark);
        for (int i = 1; i <= na && mark > 0; i++)
        if (!same(e[0][i].se.fi, e[0][i].se.se)) {
            mark --;
            join(e[0][i].se.fi, e[0][i].se.se);
            printf("%d ", e[0][i].fi);
        }
        FOR(i, 1, nb) if (!same(e[1][i].se.fi, e[1][i].se.se)) {
            join(e[1][i].se.fi, e[1][i].se.se);
            printf("%d ", e[1][i].fi);
        }
        printf("\n");
        //printf("z: %d\n", z);
    }
    return 0;
}
/** Happy Coding ^^ */
