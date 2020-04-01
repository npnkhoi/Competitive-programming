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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e5 + 5;

int n, m, d;
vi adj[N];
int p[N], aft[N], maxUp[N], maxDown[N]; 

void dfs1(int u, int par) {
	if (aft[u]) maxDown[u] = 0;
	for (int v : adj[u]) if (v != par) {
		dfs1(v, u);
		if (maxDown[v] >= 0) maxDown[u] = max(maxDown[u], maxDown[v] + 1);
	}	
} 
void dfs2(int u, int par) {
	int val[2], vtx[2];
	val[0] = val[1] = -1;
	for (int v : adj[u]) if (v != par) {
		int tmp = maxDown[v];
		if (tmp == -1) continue;
		if (tmp > val[0]) {
			vtx[1] = vtx[0];
			val[1] = val[0];
			vtx[0] = v;
			val[0] = tmp;
		} else if (tmp > val[1]) {
			val[1] = tmp;
			vtx[1] = v;
		}
	}
	for (int v : adj[u]) if (v != par) {
		if (v != vtx[0]) {
			if (val[0] >= 0) maxUp[v] = val[0] + 2;
		}
		else {
			if (val[1] >= 0) maxUp[v] = val[1] + 2;
		}
		if (maxUp[u] >= 0) maxUp[v] = max(maxUp[v], maxUp[u] + 1);
		if (aft[v] && maxUp[v] < 0) maxUp[v] = 0; 
		dfs2(v, u);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n >> m >> d;
	FOR(i, 1, m) {
		cin >> p[i];
		aft[p[i]] = 1;
	}
	FOR(i, 1, n-1) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	memset(maxDown, -1, sizeof maxDown);
	memset(maxUp, -1, sizeof maxUp);
	dfs1(1, -1);
	if (aft[1]) maxUp[1] = 0;
	dfs2(1, -1);
	int res = 0;
	//cerr << "\n";
	//FOR(i, 1, n) cerr << maxDown[i] << " " << maxUp[i] << "\n";
	FOR(u, 1, n) if (maxUp[u] <= d && maxDown[u] <= d) res ++;
	cout << res;
}
