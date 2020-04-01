using namespace std;
#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii >
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 1e5 + 10;

int dep[N], num[N], head[N], nChild[N], par[N], tail[N], idx;
iii e[N];
int ftP[N], ftT[N];
int ans[N];
vector<ii> adj[N]; int n;

struct query {
    char type;
    int u, v, c, o;
} q[N];
bool cmp(query a, query b) {return a.c < b.c; }
/// HLD ------------------------------------------
void preComp(int u) {
    //printf("pre %d\n", u);
    nChild[u] = 0;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u])
            par[v] = u,
            //printf("%d->%d\n", u, v),
            preComp(v),
            nChild[u] += 1+nChild[v];
    }
}
void hld(int u) {
    //printf("hld %d\n", u);
    num[u] = ++idx;
    int super = -1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super]))
            super = v;
    }
    if (super != -1)
        head[super] = head[u], dep[super] = dep[u], hld(super);
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j].fi;
        if (v != par[u] && v != super)
            head[v] = v, dep[v] = dep[u] + 1, hld(v);
    }
    tail[u] = idx;
}
int lca(int u, int v) {
    while (head[u] != head[v])
        if (dep[u] < dep[v]) v = par[head[v]];
        else u = par[head[u]];
    return (num[u] < num[v])? u : v;
}

/// BIT --------------------------------------------
void update(int ft[], int p, int val) {
    for (; p <= n+1; p+= p&(-p)) ft[p] += val;
}
int rsq(int ft[], int p) {
    int res = 0;
    for (; p; p -= p&(-p)) res += ft[p];
    return res;
}
/// Offline Process ----------------------------------
void updateP(int u, int v) {
    //cout << "upP\n";
    if (par[u] == v) swap(u, v);
    update(ftP, num[v], +1); update(ftP, tail[v]+1, -1);
}
int ansP(int u, int v) {
    //printf("%d %d %d\n", rsq(ftP, u), rsq(ftP, v), rsq(ftP,lca(u, v)));
    //printf("ansP %d %d %d\n", u, v, lca(u, v));
    return rsq(ftP, num[u]) + rsq(ftP, num[v]) - 2*rsq(ftP,num[lca(u, v)]);
}
void updateT(int u, int v) {
    //cout << "upT\n";
    if (par[u] == v) swap(u, v);
    while (head[u] != 1) {
        //cout << u << endl;
        update(ftT, num[head[u]], +1);
        update(ftT, num[u] + 1, -1);
        u = par[head[u]];
    }
    //cout << "ok\n";
    update(ftT, 1, +1); update(ftT, num[u]+1, -1);
}
int ansT(int u, int v) {
    if (par[v] == u) return rsq(ftT, num[v]);
    else return n - rsq(ftT, num[v]) - 2;
}

int main() {
    //freopen("network.inp", "r", stdin);
    //freopen("network.out", "w", stdout);
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
        e[i] = mp(c, mp(u, v));
    }

    num[1] = 0; dep[1] = 0; head[1] = 1;
    preComp(1);
    hld(1);

    /*for (int i = 1; i <= n; i++) cout << nChild[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << num[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << head[i] << " \n"[i == n];
    for (int i = 1; i <= n; i++) cout << par[i] << " \n"[i == n];*/

    for (int i = 1; i <= m; i++) {
        scanf(" %c", &q[i].type);
        if (q[i].type == 'P') scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].c);
        else {
            int k;
            scanf("%d%d", &k, &q[i].c);
            q[i].u = e[k].se.fi;
            q[i].v = e[k].se.se;
        }
        q[i].o = i;
    }
    sort(q+1, q+m+1, cmp);
    sort(e+1, e+n);

    int cur = 1;
    for (int i = 1; i <= m; i++) {
        //printf("%c %d %d %d\n", q[i].type, q[i].u, q[i].v, q[i].c);
        for (; cur < n && e[cur].fi <= q[i].c; cur++) {
                updateP(e[cur].se.fi, e[cur].se.se);
                updateT(e[cur].se.fi, e[cur].se.se);
                /*for (int i  = 1; i <= n; i++) cout << rsq(ftP, num[i]) << " \n"[i == n];
                for (int i  = 1; i <= n; i++) cout << rsq(ftT, num[i]) << " \n"[i == n];*/
        }
        if (q[i].type == 'P')
            ans[q[i].o] = ansP(q[i].u, q[i].v);
        else
            ans[q[i].o] = ansT(q[i].u, q[i].v);
    }
    for (int i = 1; i <= m; i++) printf("%d\n",  ans[i]);
}
