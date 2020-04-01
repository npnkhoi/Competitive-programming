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

#define task "TUNNEL"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 105, oo = 1e9 + 7;

int n, m, s, t, bound, dist[N], mark[N];
vector<ii> g[N], adj[N];
priority_queue<ii, vector<ii>, greater<ii> > heap;

void input() {
    cin >> n >> s >> t >> m;
    REP(i, m) {
        int u, v, h, d;
        cin >> u >> v >> h >> d;
        adj[u].push_back(mp(v, d));
        adj[v].push_back(mp(u, d));
        g[u].push_back(mp(v, h));
        g[v].push_back(mp(u, h));
    }
}

bool ok(int x) {
    queue<int> q;
    q.push(s);
    memset(mark, 0, sizeof mark);
    mark[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        //cerr << u << ' ';
        REP(j, g[u].size()) {
            ii v = g[u][j];
            if (v.se < x || mark[v.fi]) continue;
            mark[v.fi] = 1;
            q.push(v.fi);
        }
    }
    //cerr << '\n';
    return mark[t];
}

void biSearch() {
    int l = 0, r = 1e4, mid, bs = l;
    while (l <= r) {
        mid = (l + r) / 2;
        if (ok(mid)) {
            bs = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    bound = bs;
}

void dijsktra() {
    FOR(i, 1, n) dist[i] = oo;
    heap.push(mp(0, s));
    dist[s] = 0;
    while (!heap.empty()) {
        int u = heap.top().se, d = heap.top().fi;
        heap.pop();

        if (d != dist[u]) continue;

        REP(j, adj[u].size()) {
            ii v = adj[u][j];
            if (g[u][j] .se < bound) continue;
            if (d + v.se < dist[v.fi]) {
                dist[v.fi] = d + v.se;
                heap.push(mp(dist[v.fi], v.fi));
            }
        }
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    input();
    biSearch();
    dijsktra();
    cout << bound << ' ' << dist[t];
}
