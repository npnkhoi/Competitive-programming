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

#define task "lamps"

const int nTest = 1000;
const double TimeLimit = 1.0;

double maxTime = 1.0;
int score = 0;

const int N = 3005;
int lab[N], siz[N], color[N], tmp[N], n;
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
    ofstream inp(task".inp");
    n = Rand(1, 100);
    FOR(i, 1, n) adj[i].clear();
    inp << n << " 1\n";
    memset(lab, -1, sizeof lab);
    REP(z, n-1) {
        int u, v;
        do u = Rand(1, n-1), v = Rand(u+1, n);
        while (root(u) == root(v));
        inp << u << " " << v << "\n";
        adj[u].pb(v);
        adj[v].pb(u);
        join(u, v);
    }
    REP(i, n) {
        color[i+1] = Rand(0, 1);
        inp << color[i+1] << " ";
    }
    inp.close();
}

void check() {
    int nVtx, u;
    freopen(task".out", "r", stdin);
    FOR(i, 1, n) tmp[i] = color[i];
    cin >> nVtx;
    REP(i, nVtx) {
        cin >> u;
        change(u);
    }
    bool flag = 1;
    FOR(i, 1, n) if (tmp[i] == 0) {
        flag = 0;
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

        system(task"sub3.exe");

        check();
    }
    return 0;
}
/**/
