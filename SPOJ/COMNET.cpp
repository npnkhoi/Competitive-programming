#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e5 + 10;
const int M = 1e6 + 10;
const int S = 105;
typedef pair<int, int> ii;
typedef pair<ii, ii> pii;

vector<ii> adj[N];
set<int> change;
int n, m, q, s, k;
int num[N], low[N], idx, par[N], root[N], Rank[N], id[M];
pii e[M];
ii _e[S];
long long mst;

void dfs(int u) {
    num[u] = low[u] = ++idx;
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi;
        if (num[v] == 0) {
            par[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (par[u] != v) low[u] = min(low[u], num[v]);
    }
}
bool checkBridge(int u, int v) {
    //cout << u << " " << v << endl;
    if (num[u] > num[v]) swap(u, v);
    return low[v] > num[u];
}
int getRoot(int u) {
    return (u == root[u]) ? u : root[u] = getRoot(root[u]);
}
void join(int u, int v, int c) {
    u = getRoot(u), v = getRoot(v);
    if (u == v) return;
    mst += 1LL * c;
    if (Rank[u] > Rank[v]) root[v] = u;
    else {
        root[u] = v;
        if (Rank[u] == Rank[v]) Rank[v]++;
    }
}
bool findMST() {
    int i = 0, j = 0;
    while (i < m || j < s) {
        if (i < m && j < s) {
            if (e[i].fi.fi <= _e[j].fi) {
                if (change.find(e[i].fi.se) == change.end()) {
                    if (e[i].fi.se == k)
                        return getRoot(e[i].se.fi) == getRoot(e[i].se.se);
                    join(e[i].se.fi, e[i].se.se, e[i].fi.fi);
                    //printf("i: %d\n", i);
                }
                i++;
            }
            else {
                if (_e[j].se == k)
                return getRoot(e[id[_e[j].se]].se.fi) ==  getRoot(e[id[_e[j].se]].se.se);
                join(e[id[_e[j].se]].se.fi, e[id[_e[j].se]].se.se,
                _e[j].fi);
                //printf("j: %d\n", j);
                j++;
            }
        }
        else if (i < m) {
            if (change.find(e[i].fi.se) == change.end()) {
                    join(e[i].se.fi, e[i].se.se, e[i].fi.fi);
                    if (e[i].fi.se == k)
                        return getRoot(e[i].se.fi) == getRoot(e[i].se.se);
                    //printf("i: %d\n", i);
                }
                i++;
        }
        else {
            if (_e[j].se == k)
            return getRoot(e[id[_e[j].se]].se.fi) ==  getRoot(e[id[_e[j].se]].se.se);
            join(e[id[_e[j].se]].se.fi, e[id[_e[j].se]].se.se,
            _e[j].fi);
            //printf("i: %d\n", i);
            j++;
        }
    }
}
int main() {
    freopen("0.in", "r", stdin);
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d", &n, &m, &q);
        FOR(i, 1, n) adj[i].clear();
        REP(i, m) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            adj[u].push_back(mp(v, c));
            adj[v].push_back(mp(u, c));
            e[i].fi.fi = c;
            e[i].fi.se = i+1;
            e[i].se.fi = u;
            e[i].se.se = v;
        }
        memset(par, -1, sizeof par);
        memset(num, 0, sizeof num);
        idx = 0; dfs(1);
        sort(e, e+m);
        REP(i, m) id[e[i].fi.se] = i; /// id[i] = j : edge ith is in e[j]
        while (q--) {
            scanf("%d %d", &k, &s);
            /*if (checkBridge(e[id[k]].se.fi, e[id[k]].se.se)) {
                printf("NO\n");
                int trash;
                REP(i, 2*s) scanf("%d", &trash);
                continue;
            }*/

            change.clear();
            int save = -1;
            REP(i, s) {
                scanf("%d %d", &_e[i].se, &_e[i].fi);
                if (_e[i].se == k) save = _e[i].fi;
                change.insert(_e[i].se);
            }
            sort(_e, _e + s);

            FOR(i, 1, n) root[i] = i;
            memset(Rank, 0, sizeof Rank);
            if (findMST()) printf("YES\n");
            else printf("NO\n");
            /*mst = 0;
            findMST();
            long long tmp = mst;

            FOR(i, 1, n) root[i] = i;
            memset(Rank, 0, sizeof Rank);
            mst = 0;
            if (save > 0) join(e[id[k]].se.fi, e[id[k]].se.se, save);
                else join(e[id[k]].se.fi, e[id[k]].se.se, e[id[k]].fi.fi);
            findMST();
            //printf("backup: %d\n mst: %lld %lld\n", save, tmp, mst);
            if (mst > tmp) printf("YES\n");
            else printf("NO\n");*/
        }
    }
}
