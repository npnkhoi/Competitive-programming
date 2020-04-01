#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "SPC2"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105, V = 1e4 + 5;

int tc, n, nl, nr, last, res;
int a[N][N], id[N][N], ml[V], mr[V], trace[V];
vi adj[V];
queue<int> q;

void addEdge(int u, int v, int x) {
    if (x > 0) adj[u].push_back(v);
    else adj[v].push_back(u);
}

bool augment() {
    while (!q.empty()) q.pop();
    memset(trace, 0, sizeof trace);

    FOR(i, 1, nl) {
        if (ml[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        REP(i, adj[u].size()) {
            int v = adj[u][i];
            if (trace[v]) continue;
            if (mr[v] == 0) {
                last = v;
                return true;
            }
            trace[v] = u;
            q.push(mr[v]);
        }
    }
    return false;
}

void enlarge() {
    res ++;
    int u = last, nxt;
    while (1) {
        nxt = ml[trace[u]];
        ml[trace[u]] = u;
        mr[u] = trace[u];
        if (nxt == 0) break;
        u = nxt;
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> tc;
    REP(NhiThun, tc) {
        cin >> n;

        FOR(i, 1, n * n) adj[i].clear();
        memset(ml, 0, sizeof ml);
        memset(mr, 0, sizeof mr);
        nl = nr = 0;

        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> a[i][j];
                if (a[i][j] == 0) continue;
                if (a[i][j] > 0) id[i][j] = ++ nl;
                else if (a[i][j] < 0) id[i][j] = ++ nr;
                FOR(x, 1, i - 1)
                    if (a[x][j] == -a[i][j])
                        addEdge(id[i][j], id[x][j], a[i][j]);
                FOR(x, 1, j - 1)
                    if (a[i][x] == -a[i][j])
                        addEdge(id[i][j], id[i][x], a[i][j]);
            }
        }

        res = 0;

        FOR(u, 1, nl) {
            REP(i, adj[u].size()) {
                int v = adj[u][i];
                if (mr[v] == 0) {
                    ml[u] = v;
                    mr[v] = u;
                    res ++;
                    break;
                }
            }
        }

        while (augment()) enlarge();

        cout << res << '\n';
    }
}
