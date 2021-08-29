#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define task "WC3"
typedef pair<int, int> ii;
struct Query {
    char type;
    int u, v, c;
};

const int N = 1e5 + 5;

int tc, n, q;
int lab[N], rnk[N], mark[N];
long long sum[N];
vector<ii> adj[N];
Query que[N];

void dfs(int u) {
    mark[u] = 1;
    for (int i = 0; i < (int) adj[u].size(); i ++) {
        ii v = adj[u][i];
        if (!mark[v.fi]) {
            //anc[v.fi][0] = u;
            //dep[v.fi] = dep[u] + 1;
            sum[v.fi] = sum[u] + v.se;
            dfs(v.fi);
        }
    }
}

int root(int u) {
    if (lab[u] == -1) return u;
    else return lab[u] = root(lab[u]);
}

void join(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (rnk[u] > rnk[v]) {
        lab[v] = u;
    } else {
        lab[u] = v;
        rnk[v] += (rnk[u] == rnk[v]);
    }
}

// void initLCA() {
//     for (int d = 1; d <= 20; d ++) {
//         for (int u = 1; u <= n; u ++) {
//             if (dep[u] <= (1 << d)) {
//                 anc[u][d] = anc[anc[u][d-1]][d-1];
//                 sum[u][d] = sum[u][d-1] + sum[anc[u][d-1]][d-1];
//             }
//         }
//     }
// }

// int LCA(int u, int v) {
//     if (dep[u] > dep[v]) swap(u, v);
//     for (int d = 20; d >= 0; d --) {
//         if ((dep[v] - dep[u]) & (1 << d)) {
//             v = anc[v][d];
//         }
//     }
//     if (u == v) return u;
//     for (int d = 20; d >= 0; d--) {
//         if ((1 << d) <= dep[u] && anc[u][d] != anc[v][d]) {
//             u = anc[u][d];
//             v = anc[v][d];
//         }
//     }
//     return anc[u][0];
// }

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        scanf("%d%d", &n, &q);

        memset(lab, -1, sizeof lab);
        memset(rnk, 0, sizeof rnk);
        for (int i = 1; i <= n; i ++) adj[i].clear();

        for (int i = 1; i <= q; i ++) {
            scanf(" %c", &que[i].type);
            if (que[i].type == '!') {
                scanf("%d%d%d", &que[i].u, &que[i].v, &que[i].c);
                int u = que[i].u, v = que[i].v, c = que[i].c;
                if (root(u) != root(v)) {
                    join(u, v);
                    adj[u].push_back(mp(v, c));
                    adj[v].push_back(mp(u, -c));
                }
            } else {
                scanf("%d%d", &que[i].u, &que[i].v);
            }
        }

        memset(mark, 0, sizeof mark);
        memset(sum, 0, sizeof sum);

        for (int u = 1; u <= n; ++ u) {
            if (mark[u] == 0) {
                dfs(u);
            }
        }
 
        memset(lab, -1, sizeof lab);
        memset(rnk, 0, sizeof rnk);

        for (int i = 1; i <= q; i ++) {
            if (que[i].type == '!') {
                join(que[i].u, que[i].v);
            } else {
                int u = que[i].u, v = que[i].v;
                if (root(u) != root(v)) {
                    printf("UNKNOWN\n");
                } else {
                    printf("%lld\n", sum[v] - sum[u]);
                }
            }
        }
    }
}
