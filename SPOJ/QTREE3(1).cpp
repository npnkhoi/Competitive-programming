//#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "qtree3"
typedef long long ll;
//typedef pair<int, int> ii;
const int N = 1e5 + 5;
vector<int> adj[N];
int n, q, vtx;
int num[N], id[N], nChild[N], par[N], head[N], color[N];
int ft[N];
void dfs(int u) {
    nChild[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (nChild[v] == 0) {
            par[v] = u;
            dfs(v);
            nChild[u] += 1 + nChild[v];
        }
    }
}
void HLD(int u) {
    num[u] = ++ vtx;
    id[vtx] = u;
    if (head[u] == 0) head[u] = u;

    int super = -1;

    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != par[u] && (super == -1 || nChild[v] > nChild[super]))
            super = v;
    }
    if (super != -1) {
        head[super] = head[u];
        HLD(super);
    }
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (v != super && v != par[u]) HLD(v);
    }
}
void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) ft[idx] += val;
}
int get(int idx) {
    int res = 0;
    for (; idx > 0; idx -= idx & -idx) res += ft[idx];
    return res;
}
int get(int l, int r) {
    return get(r) - get(l-1);
}
int firstBlack(int l, int r) {
    //printf("first black %d %d\n", l, r);
    while (l < r) {
        int mi = (l+r)/2;
        if (get(l, mi)) r = mi;
            else l = mi+1;
    }
    return id[l];
    /*int mi, res = r;
    while (l <= r)  {
        cerr << l << " ~ " << r << "\n";
        int mi = (l+r)/2;
        if (get(mi, r) > 0) {
            res = min(res, mi);
            r = mi - 1;
        } else l = mi + 1;
    }
    cerr << "endBlack\n";
    cerr << res << "\n";
    return id[res];*/
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &q);
    FOR(i, 1, n-1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    //cerr << "ok\n";
    HLD(1);
    //cerr << "ok\n";
    //FOR(u, 1, n) cerr << head[u] << " "; cerr << "\n";
    //FOR(u, 1, n) cerr << par[u] << " "; cerr << "\n";
    //FOR(u, 1, n) cerr << num[u] << " "; cerr << "\n";
    /*update(4, 1);
    cerr << get(3, 5) << "\n";
    cerr << firstBlack(num[head[6]], num[6]);*/
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == 0) {
            color[num[y]] ^= 1;
            if (color[num[y]]) update(num[y], 1);
            else update(num[y], -1);
            //cerr << "update 1 " << num[y] << "\n";
        } else {
            int res = -1;
            while (1) {
                if (get(num[head[y]], num[y]))
                    res = firstBlack(num[head[y]], num[y]);
                if (head[y] == 1) break;
                else y = par[head[y]];
                //cerr << y << "\n";
            }
            printf("%d\n", res);
        }
    }
}
/// Expelliarmus !
