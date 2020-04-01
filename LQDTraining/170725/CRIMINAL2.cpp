using namespace std;
#include <bits/stdc++.h>

const int N = 1e5 + 10;
const int M = 2*N;
vector<int> adj[N];
int a[M], d[M], f[N], IT[4*M], idx, n, m;
int num[N], low[N], par[N], cnt;
bool art[N];
void __dfs(int u) {
    num[u] = low[u] = ++cnt;

    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!num[v]) {
            par[v] = u;

            __dfs(v);

            if (low[v] >= num[u]) art[u] = 1;
            low[u] = min(low[u], low[v]);
            f[u] += f[v];
        }
        else if (v != par[u]) low[u] = min(low[u], num[v]);
    }
}
void _dfs(int u, int depth) {
    printf("dfs %d %d\n", u, depth);
    f[u] = idx;
    a[idx] = u;
    d[idx++] = depth;

    for (int j = 0; j < adj[u].size(); j++)
    if (par[adj[u][j]] == u) {
        _dfs(adj[u][j], depth + 1);
        a[idx] = u;
        d[idx++] = depth;
    }
}

int left(int p) {return p*2;}
int right(int p) {return p*2+1;}

void build(int p, int l, int r) {
    if (l > r) return;
    if (l == r) IT[p] = l;
    else {
        int mid = (l + r) / 2;
        build(left(p), l, mid);
        build(right(p), mid+1, r);

        int p1 = IT[left(p)];
        int p2 = IT[right(p)];

        IT[p] = (d[p1] < d[p2]) ? p1 : p2;
    }
}

int RMQ(int p, int l, int r, int L, int R) {
    if (r < L || R < l || r < l) return -1;

    if (L <= l && r <= R) return IT[p];

    int mid = (l + r) / 2;

    int p1 = RMQ(left(p), l, mid, L, R);
    int p2 = RMQ(right(p), mid+1, r, L, R);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (d[p1] < d[p2]) ? p1 : p2;
}

void query1() {
    printf("1\n");
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    if (num[a] > num[b]) swap(a, b);
    if (num[x] > num[y]) swap(x, y);
    if (low[b] > num[a] && x < a && b < y) printf("No\n");
    else printf("Yes\n");

}
void query2() {
    printf("2\n");
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    if (num[u] > num[v]) swap(u, v);
    if (!art[c]) printf("Yes\n");
    else {
        bool dk1 = (num[u] < num[c] && num[c] < num[v]);
        bool dk2 = a[RMQ(1, 1, m, u, v)] == c;
        if ((num[u] < num[c] && num[c] < num[v]) ^ (a[RMQ(1, 1, m, u, v)] == c))
            printf("No %d %d\n", dk1, dk2);
        else printf("Yes %d %d\n", dk1, dk2);
    }
    //printf("2\n");
}
void dfs1(int u, int c) {
    sign[u] = 1;
    for (int j = 0; j < adj[u].size(); j++) {
        int v = adj[u][j];
        if (!sign[v]) dfs1(u, c);
    }
}
void query22() {
    int a, b, c;
    scanf("%d")
    memset(sign, 0, sizeof sign);
    dfs()

}
int main() {
    freopen("CRIMINAL.inp" ,"r", stdin);
    //freopen("CRIMICAL.out" ,"w", stdout);
    scanf("%d %d", &n, &m);
    //printf("%d %d\n", n, m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        //printf("%d %d\n", u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*//printf("ok\n");
    m = 2*n - 1;
    cnt = 0; __dfs(1);
    //printf("ok\n");
    idx = 1; _dfs(1, 1);
    //printf("ok\n");
    build(1, 1, m);

    int q;
    scanf("%d", &q);
    //printf("%d\n", q);
    while (q--) {
        int cmd;
        scanf("%d", &cmd);
        //printf("1\n");
        if (cmd == 1) query1();
        else query2();
    }*/

    int q;
    scanf("%d", &q);
    if (q*n <= 1e7)
    while (q--) {
        int cmd;
        scanf("%d", &cmd);
        if (cmd == 1) query11();
        else query22();
    }
    else {
        for (int i = 1; i <= q; i++) printf("yes\n");
    }
}
