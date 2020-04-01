#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Box{
    ll x, y, z;
    Box(): x(0), y(0), z(0) {}
    Box(ll _x, ll _y, ll _z): x(min(_x, _y)), y(max(_x, _y)), z(_z) {}
};

const int N = 95;
int n, p, trace[N];
Box box[N];
ll f[N];
bool mark[N];
vi topo, adj[N];

void topoSort(int u) {
    mark[u] = 1;
    REP(j, adj[u].size()) {
        int v = adj[u][j];
        if (!mark[v]) topoSort(v);
    }
    topo.push_back(u);
}
void answer(int u) {
    if (trace[u] != 0) answer(trace[u]);
    cerr << box[u].x << " " << box[u].y << " " << box[u].z << "\n";
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    int tc = 0;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break; tc ++;
        p = 0;
        FOR(i, 1, n) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            box[++p] = Box(x, y, z);
            box[++p] = Box(y, z, x);
            box[++p] = Box(z, x, y);
        }
        //FOR(i, 1, p) cerr << box[i].x << " " << box[i].y << " " << box[i].z << "\n";
        FOR(i, 1, p) adj[i].clear();
        FOR(i, 1, p) FOR(j, 1, p)
            if (box[i].x > box[j].x && box[i].y > box[j].y)
            adj[i].pb(j);
        topo.clear();
        memset(mark, 0, sizeof mark);
        FOR(i, 1, p) if (!mark[i]) topoSort(i);
        reverse(topo.begin(), topo.end());
        //REP(i, p) cerr << "topo " << topo[i] << "\n";

        memset(f, 0, sizeof f);
        FOR(i, 1, p) f[i] = box[i].z;
        ll res = 0;
        int tail;
        REP(i, p) {
            int u = topo[i];
            if (f[u] > res) tail = u;
            res = max(res, f[u]);
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (f[v] < f[u] + box[v].z) {
                    f[v] = f[u] + box[v].z;
                    trace[v] = u;
                }
            }
        }
        printf("Case %d: maximum height = %lld\n", tc, res);
        //answer(tail);
    }
}
