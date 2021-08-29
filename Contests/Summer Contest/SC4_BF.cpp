#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC4"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 305;
const int oo = 1e9 + 7;
int c[N][N], d[N][N], del[N];
int mark[N], tmp[N];
int n;
vi adj[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;
ll ans[N], res;
vi nodeIn;

void update1(int s) {
    FOR(i, 1, n) tmp[i] = oo;
    tmp[s] = 0; heap.push(mp(0, s));
    while (!heap.empty()) {
        int u = heap.top().se, dist = heap.top().fi;
        heap.pop();
        if (dist > tmp[u]) continue;
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (tmp[v] > tmp[u] + d[u][v]) {
                tmp[v] = tmp[u] + d[u][v];
                heap.push(mp(tmp[v], v));
            }
        }
    }
    REP(i, nodeIn.size()) d[s][nodeIn[i]] = tmp[nodeIn[i]];
}
void update2(int s) {
    FOR(i, 1, n) tmp[i] = oo;
    tmp[s] = 0; heap.push(mp(0, s));
    while (!heap.empty()) {
        int u = heap.top().se, dist = heap.top().fi;
        heap.pop();
        if (dist > tmp[u]) continue;
        REP(j, adj[u].size()) {
            int v = adj[u][j];
            if (tmp[v] > tmp[u] + d[v][u]) {
                tmp[v] = tmp[u] + d[v][u];
                heap.push(mp(tmp[v], v));
            }
        }
    }
    REP(i, nodeIn.size()) d[nodeIn[i]][s] = tmp[nodeIn[i]];
}
void update3(int s) {
    REP(i, adj[s].size()) REP(j, adj[s].size()) {
        int u = adj[s][i], v = adj[s][j];
        d[u][v] = min(d[u][v], d[u][s] + d[s][v]);
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d", &n);
        FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &d[i][j]);
        FOR(i, 1, n) scanf("%d", &del[i]);
        nodeIn.clear();
        FOR(i, 1, n) adj[i].clear();

        FORD(i, n, 1) {
            int u = del[i];
            REP(i, nodeIn.size()) {
                int v = nodeIn[i];
                adj[u].pb(v);
                adj[v].pb(u);
            }
            nodeIn.push_back(u);
            res = 0;
            /*update1(u);
            update2(u);
            update3(u);*/
            REP(i, nodeIn.size()) REP(j, nodeIn.size())
                res += d[nodeIn[i]][nodeIn[j]];
            /*FOR(i, 1, n) {
                FOR(j, 1, n) cerr << d[i][j] << " ";
                cerr << "\n";
            }*/
            ans[i] = res;
        }
        FOR(i, 1, n) printf("%lld ", ans[i]);
        printf("\n");
    }
}
