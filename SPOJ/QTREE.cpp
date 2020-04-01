using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii >

const int N = 1e4 + 10;
int idx, num[N], head[N], dep[N], nChild[N], par[N], e[N], numE[N];
vector<iii> adj[N];
int IT[4*N], n;

void preComp(int u) {
    nChild[u] = 0;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u])
            par[v] = u, preComp(v), nChild[u] += 1+nChild[v];
    }
}
void hld(int u) {
    num[u] = ++idx;
    int super = -1;
    ii tmp;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super]))
            super = v, tmp = adj[u][j].se;
    }
    if (super != -1) {
        dep[super] = dep[u], head[super] = head[u];
        numE[tmp.se] = idx+1;
        e[idx+1] = tmp.fi;
        hld(super);
    }
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u] && v != super) {
            head[v] = v;
            dep[v] = dep[u] + 1;
            e[idx+1] = adj[u][j].se.fi;
            numE[adj[u][j].se.se] = idx+1;
            hld(v);
        }
    }
}
int lca(int u, int v) {
    while (head[u] != head[v]) {
        if (dep[u] < dep[v]) v = par[head[v]];
        else u = par[head[u]];
    }
    return (num[u] < num[v]) ? u : v;
}
void build(int IT[], int a[], int p, int l, int r) {
    if (r < l) return;
    if (l == r) IT[p] = a[l];
    else {
        int mid = (l+r)/2;
        build(IT, a, 2*p, l, mid);
        build(IT, a, 2*p+1, mid+1, r);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
void update(int IT[], int p, int l, int r, int i, int val) {
    if (r < l || i < l || r < i) return;
    if (l == i && i == r) IT[p] = val;
    else {
        int mid = (l+r)/2;
        update(IT, 2*p, l, mid, i, val);
        update(IT, 2*p+1, mid+1, r, i, val);
        IT[p] = max(IT[2*p], IT[2*p+1]);
    }
}
int rmq(int IT[], int p, int l, int r, int L, int R) {
    if (R < l || r < L || r < l || R < L) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        return max(rmq(IT, 2*p, l, mid, L, R), rmq(IT, 2*p+1, mid+1, r, L, R));
    }
}
int maxE(int u, int v) {
    //printf("maxE %d %d\n", u, v);
    int res = -1;
    while (head[u] != head[v]) {
        res = max(res, rmq(IT, 1, 1, n, num[head[v]], num[v]));
        v = par[head[v]];
    }
    //printf("%d %d\n", num[u] + 1, num[v]);
    res = max(res, rmq(IT, 1, 1, n, num[u] + 1, num[v]));
    //cout << res << endl;
    return res;
}
int main() {
    //freopen("test.inp", "r", stdin);
    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        //cout << n << endl;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            //cout << u << v << c << "\n";
            adj[u].pb(mp(v, mp(c, i)));
            adj[v].pb(mp(u, mp(c, i)));
        }
        idx = 0; num[1] = 0; head[1] = 1; dep[1] = 0;
        preComp(1); hld(1);
        build(IT, e, 1, 1, n);
        /*for (int i = 1; i <= n; i++) cout << num[i] << " \n"[i==n];
        for (int i = 1; i <= n; i++) cout << head[i] << " \n"[i==n];
        for (int i = 1; i <= n; i++) cout << par[i] << " \n"[i==n];*/

        char cmd[10];
        int x, y;

        while (scanf("%s", &cmd)) {
            //cout << cmd << endl;
            if (cmd[0] == 'D') break;
            scanf("%d %d", &x, &y);
            if (cmd[0] == 'Q') {
                //cout << "1\n";
                int a = lca(x, y);
                //cout << a << "\n";
                printf("%d\n", max(maxE(a, x), maxE(a, y)));
            }
            else update(IT, 1, 1, n, numE[x], y);
        }
    }
}
