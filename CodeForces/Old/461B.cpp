using namespace std;
#include <stdio.h>
#include <vector>
#define pb push_back

const int N = 1e5 + 10;
const long long md = 1e9 + 7;
bool sign[N];
vector<int> adj[N];
int color[N], d[N], n;
long long res;
void dfs(int u) {
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (sign[v] == 0) {
            d[v] = d[u] + 1;
            if (color[v])
                res = (res*d[v]) % md, d[v] = 0;
            dfs(v);
        }
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x; scanf("%d", &x);
        adj[i].pb(x);
        adj[x].pb(i);
    }
   	int root = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &color[i]);
        if (color[i] == 1) root = i;
    }
    if (root == -1) printf("0");
    else {
        res = 1;
        d[root] = 0;
        dfs(root);
        printf("%d: \n", root);
        for (int i = 0; i < n; i++) printf("%d \n", d[i]);
        printf("%lld", res);
    }
}
