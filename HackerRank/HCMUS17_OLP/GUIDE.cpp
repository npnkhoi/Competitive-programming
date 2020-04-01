using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 2e5 + 5;
vector<int> adj[N];
int num[N], tail[N], lab[N], dep[N], anc[N][22];
int n, m, q, cc, idx;
void dfs(int u, int h) {
    lab[u] = cc;
    dep[u] = h;
    num[u] = tail[u] = ++idx;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (num[v] == 0) {
            anc[v][0] = u;
            dfs(v, h+1);
            tail[u] = tail[v];
        }
    }
}
void init() {
    for (int j = 1; (1 << j) <= n; j++)
    for (int i = 1; i <= n; i++)
    if ((1 << j) <= dep[i]) anc[i][j] = anc[anc[i][j-1]][j-1];
}
int getAnc(int u, int d) {
    while (d) {
        u = anc[u][int(floor(log2(d&(-d))))];
        d -= d&(-d);
    }
    return u;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cc = 0; idx = 0;
    for (int i = 1; i <= n; i++) if (lab[i] == 0) {
        cc ++;
        dfs(i, 0);
    }
    init();
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &u, &v);
        if (lab[u] != lab[v]) printf("-1\n");
        else if (num[u] <= num[v] && num[v] <= tail[u])
            printf("%d\n", getAnc(v, dep[v] - dep[u] - 1));
        else printf("%d\n", anc[u][0]);
    }
    return 0;
}
/** Happy Coding ^^ */

