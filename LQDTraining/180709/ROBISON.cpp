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
#define task "ROBISON"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
typedef pair<ii, int> ii_i;
typedef pair<int, ii> i_ii;

const int N = 2000 + 5;
const int K = 200 + 5;
const int oo = 1e9 + 7;

int k, m, n, s, t;
vector<i_ii> adj[N];
int dist[N][K];
priority_queue<ii_i, vector<ii_i>, greater<ii_i> > heap;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> k >> n >> m;
	REP(i, m) {
		int u, v, t, h;
		cin >> u >> v >> t >> h;
		adj[u].pb(mp(v, mp(t, h)));
		adj[v].pb(mp(u, mp(t, h)));
	}	
	cin >> s >> t;	
	FOR(u, 1, n) FOR(j, 0, k) dist[u][j] = oo;
	dist[s][0] = 0;
	heap.push(mp(mp(0, 0), s));
	while (!heap.empty()) {
		int d = heap.top().fi.fi; 
		int h = heap.top().fi.se;
		int u = heap.top().se;
		heap.pop();
		if (d > dist[u][h]) continue;
		REP(j, adj[u].size()) {
			i_ii v = adj[u][j];
			if (h + v.se.se <= k && dist[v.fi][h + v.se.se] > d + v.se.fi) {
				dist[v.fi][h + v.se.se] = d + v.se.fi;
				heap.push(mp(mp(d + v.se.fi, h + v.se.se), v.fi));
			}
		}
	}
	int res = oo;
	FOR(j, 0, k-1) res = min(res, dist[t][j]);
	if (res == oo) cout << -1;
	else cout << res;
}
