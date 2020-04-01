using namespace std;
#include <stdio.h>
#include <vector>
#include <cmath>

const int N = 2e5 + 10;
const int md = 1e9 + 7;

vector<int> adj[N];
vector<int> sign (N, -1);
int cc, cyc;
int p[N];
long long Pow[N], res;

void dfs(int u) {
    //printf("dfs %d\n", u);
    cc ++;
    bool meet = 0;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (sign[v] == -1) sign[v] = sign[u] + 1, p[v] = u, dfs(v);
        else if (v != p[u]) cyc = abs(sign[u] - sign[v]) + 1;
        else if (meet) cyc = 2; else meet = 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        adj[i].push_back(u);
        adj[u].push_back(i);
    }

    Pow[0] = 1;
    for (int i = 1; i <= n; i++) Pow[i] = (Pow[i-1] + Pow[i-1]) % md;

    for (int i = 0; i <= n; i++) p[i] = i;

    res = 1;

    for (int i = 1; i <= n; i++) if (sign[i] == -1) {
        cc = cyc = 0, sign[i] = 0, dfs(i);
        //printf("%d %d\n", cyc, cc);
        if (cyc) res = ((res * Pow[cc-cyc]) % md * (Pow[cyc] - 2)) % md;
    }
    printf("%I64d", res);
}
