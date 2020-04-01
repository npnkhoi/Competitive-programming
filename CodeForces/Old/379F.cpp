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
const int N = 1e6 + 2;
int dep[N], anc[22][N];
int q, a, b, d, n;

int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[v] > dep[u])
        v = anc[int(floor(log2(dep[v] - dep[u])))][v];
    if (u == v) return u;
    for (int i = int(floor(log2(dep[u]))); i >= 0; i--)
    if ((1<<i) <= dep[u] && anc[i][u] != anc[i][v])
        u = anc[i][u], v = anc[i][v];
    return anc[0][u];
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2*dep[LCA(u, v)];
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    dep[2] = dep[3] = dep[4] = 1;
    anc[0][2] = anc[0][3] = anc[0][4] = 1;
    a = 2; b = 4; d = 2; n = 4;
    scanf("%d", &q);
    while (q--) {
        int t;
        scanf("%d", &t);
        dep[n+1] = dep[n+2] = dep[t] + 1;
        anc[0][n+1] = anc[0][n+2] = t;
        for (int i = 1; (1<<i) <= dep[n+1]; i++)
        anc[i][n+1] = anc[i][n+2] = anc[i-1][anc[i-1][n+2]];
        if (dist(a, n+1) > d) d = dist(a, n+1), b = n+1;
        if (dist(a, n+2) > d) d = dist(a, n+2), b = n+2;
        if (dist(n+1, b) > d) d = dist(n+1, b), a = n+1;
        if (dist(n+2, b) > d) d = dist(n+2, b), a = n+2;
        n += 2;
        printf("%d\n", d);
    }
    return 0;
}
/** Happy Coding ^^ */
