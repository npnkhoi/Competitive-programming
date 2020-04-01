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

#define taskName "0"

const int N = 1005;
const int M = 2e4 + 5;
vector<int> adj[N];
vector<ii> ans;
ii e[M];
int num[N];
int n, m;

bool ok;

void dfs(int u, int X, int Y) {
    num[u] = -1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (u == X && v == Y) continue;
        if (num[v] == 0) {
            dfs(v, X, Y);
        } else if (num[v] == -1) ok = 0;
    }
    num[u] = 1;
}
bool hasCircle(int X, int Y) {
    memset(num, 0, sizeof num);
    ok = 1;
    FOR(i, 1, n) if (num[i] == 0) dfs(i, X, Y);
    return !ok;
}
int main() {
    //freopen(taskName".inp", "r", stdin);
    //freopen(taskName".out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (u != v) {
            adj[u].push_back(v);
            e[i] = mp(u, v);
        } else e[i] = mp(-1, -1);
    }
    if (!hasCircle(-1, -1)) {
        printf("-1");
        return 0;
    } else {
        //cerr << "hasCircle\n";
        sort(e, e+m);
        REP(i, m) if (i == 0 || e[i] != e[i-1])
        if (e[i].fi != -1 && !hasCircle(e[i].fi, e[i].se))
            ans.pb(e[i]);
        if (ans.empty()) printf("-1");
        else {
            printf("%d\n", (int)ans.size());
            sort(ans.begin(), ans.end());
            REP(j, ans.size()) printf("%d %d\n", ans[j].fi, ans[j].se);
        }
    }
    return 0;
}
/** Happy Coding :D */
