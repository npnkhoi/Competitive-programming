#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "nreduce"
const int N = 1e5 + 5;
int n, m;
int lab[N], save[N];
vector<iii> e[5];
vector<int> ans;
int root(int u) {
    //printf("root %d\n", u);
    if (lab[u] < 0) return u;
    else return lab[u] = root(lab[u]);
    //printf("end root\n");
}
void join(int u, int v) {
    u = root(u), v = root(v);
    if (lab[u] < lab[v]) {
        lab[v] = u;
    } else {
        lab[u] = v;
        lab[v] -= lab[u] == lab[v];
    }
}
bool check() {
    int cnt = 0;
    FOR(i, 1, n) if (lab[i] < 0) {
        cnt ++;
        if (cnt > 1) return false;
    }
    return true;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m) {
        int u, v, type;
        scanf("%d%d%d", &u, &v, &type);
        e[type].pb(mp(mp(u, v), i));
        e[type].back().se = i;
    }
    //cerr << "ok1\n";
    memset(lab, -1, sizeof lab);
    REP(i, e[3].size()) {
        int u = e[3][i].fi.fi, v = e[3][i].fi.se;
        //cerr << u << " " << v << "\n";
        if (root(u) != root(v)) join(u, v);
        else ans.pb(e[3][i].se);
    }
    //cerr << "ok2\n";
    FOR(i, 1, n) save[i] = lab[i];

    REP(i, e[1].size()) {
        int u = e[1][i].fi.fi, v = e[1][i].fi.se;
        if (root(u) != root(v)) join(u, v);
        else ans.pb(e[1][i].se);
    }
    if (!check()) {
        printf("-1");
        exit(0);
    }
    FOR(i, 1, n) lab[i] = save[i];
    REP(i, e[2].size()) {
        int u = e[2][i].fi.fi, v = e[2][i].fi.se;
        if (root(u) != root(v)) join(u, v);
        else ans.pb(e[2][i].se);
    }
    if (!check()) {
        printf("-1");
        exit(0);
    }
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d\n", ans[i]);

}
/** Happy Coding :D */
