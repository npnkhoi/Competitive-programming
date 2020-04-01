#include <stdio.h>
#include <vector>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i, n) for (int i = 0; i < n; i++)

const int N = 1e4 + 10;
int n, m;
vector<int> adj[N];
int idx, root, rootChild, num[N], low[N], par[N];
bool art[N];
int cntArt, cntBri;
void dfs(int u) {
    //printf("%d\n", u);
    num[u] = low[u] = ++idx;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!num[v]) {
            if (u == root) rootChild ++;
            par[v] = u;
            dfs(v);
            if (low[v] >= num[u]) art[u] = 1;
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                cntBri ++;
                //printf("Bri: %d %d\n", u, v);
            }
        }
        else if (v != par[u]) low[u] = min(low[u], num[v]);
    }
}
int main() {
    scanf("%d %d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    idx = 0;
    FOR(u, 1, n) if (!num[u]) {
        root = u;
        rootChild = 0;
        dfs(root);
        art[root] = (rootChild > 1);
        //printf("RC: %d\n", rootChild);
    }
    FOR(i, 1, n) {
        cntArt += art[i];
        //if (art[i]) printf("Art: %d\n", i);
    }
    //FOR(i, 1, n) printf("%3d", num[i]); printf("\n");
    //FOR(i, 1, n) printf("%3d", low[i]); printf("\n");
    printf("%d %d\n", cntArt, cntBri);
}
