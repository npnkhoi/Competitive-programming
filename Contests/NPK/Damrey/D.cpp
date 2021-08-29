using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef pair<ull, ull> pull;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

const int N = 1e6 + 5;
const ull oo = 1e18 + 7;

pair<ull, ull> res;
bool mark[N];
vector<int> adj[N];
ull a[N];
int n;


bool Less(pull x, pull y) {
    return (double) x.fi / x.se < (double) y.fi / y.se;
}

void dfs(int u, ull x, ull y) {
    //cerr << "dfs " << u << " " << x << " " << y << "\n";
    if (Less(mp(x, y), res)) res = mp(x, y);
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (mark[v] == 0) {
            /*ull tu = x*a[v];
            ull mau = y+1;
            ull gcd = __gcd(tu, mau);
            tu /= gcd;
            mau /= gcd;*/
            dfs(v, x*a[v], y+1);
        }
    }
}
void sub1() {
    res = mp(oo, 1);
    FOR(i, 1, n) {
        memset(mark, 0, sizeof mark);
        dfs(i, a[i], 1);
        //cerr << "\n";
    }
    ull gcd = __gcd(res.fi, res.se);
    res.fi /= gcd;
    res.se /= gcd;

    printf("%lld/%lld\n", res.fi, res.se);
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    scanf("%d", &n);
    REP(i, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    FOR(i, 1, n) scanf("%lld", &a[i]);
    sub1();
    return 0;
}
/** Happy Coding :D */
