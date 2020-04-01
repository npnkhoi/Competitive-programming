using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1e3 + 5;
typedef pair<int, pair<ii, ii> > edge;
int n, cur, wei[N*N], a[N][N], res, Rank[N*N], root[N*N], nChild[N*N];
vector<pair<int, ii> > v;

bool inside(const int &x, const int &y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}
int getRoot(int u) {
    if (wei[u] != cur) {
        nChild[u] = Rank[u] = 0;
        wei[u] = cur;
        return root[u] = u;
    }
    return (root[u] == u) ? u : root[u] = getRoot(root[u]);
}
void join(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (u == v) return;
    if (Rank[u] > Rank[v]) {
        root[v] = u;
        nChild[u] += 1+nChild[v];
    } else {
        root[u] = v;
        nChild[v] += 1+nChild[u];
        Rank[v] += Rank[u] == Rank[v];
    }
}
int main() {
    freopen("rselect.inp","r",stdin);
    freopen("rselect.out","w",stdout);
    scanf("%d", &n);
    REP(i, n) REP(j, n) {
        scanf("%d", &a[i][j]);
        if (i) v.push_back(mp(abs(a[i][j] - a[i-1][j]), mp(i*n+j, (i-1)*n+j)));
        if (j) v.push_back(mp(abs(a[i][j] - a[i][j-1]), mp(i*n+j, i*n+(j-1))));
    }
    sort(v.begin(), v.end());
    memset(wei, -1, sizeof wei);
    REP(i, v.size()) {
        cur = v[i].fi;
        int v1 = v[i].se.fi, v2 = v[i].se.se;
        //cout << i;
        if (getRoot(v1) != getRoot(v2)) {
            join(v1, v2);
            res = max(res, nChild[getRoot(v1)]+1);
        }
    }
    printf("%d\n", res);
    cerr << res;
    return 0;
}
/** Happy Coding ^^ */
