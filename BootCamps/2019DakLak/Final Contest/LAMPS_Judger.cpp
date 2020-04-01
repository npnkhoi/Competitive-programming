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

#define task "LAMPS"

const int nTest = 1000;
const double TimeLimit = 1.0;

double maxTime = 1.0;
int score = 0;

const int N = 3005;
int lab[N], siz[N], color[N], tmp[N], mark[N][N], n;
vi adj[N];
int root(int u) {
    if (lab[u] == -1) return u;
    else {
        lab[u] = root(lab[u]);
        return lab[u];
    }
}

void join(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return;
    if (siz[u] > siz[v]) {
        lab[v] = u;
        siz[u] += siz[v];
    } else {
        lab[u] = v;
        siz[v] += siz[u];
    }
}

long long Rand(long long l, long long r) {
    return l + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) +
                1LL * rand() ) % (r-l+1);
}

void change(int u) {
    tmp[u] ^= 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        tmp[v] ^= 1;
    }
}

void test() {
    cerr << "test\n";
    ofstream inp(task".inp");
    n = 50;
    FOR(i, 1, n) adj[i].clear();
    inp << n << " 1\n";
    memset(lab, -1, sizeof lab);
    memset(siz, 0, sizeof siz);

    memset(mark, 0, sizeof mark);
    REP(z, n-1) {
        //cerr << "edge " << z << "\n";
        int u, v;
        do u = Rand(1, n-1), v = Rand(u+1, n);
        while (root(u) == root(v));
        mark[u][v] = mark[v][u] = 1;
        inp << u << " " << v << "\n";
        //cerr << u << " " << v << "\n";
        adj[u].pb(v);
        adj[v].pb(u);
        join(u, v);
    }
    int u, v;
    do {
        u = Rand(1, n-1), v = Rand(u+1, n);
        //cerr << u << " " << v << "\n";
    }
    while (u == v || mark[u][v]);
    adj[u].pb(v);
    adj[v].pb(u);

    inp << u << " " << v << "\n";
    REP(i, n) {
        color[i+1] = Rand(0, 1);
        inp << color[i+1] << " ";
    }
    inp.close();
}

void check() {
    freopen(task".inp", "r", stdin);
    int tc;
    scanf("%d%d", &n, &tc);
    cerr << "n tc " << n << " " << tc << "\n";
    FOR(i, 1, n) adj[i].clear();
    REP(i, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, n) {
        scanf("%d", &color[i]);
        //cerr << color[i] << "\n";
    }
    int nVtx, u;
    REP(i, 1e8);
    freopen(task".out", "r", stdin);
    REP(i, 1e8);
    FOR(i, 1, n) tmp[i] = color[i];
    scanf("%d", &nVtx);
    cerr << "nvtx " << nVtx << "\n";
    REP(i, nVtx) {
        cin >> u;
        change(u);
    }
    bool flag = 1;
    if (nVtx != -1) FOR(i, 1, n) if (tmp[i] == 0) {
        flag = 0;
        cerr << "WRONG at " << i << "\n";
    }
    if (flag || nVtx == -1) cerr << "CORRECT\n"; else {
        cerr << "WRONG-----------\n";
        exit(0);
    }
}

int main() {
    srand(time(NULL));

    FOR(iTest, 1, nTest) {
        printf("* TEST NUMBER %d\n", iTest);

        test();
        cerr << "ok test\n";

        system(task".exe");
        cerr << "ok exe\n";

        check();
    }
    return 0;
}
/**/
