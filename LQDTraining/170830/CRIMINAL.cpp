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
const int N = 1e5 + 10;
int n, m, q, nCC, idx;
vector<int> adj[N];
int cc[N], num[N], low[N], tail[N], anc[32][N], dep[N];
bitset<N> art;
void dfs(int u) {
    cc[u] = nCC; num[u] = low[u] = tail[u] = ++idx;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v == anc[0][u]) continue;

        if (!num[v]) {
            anc[0][v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
            if (low[v] >= num[u]) art[u] = 1;
            low[u] = min(low[u], low[v]);
            tail[u] = tail[v];
        } else low[u] = min(low[u], num[v]);
    }
}
void preLCA() {
    for (int i = 1; (1<<i) <= n; i++)
    for (int u = 1; u <= n; u++) if ((1<<i) <= dep[u]) {
        anc[i][u] = anc[i-1][anc[i-1][u]];
        //printf("anc[%d][%d]: %d\n", i, u, anc[i][u]);
    }
}
bool ancDes(int u, int v) {
    return num[u] <= num[v] && num[v] <= tail[u];
}
int getAnc(int i, int u) {
    while (i > 0) {
        int t = int(floor(log2(i)));
        u = anc[t][u];
        i -= (1<<t);
    }
    return u;
}
void query1() {
    int a, b, u, v;
    scanf("%d %d %d %d", &a, &b, &u, &v);
    if (cc[a] != cc[b]) printf("no\n");
    else {
        if (num[u] > num[v]) swap(u, v);
        if (num[a] > num[b]) swap(a, b);
        //printf("%d %d %d %d\n", a, b, u, v);
        //printf("%d %d\n", low[v], num[u]);
        if (low[v] > num[u] && (ancDes(v, a) ^ ancDes(v, b))) printf("no\n");
        else printf("yes\n");
    }
}
void query2() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (cc[a] != cc[b]) printf("no\n");
    else if (art[c] == 0) printf("yes\n");
    else {
        if (ancDes(c, b)) swap(a, b);
        //cout << a << " " << b << " " << c << "\n";
        if (!ancDes(c, a)) printf("yes\n");
        else {
            int t = getAnc(dep[a] - dep[c] - 1, a);
            int z = getAnc(dep[b] - dep[c] - 1, b);
            //printf("==> %d %d\n", t, z);
            if (ancDes(c, b))
                if ((low[t] < num[c] && low[z] < num[c]) || t == z)
                    printf("yes\n"); else printf("no\n");
            else if (low[t] < num[c]) printf("yes\n"); else printf("no\n");
        }
    }
}
int main() {
    freopen("CRIMINAL.inp","r",stdin);
    freopen("CRIMINAL.out","w",stdout);
    scanf("%d%d", &n, &m);
    REP(z, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) if (num[i] == 0) nCC++, dfs(i);
    preLCA();
    scanf("%d", &q);
    REP(z, q) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) query1();
        else query2();
    }
    return 0;
}
/** Happy Coding ^^ */
