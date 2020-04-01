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
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, double> idb;
typedef pair<double, int> dbi;

const int N = 1e3 + 5;
const double oo = 1e18 + 7;
int n, m;
int x[N], y[N], mark[N][N];
double maxEdge;
vector<idb> adj[N];
double dist[N];
priority_queue<dbi, vector<dbi>, greater<dbi> > heap;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> n >> m >> maxEdge;
    FOR(i, 1, n) cin >> x[i] >> y[i];
    REP(i, m) {
    	int u, v;
    	cin >> u >> v;
    	adj[u].pb(mp(v, 0));
    	adj[v].pb(mp(u, 0));
    	mark[u][v] = mark[v][u] = 1;
    }
    FOR(u, 1, n-1) FOR(v, u+1, n) if (!mark[u][v]) {
    	double d = sqrt(1LL * (x[u] - x[v]) * (x[u] - x[v]) + 1LL * (y[u] - y[v]) * (y[u] - y[v]));
    	if (d <= maxEdge) {
    		adj[u].pb(mp(v, d));
    		adj[v].pb(mp(u, d));
    	}
    }
    FOR(i, 1, n) dist[i] = oo;
    dist[1] = 0; heap.push(mp(0, 1));
    while (!heap.empty()) {
    	int u = heap.top().se;
    	double d = heap.top().fi;
    	heap.pop();

    	if (d > dist[u]) continue;

    	REP(j, adj[u].size()) {
    		idb v = adj[u][j];
    		if (dist[v.fi] > d + v.se) {
    			dist[v.fi] = d + v.se;
    			heap.push(mp(dist[v.fi], v.fi));
    		}     	
    	}
    }
    if (dist[n] == oo) cout << "-1";
    else cout << (ll) floor(dist[n] * 1000);
}
