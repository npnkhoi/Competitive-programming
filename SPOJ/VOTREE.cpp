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
const int N = 7e4 + 5;
int n, q, u, v, IT[4*N], dep[N], anc[22][N];
bool sign[N];
vector<int> adj[N];
void init(int u) {
    sign[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (sign[v] == 0) {
            anc[0][v] = u;
            dep[v] = dep[u] + 1;
            init(v);
        }
    }
}
void preLCA() {
    for (int i = 1; (1<<i) <= n; i++)
    for (int u = 1; u <= n; u++)
    if ((1 << i) <= dep[u]) anc[i][u] = anc[i-1][anc[i-1][u]];
}
int LCA(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v]) v = anc[int(floor(log2(dep[v] - dep[u])))][v];
    if (u == v) return u;
    for (int i = int(floor(log2(dep[u]))); i >= 0; i--)
    if ((1 << i) <= dep[u] && anc[i][u] != anc[i][v]) {
        u = anc[i][u];
        v = anc[i][v];
    }
    return anc[0][u];
}
void build(int p, int l, int r) {
    if (l == r) IT[p] = l;
    else {
        int mid = (l + r) / 2;
        build(2*p, l, mid);
        build(2*p + 1, mid + 1, r);
        IT[p] = LCA(IT[2*p], IT[2*p+1]);
    }
}
int query(int p, int l, int r, int L, int R) {
    if (r < l || R < L || r < L || R < l) return -1;
    else if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l + r) / 2;
        int ans1 = query(2*p, l, mid, L, R);
        int ans2 = query(2*p+1, mid + 1, r, L, R);
        if (ans1 == -1) return ans2;
        else if (ans2 == -1) return ans1;
        else return LCA(ans1, ans2);
    }
}

int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &q);
    int u, v;
    REP(z, n-1) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1] = 0;
    init(1);
    preLCA();
    build(1, 1, n);
    //REP(i, 2*n) cout << IT[i] << " ";
    //cout << endl;
    //cout << query(1, 1, n, 2, 2);
    while (q--) {
        scanf("%d %d", &u, &v);
        //printf("? %d %d\n", u, v);
        printf("%d\n", query(1, 1, n, u, v));
    }
    return 0;
}
/** Happy Coding ^^ */
