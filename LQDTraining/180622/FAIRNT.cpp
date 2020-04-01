#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "FAIRNT"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;
const int K = 105;
int n, m, k, l;
vi adj[N], type[K], val[N];
int d[N], cnt[N], f[N];
queue<int> q;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k >> l;
    //scanf("%d%d%d%d", &n, &m, &k, &l);
    FOR(i, 1, n) {
        int t;
        cin >> t;
        //scanf("%d", &t);
        type[t].pb(i);
    }
    REP(i, m) {
        int u, v;
        cin >> u >> v;
        //scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    FOR(i, 1, k) {
        //cerr << "bfs type " << i << "\n";
        memset(d, -1, sizeof d);
        REP(j, type[i].size()) {
            int u = type[i][j];
            d[u] = 0;
            q.push(u);
            val[0].pb(u);
            //cerr << "push " << u << "\n";
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            REP(j, adj[u].size()) {
                int v = adj[u][j];
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    //dist[v][i] = d[v];
                    val[d[v]].pb(v);
                }
            }
        }
        //FOR(i, 1, n) cerr << d[i] << " "; cerr << "\n";
    }
    /*FOR(i, 1, n) {
        FOR(j, 1, k) cerr << dist[i][j] << " ";
        cerr << "\n";
    }*/
    FOR(v, 0, n) REP(j, val[v].size()) {
        int u = val[v][j];
        if (cnt[u] < l) {
            f[u] += v;
            cnt[u] ++;
        }
    }
    FOR(i, 1, n)
        cout << f[i] << ' ';
        //printf("%d ", f[i]);

    /*FOR(u, 1, n) {
        //sort(dist[u] + 1, dist[u] + k + 1);
        khoiSort
        int s = 0;
        FOR(i, 1, l) s += dist[u][i];
        cout << s << ' ';
    }*/
}
