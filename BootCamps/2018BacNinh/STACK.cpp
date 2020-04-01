#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define task "stack"

const int N = 2500 + 5;
const int oo = 1e9 + 7;
int n, res;
ii a[N];
vi adj[N];
double timer;
bitset<N> vis;

void TLE() {
    if ((clock() - timer) / CLOCKS_PER_SEC >= 15.0) {
        printf("%d", res);
        exit(0);
    }
}
void backTrack(int cap, int len, int u) {
    TLE();
    res = max(res, len);
    vis[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!vis[v] && a[v].fi <= cap)
            backTrack(min(cap - a[v].fi, a[v].se), len + 1, v);
    }
    vis[u] = 0;
}
bool cmp(ii a, ii b) {
    return a.se > b.se || (a.se == b.se && a.fi > b.fi);
}
int main() {
    freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    timer = clock();
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &a[i].fi);
    FOR(i, 1, n) scanf("%d", &a[i].se);
    sort(a+1, a+n+1, cmp);
    FOR(i, 1, n) {
        FOR(j, i+1, n) if (a[j].fi <= a[i].se) adj[i].pb(j);
        FORD(j, i-1, 1) if (a[j].fi <= a[i].se) adj[i].pb(j);
    }
    FOR(i, 1, n) adj[0].pb(i);
    int tmp = a[1].fi;
    /*FORD(i, 1, n) {
        if (a[i].fi <= tmp)
    }*/
    backTrack(oo, 0, 0);
    printf("%d", res);
    return 0;
}
/** Happy Coding :D */
