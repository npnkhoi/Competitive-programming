using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int n, q;
const int N = 1e5 + 10;
pair<int, pair<int, int> > e[N];
vector<pair<int, int> > adj[N];
long long nChild[N], s;
int par[N];
void dfs(int u) {
    //printf("%d\n", u);
    nChild[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u])
            par[v] = u, dfs(v), nChild[u] += nChild[v];
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
        e[i] = mp(c, mp(u, v));
    }
    dfs(1);
    for (int i = 1; i < n; i++) {
        if (e[i].se.se == par[e[i].se.fi])
            swap(e[i].se.se, e[i].se.fi);
        s += nChild[e[i].se.se] * (n-nChild[e[i].se.se]) * e[i].fi;
        //cout << nChild[e[i].se.se] << endl;
    }
    scanf("%d", &q);
    while (q--) {
        int i, v;
        scanf("%d%d", &i, &v);
        s -= nChild[e[i].se.se] * (n-nChild[e[i].se.se]) * (e[i].fi - v);
        e[i].fi = v;
        printf("%.10f\n", 6.0*s/n/(n-1));
    }
}
