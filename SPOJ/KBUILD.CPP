using namespace std;
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <string.h>
#include <vector>
#include <queue>

#define iii pair<pair<int, int>, int>
#define mp make_pair
#define fi first
#define se second
const int N = 2e5 + 10;
vector<int> adj[N];
bitset<N> sign;
priority_queue<iii> pq;
int n, m;
int idx, num[N], par[N], nChild[N], head[N], dep[N], depvtx[N];

void preComp(int u) { /// nChild, par
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u]) {
            par[v] = u;
            depvtx[v] = depvtx[u] + 1;
            preComp(v);
            nChild[u] += 1 + nChild[v];
        }
    }
}
void hld(int u) { /// num, head, dep
    //printf("%d\n", u);
    num[u] = ++idx;
    if (head[u] == -1) head[u] = u;
    dep[u] = (par[u] == -1)? 0: dep[head[par[u]]] + 1;
    int super = -1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u] && (super == -1 || nChild[super] < nChild[v]))
            super = v;
    }
    if (super != -1) head[super] = head[u], hld(super);
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u] && v != super) hld(v);
    }
}
int lca(int u, int v) {
    //printf("lca %d %d \n", u, v);
    while (head[u] != head[v]) {
        if (dep[head[u]] > dep[head[v]]) u = par[head[u]];
        else v = par[head[v]];
        //printf("%d %d\n", u, v);
    }
    return (num[u] < num[v])? u : v;
}
int main() {
    //freopen("test.inp", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par, -1, sizeof par);
    memset(nChild, 0, sizeof nChild);
    depvtx[1] = 0;
    preComp(1);
    idx = 0;
    memset(head, -1, sizeof head);
    hld(1);

    //printf("ok\n");

    scanf("%d", &m);
    while (m--) {
        int u, v, t;
        scanf("%d %d", &u, &v);
        t = lca(u, v);
        //cout << t << endl;
        if (t != u)
            pq.push(mp(mp(depvtx[u], -depvtx[t]), u));
        if (t != v)
            pq.push(mp(mp(depvtx[v], -depvtx[t]), v));
    }
    sign.reset();
    int res = n-1;
    while (!pq.empty()) {
        iii t = pq.top(); pq.pop();
        int y = t.fi.fi, x = -t.fi.se, u = t.se;
        //cout << y << " " << x << " " << u << endl;
        if (sign[u]) continue;
        sign[u] = 1; res --;
        if (y-x > 1) {
            //cout << "push " << y << " " << x << endl;
            pq.push(mp(mp(y-1, -x), par[u]));
        }
    }
    cout << res;
}
