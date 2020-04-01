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

#define task "dining"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Pack {
    int dist, vtx, type;
    Pack() {}
    Pack(int a, int b, int c): dist(a), vtx(b), type(c) {}
};

bool operator < (const Pack a, const Pack b) {
    return a.dist > b.dist;
}

const int N = 5e4 + 5, oo = 2e9 + 7;

int n, m, k;
int yum[N], dist[N][2];
vector<ii> adj[N];
priority_queue<Pack> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));
    }
    REP(i, k) {
        int u, c;
        cin >> u >> c;
        yum[u] = c;
    }
    FOR(i, 1, n) dist[i][0] = dist[i][1] = oo;
    dist[n][0] = 0; q.push(Pack(0, n, 0));
    if (yum[n] > 0) dist[n][1] = 0, q.push(Pack(0, n, 1));

    while (!q.empty()) {
        Pack t = q.top();
        q.pop();

        if (t.dist != dist[t.vtx][t.type]) continue;

        REP(i, adj[t.vtx].size()) {
            ii v = adj[t.vtx][i];

            if (dist[v.fi][t.type] > dist[t.vtx][t.type] + v.se) {
                dist[v.fi][t.type] = dist[t.vtx][t.type] + v.se;
                q.push(Pack(dist[v.fi][t.type], v.fi, t.type));
            }

            if (t.type == 0 && yum[v.fi] > 0 && dist[v.fi][1] > dist[t.vtx][0] + v.se - yum[v.fi]) {
                dist[v.fi][1] = dist[t.vtx][0] + v.se - yum[v.fi];
                q.push(Pack(dist[v.fi][1], v.fi, 1));
            }
        }
    }
    //FOR(i, 1, n) cerr << dist[i][0] << ' ' << dist[i][1] << '\n';
    //cerr << '\n';
    FOR(i, 1, n-1) cout << (dist[i][0] >= dist[i][1]) << '\n';
}
