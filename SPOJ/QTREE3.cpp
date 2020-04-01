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

const int N = 1e5 + 10;
int idx, num[N], head[N], dep[N], nChild[N], par[N], vtx[N], a[N];
vector<int> adj[N];
int IT[4*N], n, q;

void preComp(int u) {
    nChild[u] = 0;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u])
            par[v] = u, preComp(v), nChild[u] += 1+nChild[v];
    }
}
void hld(int u) {
    num[u] = ++idx;
    vtx[idx] = u;
    int super = -1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super]))
            super = v;
    }
    if (super != -1) {
        dep[super] = dep[u], head[super] = head[u];
        hld(super);
    }
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (v != par[u] && v != super) {
            head[v] = v;
            dep[v] = dep[u] + 1;
            hld(v);
        }
    }
}

void build(int IT[], int p, int l, int r) {
    if (l == r) IT[p] = r;
    else {
        IT[p] = r;
        int mid = (l+r)/2;
        build(IT, 2*p, l, mid);
        build(IT, 2*p+1, mid+1, r);
    }
}
void update(int IT[], int p, int l, int r, int i) {
    if (r < l || i < l || r < i) return;
    if (l == i && i == r) return;
    else {
        int mid = (l+r)/2;
        update(IT, 2*p, l, mid, i);
        update(IT, 2*p+1, mid+1, r, i);
        int p1 = IT[2*p], p2 = IT[2*p+1];
        IT[p] = (a[p1] == 1) ? p1 : p2;
    }
}
int rmq(int IT[], int p, int l, int r, int L, int R) {
    if (R < l || r < L || r < l || R < L) return -1;
    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        int p1 = rmq(IT, 2*p, l, mid, L, R);
        int p2 = rmq(IT, 2*p+1, mid+1, r, L, R);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (a[p1] == 1) ? p1 : p2;
    }
}
int ans(int u) {
    //printf("ans\n");
    int res = 1, tmp;
    while (head[u] != 1) {
        tmp = rmq(IT, 1, 1, n, num[head[u]], num[u]);
        //printf("%d %d\n", u, tmp);
        if (a[tmp] == 1) res = tmp;
        u = par[head[u]];
    }
    tmp = rmq(IT, 1, 1, n, 1, num[u]);
    if (a[tmp] == 1) res = tmp;
    //printf("==> %d\n", res);
    return res;
}
int main() {

    scanf("%d %d", &n, &q);

    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    idx = 0; num[1] = 0; head[1] = 1; dep[1] = 0;
    preComp(1); hld(1);
    build(IT, 1, 1, n);

    /*for (int i = 1; i <= n; i++) cout << num[i] << " \n"[i==n];
    for (int i = 1; i <= n; i++) cout << head[i] << " \n"[i==n];
    for (int i = 1; i <= n; i++) cout << par[i] << " \n"[i==n];*/

    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == 0) {
            a[num[y]] = 1-a[num[y]];
            update(IT, 1, 1, n, num[y]);
            //for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
        }
        else {
            int res = ans(y);
            printf("%d\n", (a[res] == 0) ? -1 : vtx[res]);
        }

    }
}
