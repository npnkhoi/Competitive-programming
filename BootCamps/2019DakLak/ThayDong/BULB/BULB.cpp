#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "bulb"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e3 + 5;
const int K = 3e4 + 5;
vi adj[N], ans;
int par[N], mark[K], edgeID[N][N], a[N], b[N];
ii eList[K];
int m, n, k;
queue<int> q;

void trace(int u) {
    //cerr << "trace " << u << "\n";
    if (par[u] != -1) {
        mark[edgeID[u][par[u]]] ^= 1;
        trace(par[u]);
    }
}
void augment(int s) {
    while (!q.empty()) q.pop(); q.push(s);
    memset(par, 0, sizeof par); par[s] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (par[v] == 0) {
                par[v] = u;
                if (a[v]) {
                    a[s] = a[v] = 0;
                    trace(v);
                    return;
                } else q.push(v);
            }
        }
    }
    printf("-1"); exit(0);
}
long long Rand(long long l, long long r) {
    return l + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) +
                1LL * rand() ) % (r-l+1);
}
void test() {
    freopen(task".inp" ,"w", stdout);
    srand(time(NULL));
    int m = Rand(1, 10), n = Rand(1, 10), k = Rand(1, 1000);
    cout << m << " " << n << " " << k << "\n";
    REP(z, m+n) cout << Rand(0, 1); cout << "\n";
    REP(z, m+n) cout << Rand(0, 1); cout << "\n";
    REP(z, k) {
        cout << Rand(1, m) << " " << Rand(1, n) << "\n";
    }
}
void check() {
    cerr << "check\n";
    freopen(task".out", "r", stdin);
    srand(time(NULL));
    int m;
    cin >> m;
    REP(z, m) {
        int k;
        cin >> k;
        b[eList[k].fi] ^= 1;
        b[eList[k].se] ^= 1;
    }
    FOR(i, 1, m+n) if (b[i] == 1) {
        cerr << "WRONG ANSWER\n";
        return;
    }
    cerr << "CORRECT  !!!\n";
}
int main() {
    //test();
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    char ch;
    FOR(i, 1, m+n) {
        scanf(" %c", &ch);
        a[i] = ch - '0';
    }
    FOR(i, 1, m+n) {
        scanf(" %c", &ch);
        a[i] ^= (ch - '0');
        //b[i] = a[i];
        //cerr << a[i] << "\n";
    }
    FOR(i, 1, k) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v+m);
        adj[v+m].pb(u);
        edgeID[u][v+m] = edgeID[v+m][u] = i;
        //eList[i] = mp(u, v+m);
    }
    FOR(i, 1, m+n) if (a[i]) augment(i);
    FOR(i, 1, k) if (mark[i]) ans.pb(i);
    printf("%d\n", ans.size());
    REP(i, ans.size()) printf("%d ", ans[i]);
    //check();
}
