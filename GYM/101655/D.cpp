#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

typedef pair<int, int> ii;

vector<int> adj[N];
vector<vector<int> > f[N];
vector<int> f[N][N][]

void Resize(vector<vector<vector<int>>> &v, int a, int b, int c) {
	v.resize(a);
	for (int i = 0; i < a; ++ i) {
		v[i].resize(b);
		for (int j = 0; j < b; ++ j) {
			v[i][j].resize(c);
		}
	}
}

long long Rand(long long l, long long r) {
	return l + (
		1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +  
		1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
		1LL * rand() * (RAND_MAX + 1) +
		1LL * rand()) % (r - l + 1);
}

void dfs(int u, int par) {
	int p = 0;
	for (ii v : adj[u]) if (v != par) {
		child[++ p] = v;
	}
	for (int i = 1; i <= p; ++ i) {
		int v = child[i].first;
		int c = child[i].second;
		for (int j = 0; j <= k; ++ j) {
			g[i][j][0] = g[i][j][1] = 0;
			for (int k = 0; k <= j; ++ k) {
				g[i][j][0] = max(g[i][j][0], g[i - 1][j - k][0] + f[v][k][0]);
				g[i][j][0] = max(g[i][j][0], g[i - 1][j - k][0] + f[v][k][1]);
				if (k < j) 
					g[i][j][0] = max(g[i][j][0], g[i - 1][j - k - 1][0] + c + f[v][k][1]);

				g[i][j][1] = max(g[i][j][1], g[i - 1][j - k - 1][0] + c + f[v][k][1]);
				g[i][j][1] = max(g[i][j][1], g[i - 1][j - k][1] + f[v][k][0]);
				g[i][j][1] = max(g[i][j][1], g[i - 1][j - k][1] + f[v][k][1]);
			}
		}
	}
	for (int x = 0; x <= k; ++ k) {
		f[u][x][0] = g[p][x][0];
		f[u][x][1] = g[p][x][1];
	}
}

void calc(int root) {
	dfs(root, -1);
	res = max(res, f[root][k][0], f[root][k][1]);
}

int main() {
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i) {
			adj[i].clear();
		}
		for (int i = 1; i < n; ++ i) {
			int u, v, c;
			scanf("%d%d%d", &u, &v,  &c);
			res += c;
			adj[u].push_back(make_pair(v, c));
			adj[v].push_back(make_pair(u, c));
		}
		res = 0;
		for (int i = 1; i <= 1000; ++ i) {
			if (n <= 1000) calc(i);
			else calc(Rand(1, n));
		}
		printf("%d\n", res);
	}
}