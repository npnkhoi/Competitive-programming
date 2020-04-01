#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> ii;

const int N = 1e6 + 5;
const int oo = 1e9 + 7;

int n, res, fi[N], fo[N];
vector<ii> adj[N];

void dfs(int u, int par) {
	for (ii v : adj[u]) if (v.fi != par) {
		dfs(v.fi, u);
		fi[u] = max(fi[u], v.se + fi[v.fi]);
	}
}

void dfsOut(int u, int par) {
	int tmp, max1 = 0, max2 = 0;
	for (ii v : adj[u]) if (v.fi != par) {
		tmp = v.se + fi[v.fi];
		if (tmp >= max1) max2 = max1, max1 = tmp;
		else if (tmp > max2) max2 = tmp;
	}
	for (ii v : adj[u]) if (v.fi != par) {
		// fo[v.fi] = fo[u] + v.se;
		tmp = v.se + fi[v.fi];
		if (tmp != max1) fo[v.fi] = max(fo[u] + v.se, max1 + v.se);
		else fo[v.fi] = max(fo[u] + v.se, max2 + v.se);

		dfsOut(v.fi, u);
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	// scanf("%d", &n);
	cin >> n;
	for (int  i = 1; i < n; ++ i) {
		int u, v, c;
		// scanf("%d%d%d", &u, &v, &c);
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(v, c));
		adj[v].push_back(make_pair(u, c));
	}
	dfs(1, -1);
	dfsOut(1, -1);
	res = oo;
	for (int i = 1; i <= n; ++ i) {
		res = min(res, max(fi[i], fo[i]));
	// 	cerr << fi[i] << " " << fo[i] << "\n";
	}
	// printf("%d", res); 
	cout << res;
}