#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "cntab1"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e3 + 5;
vector<ii> adj[N];
vi ans;
ii ope[N];
int n, idx, cnt1, cnt2;
int tmp[N], mark[N];
int a[N][N], b[N][N];


void dfs(int u) {
    if (cnt1 != -1) cnt1 += ope[u].fi;
    if (cnt2 != -1) cnt2 += ope[u].se;
    mark[u] = 1;
    tmp[++idx] = u;
    //cerr << "dfs " << u << " " << ope[u].fi << " " << ope[u].se << " " << cnt1 << " " << cnt2 << "\n";
    REP(j, adj[u].size()) {
        int v = adj[u][j].fi, c = adj[u][j].se;
        if (!mark[v]) {
            ope[v] = mp(ope[u].fi ^ c, ope[u].se ^ c);
            dfs(v);
        } else {
            if (ope[v].fi ^ ope[u].fi != c) cnt1 = -1;
            if (ope[v].se ^ ope[u].se != c) cnt2 = -1;
        }
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &b[i][j]);
    FOR(i, 1, n) FOR(j, 1, n) {
        if ((a[i][j] == 0) ^ (b[i][j] == 0)) {
            printf("-1");
            exit(0);
        } else if (a[i][j] != 0) {
            adj[i].pb(mp(j+n, a[i][j] != b[i][j]));
            adj[j+n].pb(mp(i, a[i][j] != b[i][j]));
            //cerr << i << " - " << j + n << "\n";
        }
    }
    FOR(i, 1, 2*n) if (!mark[i]) {
        //cerr << "here\n";
        idx = cnt1 = cnt2 = 0;
        ope[i] = mp(0, 1);
        dfs(i);
        if (cnt1 == -1 && cnt2 == -1) {
            printf("-1");
            exit(0);
        } else if (cnt1 < cnt2) {
            FOR(i, 1, idx) if (ope[tmp[i]].fi) ans.pb(tmp[i]);
        } else {
            FOR(i, 1, idx) if (ope[tmp[i]].se) ans.pb(tmp[i]);
        }
    }
    if (ans.size() > 100) {
        printf("-1");
        return 0;
    }
    printf("%d\n", ans.size());
    REP(j, ans.size()) {
        if (ans[j] <= n) printf("1 %d\n", ans[j]);
        else printf("2 %d\n", ans[j] - n);
    }
}
