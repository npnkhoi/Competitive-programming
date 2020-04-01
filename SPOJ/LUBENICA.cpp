using namespace std;
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int N = 1e5 + 10;
const int oo = 1e9 + 17;
vector<pair<int, int> > adj[N];
int num[N], par[N], nChild[N], depvt[N], dep[N], head[N], idx;
int e[N];
int ITMin[4*N], ITMax[4*N];

void preComp(int u) {
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u]) {
            par[v] = u;
            //depvt[v] = depvt[u] + 1;
            preComp(v);
            nChild[u] += 1 + nChild[v];
        }
    }
}

void hld(int u) {
    num[u] = ++idx;
    int super = -1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super])) super = v;
    }
    if (super != -1) {
        head[super] = head[u];
        dep[super] = dep[u];
        hld(super);
    }
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u])
        if (v != super) {
            head[v] = v;
            dep[v] = dep[u] + 1;
            e[idx+1] = adj[u][j].se;
            hld(v);
        }
        else e[num[super]] = adj[u][j].se;
    }
}

int lca(int u, int v) {
    //printf("lca %d %d\n", u, v);
    while (head[u] != head[v]) {
        if (dep[u] < dep[v]) v = par[head[v]];
        else u = par[head[u]];
        //printf("%d %d\n", u, v);
    }
    //cout << num[u] << " " << num[v] << " " << ((num[u] < num[v]) ? u : v) << endl;
    return (num[u] < num[v]) ? u : v;
}

void build(int IT[], int a[], int p, int l, int r) {
    if (r < l) return;
    if (l == r) IT[p] = a[l];
    else {
        int mid = (l+r)/2;
        build(IT, a, 2*p, l, mid);
        build(IT, a, 2*p+1, mid+1, r);
        IT[p] = min(IT[2*p], IT[2*p+1]);
    }
}

int rmq(int IT[], int p, int l, int r, int L, int R) {
    if (r < l || R < L || r < L || R < l) return oo;

    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        return min(rmq(IT, 2*p, l, mid, L, R), rmq(IT, 2*p+1, mid+1, r, L, R));
    }
}
int main() {
    //freopen("test.inp", "r", stdin);
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }

    memset(par, -1, sizeof par);
    idx = 0; depvt[1] = 0;
    preComp(1);

    memset(head, -1, sizeof head);
    head[1] = 1; dep[1] = 0;
    hld(1);

    /*for (int i = 1; i <= n; i++) cout << num[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << head[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << dep[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << e[i] << " \n"[i == n];*/

    build(ITMin, e, 1, 1, n);
    for (int i = 1; i <= n; i++) e[i] = -e[i];
    build(ITMax, e, 1, 1, n);

    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int maxE = -oo, minE = oo;
        int t = lca(u, v);
        //printf("lca: %d (%d %d)\n", t, u, v);
        while (dep[u] > dep[t]) {
            maxE = max(maxE, -rmq(ITMax, 1, 1, n, num[head[u]], num[u]));
            minE = min(minE, rmq(ITMin, 1, 1, n, num[head[u]], num[u]));
            u = par[head[u]];
            //cout << minE << " " << maxE << endl;
        }
        maxE = max(maxE, -rmq(ITMax, 1, 1, n, num[t] + 1, num[u]));
        minE = min(minE, rmq(ITMin, 1, 1, n, num[t] + 1, num[u]));
        //cout << minE << " " << maxE << endl;
        //cout << "--\n";

        while (dep[v] > dep[t]) {
            maxE = max(maxE, -rmq(ITMax, 1, 1, n, num[head[v]], num[v]));
            minE = min(minE, rmq(ITMin, 1, 1, n, num[head[v]], num[v]));
            v = par[head[v]];
            //cout << minE << " " << maxE << endl;
        }
        maxE = max(maxE, -rmq(ITMax, 1, 1, n, num[t] + 1, num[v]));
        minE = min(minE, rmq(ITMin, 1, 1, n, num[t] + 1, num[v]));
        //cout << minE << " " << maxE << endl;
        printf("%d %d\n", minE, maxE);
    }
}
