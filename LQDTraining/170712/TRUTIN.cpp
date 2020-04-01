using namespace std;
#include <stdio.h>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1e3 + 10;
const int K = 210;

int n, k;
char str[N][K];
vector<int> adj[N];
int c[N][N], s[N], pre[N], ans[N];
bool sign[N];
int res;
set<ii> data;
vector<pair<int, ii> > e;

class UFDS {
private: vector<int> p, Rank;
public:
    UFDS(int n) {
        Rank.assign(n, 0);
        p.assign(n, -1);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int Root(int u) {return (u == p[u]) ? u : (p[u] = Root(p[u])); }

    bool SameSet(int u, int v) {return Root(u) == Root(v); }

    void Union(int u, int v) {
        int x = Root(u), y = Root(v);

        if (Rank[x] > Rank[y]) p[y] = x;
        else {
            p[x] = y; Rank[y] += (Rank[y] == Rank[x]);
        }
    }
};

void dfs(int u) {
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!sign[v])
            printf("%d %d\n", v, (c[u][v] < k) ? u : 0),
            dfs(v);
    }
}

int main() {
    freopen("trutin.inp", "r", stdin);
    freopen("trutin.out", "w", stdout);
    scanf("%d %d\n", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%s", &str[i]);
    for (int i = 1; i < n; i++)
    for (int j = i+1; j <= n; j++) {
        int t = 0;
        for (int x = 0; x < k; x ++) t += (str[i][x] != str[j][x]);
        t = min(t << 1, k);
        e.push_back(mp(t, ii(i, j)));
        c[i][j] = c[j][i] = t;
    }

    sort(e.begin(), e.end());

    UFDS UF(n + 5);

    for (int i = 0, cnt = 0; i < e.size(); i++) {
        int u = e[i].se.fi, v = e[i].se.se;

        if (!UF.SameSet(u, v)) {
            cnt ++;
            UF.Union(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            res += e[i].fi;
        }
        if (cnt == n-1) break;
    }

    printf("%d\n", res + k);

    memset(sign, 0, sizeof sign);

    printf("1 0\n");
    dfs(1);
}
