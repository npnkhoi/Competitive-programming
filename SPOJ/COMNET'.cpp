#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int S = 105;
int tc, m, n, q, k, s, root[N], Rank[N], id[S], val[S];
struct edge {int u, v, c;} e[M];
int getRoot(int u) {return (u == root[u]) ? u : root[u] = getRoot(root[u]); };
void join(int u, int v) {
    u = getRoot(u), v = getRoot(v);
    if (u == v) return;
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        Rank[v] += Rank[u] == Rank[v];
    }
}
int main() {
    //freopen("0.in", "r", stdin);
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d", &n, &m, &q);
        REP(i, m) scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
        while (q--) {
            FOR(i, 1, n) root[i] = i;
            memset(Rank, 0, sizeof Rank);
            scanf("%d %d", &k, &s); k--;
            REP(i, s) {
                scanf("%d %d", &id[i], &val[i]);
                id[i] --;
                swap(e[id[i]].c, val[i]);
            }
            int tmp = e[k].c;
            REP(i, m) if (e[i].c < tmp) {
                join(e[i].u, e[i].v);
                //cout << i << endl;
            }
            if (getRoot(e[k].u) == getRoot(e[k].v)) printf("YES\n");
            else printf("NO\n");
            REP(i, s) swap(e[id[i]].c, val[i]);
        }
    }
}
