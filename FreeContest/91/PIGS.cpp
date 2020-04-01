#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, dep[N];
long long cntIn[N][N], cntOut[N][N], f[N][N];
vector<int> adj[N];
long long res;

void dfs(int u, int par) {
	cntIn[u][0] = 1;
	for (int v : adj[u]) {
		if (v == par) continue;
		dep[v] = dep[u] + 1;
		dfs(v, u);
		for (int i = 1; i < n; ++ i) cntIn[u][i] += cntIn[v][i - 1];
	}
}

void calc(int u, int par) {
	for (int v : adj[u]) {
		if (v == par) continue;
		for (int i = 1; i < n; ++ i) {
			cntOut[v][i] = cntOut[u][i - 1];
			cntOut[v][i] += cntIn[u][i - 1] - (i >= 2 ? cntIn[v][i - 2] : 0);
		}
		calc(v, u);
	}
	for (int i = 0; i < n; ++ i) {
		f[u][i] = cntIn[u][i] + cntOut[u][i];
	}
	// cerr << "f " << u << ": "; for (int i = 0; i < n; ++ i) cerr << f[u][i] << " "; cerr << "\n";

	for (int d = 1; d < n; ++ d) {
		if (f[u][d] >= 3) {
			// cerr << u << " " << d << "\n";
			res += f[u][d] * (f[u][d] - 1) * (f[u][d] - 2) / 6;
			for (int v : adj[u]) {
				if (v == par) continue;
				if (cntIn[v][d - 1] >= 2) {
					res -= cntIn[v][d - 1] * (cntIn[v][d - 1] - 1) / 2 * (f[u][d] - cntIn[v][d - 1]);
				}
				if (cntIn[v][d - 1] >= 3) {
					res -= cntIn[v][d - 1] * (cntIn[v][d - 1] - 1) * (cntIn[v][d - 1] - 2) / 6;
				}
			}
			if (cntOut[u][d] >= 2) {
				res -= cntOut[u][d] * (cntOut[u][d] - 1) / 2 * (f[u][d] - cntOut[u][d]);
			}
			if (cntOut[u][d] >= 3) {
				res -= cntOut[u][d] * (cntOut[u][d] - 1) * (cntOut[u][d] - 2) / 6;
			}
			// cerr << "res: " << res << "\n";
		}
	}
}

int main() {
	// freopen("PIGS.inp", "r", stdin);
	// freopen("PIGS.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i < n; ++ i) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	calc(1, -1);
	printf("%lld\n", res);
}