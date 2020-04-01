#include <stdio.h>
#include <utility>
#include <vector>
#define fi first
#define se second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 2e5 + 10;
const ll oo = 1e17 + 2;

vector<int> adj[N];
ll w[N], des1[N];
pll des2[N];
int par[N];

void push(ll val, pll &a) { /// max heap
    if (val > a.fi) a.se = a.fi, a.fi = val;
    else if (val > a.se) a.se = val;
}

void update(pll &a, const pll b) {
    if (a.fi + a.se < b.fi + b.se) a = b;
}

void dfs(int u) {
    //printf("dfs %d\n", u);
    des1[u] = -oo; des2[u] = mp(-oo, -oo);
    pll tmp = mp(-oo, -oo);
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u]) {
            par[v] = u;

            dfs(v);

            des1[u] = max(des1[u], des1[v]);
            update(des2[u], des2[v]);
            push(des1[v], tmp);
            w[u] += w[v];
        }
    }
    des1[u] = max(des1[u], w[u]);
    update(des2[u], tmp);
    //printf("vetex %d: %lld, (%lld, %lld)\n", u, des1[u], des2[u].fi, des2[u].se);

}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if (des2[1].se == -oo) printf("Impossible");
    else printf("%lld", des2[1].fi + des2[1].se);
}
