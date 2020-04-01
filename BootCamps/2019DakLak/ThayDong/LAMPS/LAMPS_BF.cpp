#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "LAMPS"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
int color[N], n, tc;
ll state;
map<ll, int> save;
vi adj[N];
void change(int u, int &stt) {
    stt ^= (1 << u-1);
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        stt ^= (1 << v-1);
    }
}
void sub2() {
    save.clear();
    int m = n/2, p = n - m;
    //cerr << m << " " << p << "\n";
    REP(mask, (1 << m)) {
        int tmp = state;
        REP(i, m) if (mask & (1 << i)) change(i+1, tmp);
        save[tmp] = mask;
        //cerr << mask << "->" << tmp << "\n";
    }
    //cerr << "-----\n";
    REP(mask, (1 << p)) {
        int tmp = (1 << n) - 1;
        REP(i, p) if (mask & (1 << i)) change(i+m+1, tmp);
        //cerr << mask << "->" << tmp << "\n";
        if (save.find(tmp) != save.end()) {
            int preMask = save[tmp];
            printf("%d", __builtin_popcount(preMask) + __builtin_popcount(mask));
            REP(i, m) if (preMask & (1 << i)) printf(" %d", i + 1);
            REP(i, p) if (mask & (1 << i)) printf(" %d", i + m + 1);
            printf("\n");
            return;
        }
    }
    printf("-1\n");
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d%d", &n, &tc);
    FOR(z, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while (tc --) {
        //FOR(i, 1, n) adj[i].clear();
        state = 0;
        FOR(i, 1, n) {
            scanf("%d", &color[i]);
            if (color[i]) state |= (1 << i-1);
        }
        if (n <= 30) sub2();
    }
}
